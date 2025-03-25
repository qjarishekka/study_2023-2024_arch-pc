package juegoTareaFinal;

import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Bullet extends JLabel {

    Image bulletImage = new ImageIcon("src//bullet.png").getImage();
    BoxCollider boxCollider = new BoxCollider(this);

    double X0 = 0;
    double Y0 = 0;
    double vectorX = 0;
    double vectorY = 0; 
    int bulletSize = 0;   

    public Long createdTime;

    public Bullet( int x, int y   , double vectorX, double vectorY , int bulletSize , Long createdTime){

        this.vectorX = vectorX;
        this.vectorY = vectorY;
        this.bulletSize = bulletSize;

        setIcon(new ImageIcon(bulletImage.getScaledInstance(bulletSize, bulletSize, 0)));
        setBounds(x , y , bulletSize, bulletSize);
        X0 = x;
        Y0 = y;

        this.createdTime = createdTime;
        

    }

    public void moveTo(){
        X0 = X0 + vectorX;
        Y0 = Y0 +  vectorY;
        setLocation((int)X0 , (int)Y0);
        boxCollider.refresBoxCollider();
    }



    
}
