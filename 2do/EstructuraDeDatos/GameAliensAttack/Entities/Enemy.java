package GameAliensAttack.Entities;

import javax.swing.ImageIcon;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Animator;
import GameAliensAttack.GameEngine.BoxCollider;
import GameAliensAttack.GameEngine.MonoBehavior;
import GameAliensAttack.GameEngine.RigidBody;

public class Enemy extends MonoBehavior {


    String path = "src//animations//enemyAnimation";
    int size = (int)(MainFrame.height*0.1);
    int velocity = 2;

    Animator animator = new Animator(path, this, size);
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);
    MonoBehavior targetedEntity = null;

    public Enemy(){
        setBounds(500,500 , size, size);
        setIcon(new ImageIcon(animator.getIgame(0).getScaledInstance(size, size, 0)) );
        animator.play();
        rigidBody.crashingPhysics = false;
        


    }
    public void setTargetedEntity(MonoBehavior target){
        targetedEntity = target;
    }

    private void followEntity(){

            if(targetedEntity != null){
            int dx = getX() - (int)targetedEntity.getX();
            int dy = getY() - (int)targetedEntity.getY();
            double angle = Math.atan2(dy, dx);
            double X = Math.cos(angle);
            double Y = Math.sin(angle);

            rigidBody.setVelocity(-X*velocity, -Y*velocity);

            }
            

    }
    

    @Override
    public void update() {
       followEntity();
       
    }
    
}
