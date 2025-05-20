package GameAliensAttack;

import javax.swing.ImageIcon;
import java.awt.Image;

public class Bullet extends MonoBehavior{

    Image bulletImage = new ImageIcon("src//bullet.png").getImage();
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);
    int size =  0 ;
    double dx = 0;
    double dy = 0;
    double angle = 0;


    public Bullet(){
        size = (int)(MainFrame.height*0.03);
        setBounds((int)Player.proxy.getBounds().getCenterX(), (int)Player.proxy.getBounds().getCenterY(), size, size );
        setIcon(new ImageIcon(bulletImage.getScaledInstance(size, size, 0)));
        angle = Player.proxy.angle;
        dx = Math.cos(angle);
        dy = Math.sin(angle);
        rigidBody.crashingPhysics = false;
    }

    public void move(){

        //rigidBody.setVelocity(dx, dy);

    }



    @Override
    public void update() {
        move();
    }
    
}
