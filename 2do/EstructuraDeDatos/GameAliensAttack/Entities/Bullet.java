package GameAliensAttack.Entities;

import java.awt.Image;
import java.time.Duration;
import java.time.Instant;

import javax.swing.ImageIcon;

import GameAliensAttack.GameManager;
import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.*;

public class Bullet extends MonoBehavior {
    String path = "src//bullet.png";
    Image bulletImage = new ImageIcon(path).getImage();
    int size = (int)(MainFrame.height*0.05);
    static int counter = 0;
    int Name = 0;

    double angle = 0;
    double x = 0;
    double y = 0;
    double dx = 0;
    double dy = 0;
    double r = 0;
    double chronometer = 0;
    Instant time0 = Instant.now(); 
    int velocity = 20;

    public Bullet() {
        x = Player.proxy.getBounds().getCenterX() - size/2;
        y = Player.proxy.getBounds().getCenterY() - size/2;
        double radius = 1;
        dx = Input.getCursorPosition().getX() - Player.proxy.getBounds().getCenterX();
        dy = Input.getCursorPosition().getY() - Player.proxy.getBounds().getCenterY();

        double d = Math.sqrt(dx*dx + dy*dy);
        r = radius / d;

        setBounds((int)x , (int)y , size , size);
        setIcon(new ImageIcon(bulletImage.getScaledInstance(size, size, 0)));
        setTag("Bullet");

        this.boxCollider = new BoxCollider(this);

        //this.rigidBody = new RigidBody(this.boxCollider);
    }

    void move() {
        x = x + (dx * r * velocity);
        y = y + (dy * r * velocity);
        setLocation((int)x, (int)y);
    }

    void autoKill() {
        chronometer = Duration.between(time0, Instant.now()).getNano()/1e9;
        if (chronometer >= 0.5) {
            SceneManager.removeFromSceneByTag(this, "Game");
            //System.out.println(MonoBehavior.toRemoveBuffer.size());
        }
    }



    @Override
    public void update() {
        move();
        autoKill();
    }
}
