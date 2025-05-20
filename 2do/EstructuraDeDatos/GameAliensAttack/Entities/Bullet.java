package GameAliensAttack.Entities;

import java.awt.Image;

import javax.swing.ImageIcon;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.*;

public class Bullet extends MonoBehavior{
    String path = "src//bullet.png";
    Image bulletImage = new ImageIcon(path).getImage();
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);
    int size = (int)(MainFrame.height*0.5);

    double angle = 0;
    double x = 0;
    double y = 0;
    double dx = 0;
    double dy = 0;
    public Bullet(){
        this.angle = Player.proxy.angle;
        x = Player.proxy.getBounds().getCenterX();
        y = Player.proxy.getBounds().getCenterY();
        dx = Math.cos(angle);
        dy = Math.sin(angle);
        setBounds((int)x , (int)y , size ,size);
        setIcon(new ImageIcon(bulletImage.getScaledInstance(size, size, 0)));
        rigidBody.crashingPhysics = false;
    }

    void move(){

        //rigidBody.setVelocity(dx, dy);

    }

    @Override
    public void update() {
        move();
    }
    


}
