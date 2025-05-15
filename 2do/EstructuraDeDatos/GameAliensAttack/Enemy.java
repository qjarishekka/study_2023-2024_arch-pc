package GameAliensAttack;

import java.awt.Component;
import java.util.concurrent.CompletionStage;

import javax.swing.ImageIcon;

public class Enemy extends MonoBehavior {


    String path = "src//animations//enemyAnimation";
    int size = (int)(MainFrame.height*0.1);


    Animator animator = new Animator(path, this, size);
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);
    MonoBehavior targetedEntity = null;

    public Enemy(){
        setBounds(500,500 , size, size);
        setIcon(new ImageIcon(animator.getIgame(0).getScaledInstance(size, size, 0)) );
        animator.play();
        


    }
    public void setTargetedEntity(MonoBehavior target){
        targetedEntity = target;
    }

    private void followEntity(){

            if(targetedEntity != null){
            double radius = 10;
            int dx = getX() - (int)targetedEntity.getX();
            int dy = getY() - (int)targetedEntity.getY();
            double d = Math.sqrt(dx*dx + dy*dy);
            double r = radius/d;
            rigidBody.setVelocity(-dx*r*0.01, -dy*r*0.01);
            
            /* int dx = getX() - (int)targetedEntity.getX();
            int dy = getY() - (int)targetedEntity.getY();
            rigidBody.setVelocity(-dx*0.01, -dy*0.01); */
            }
            

    }




    @Override
    public void update() {
       followEntity();
    }
    
}
