package GameAliensAttack;

import javax.swing.ImageIcon;

public class Enemy extends MonoBehavior {


    String path = "src//animations//enemyAnimation";
    int size = (int)(MainFrame.height*0.1);


    Animator animator = new Animator(path, this, size);
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);

    public Enemy(){
        setBounds(500,500 , size, size);
        setIcon(new ImageIcon(animator.getIgame(0).getScaledInstance(size, size, 0)) );
        animator.play();

    }



    @Override
    public void update() {
       
    }
    
}
