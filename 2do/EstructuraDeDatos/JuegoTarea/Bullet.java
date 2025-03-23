package JuegoTarea;

import java.awt.Image;


import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Bullet extends JLabel{
    
    Image bulletImage = new ImageIcon("src//bullet.png").getImage();
    Main main;
    Physics physics;
    Player player;
    long createdTime;
    double X0= 0;
    double Y0 = 0;
    double vectorX = 0;
    double vectorY = 0;


    


    public Bullet(Main main ,Physics physics, Player player, double vx , double vy){
        this.main = main;
        this.physics = physics;
        this.player = player;
        vectorX = vx;
        vectorY = vy;



        

        setIcon(new ImageIcon(bulletImage.getScaledInstance(main.getWidth()*1/300,main.getHeight()*2/300,0)));
        setBounds(  (int)player.getBounds().getCenterX() , (int)player.getBounds().getCenterY(), getIcon().getIconWidth() , getIcon().getIconHeight());
        physics.addBullets(this);
        createdTime = physics.deltaTime;

        X0 = player.getBounds().getCenterX();
        Y0 = player.getBounds().getCenterY();
        
    }


    public void moveTo( long deltaTime){
        
        X0 += vectorX;
        Y0 += vectorY;

        setLocation((int)X0, (int)Y0);


    }
    
}
