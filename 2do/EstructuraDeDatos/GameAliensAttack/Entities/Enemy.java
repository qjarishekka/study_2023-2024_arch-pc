package GameAliensAttack.Entities;

import javax.swing.ImageIcon;

import GameAliensAttack.GameManager;
import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Animator;
import GameAliensAttack.GameEngine.BoxCollider;
import GameAliensAttack.GameEngine.GameEngine;
import GameAliensAttack.GameEngine.MonoBehavior;
import GameAliensAttack.GameEngine.RigidBody;
import GameAliensAttack.GameEngine.SceneManager;

public class Enemy extends MonoBehavior {

    String path = "src//animations//enemyAnimation";
    public static int size = (int)(MainFrame.height * 0.1);
    int velocity = 5;
    int life = 3;

    MonoBehavior targetedEntity = null;
    

    public Enemy() {
        // Crear animador temporal
        Animator tempAnimator = new Animator(path, this, size);

        // Usar imagen del animador para establecer ícono
        setBounds(500, 500, size, size);
        setIcon(new ImageIcon(tempAnimator.getIgame(0).getScaledInstance(size, size, 0)));

        // Asignar a los campos heredados (¡esto es lo importante!)
        this.animator = tempAnimator;
        this.boxCollider = new BoxCollider(this);
        this.rigidBody = new RigidBody(this.boxCollider);


        rigidBody.crashingPhysics = false;
        setTag("Enemy");
    }

    public void setTargetedEntity(MonoBehavior target) {
        targetedEntity = target;
    }

    private void followEntity() {
        if (targetedEntity != null) {
            int dx = getX() - (int)targetedEntity.getX();
            int dy = getY() - (int)targetedEntity.getY();
            double angle = Math.atan2(dy, dx);
            double X = Math.cos(angle);
            double Y = Math.sin(angle);

            rigidBody.setVelocity(-X * velocity, -Y * velocity);
        }
    }
    public void setLifePoints(int lifePoints){
        life = lifePoints;
    }

    @Override
    public void update() {
        followEntity();

        if (boxCollider.isCollidingByTag("Bullet")){
            life--;
            SceneManager.removeFromSceneByTag(boxCollider.objectHitted, "Game");

        }

        if (life <= 0) {
            SceneManager.removeFromSceneByTag(this, "Game");
            GameManager.score++;
        }

        if(boxCollider.isColliding(targetedEntity.boxCollider)  ){
            SceneManager.removeFromSceneByTag(this, "Game");

        }


    }
}

