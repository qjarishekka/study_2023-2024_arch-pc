package JuegoTarea;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Rectangle;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;


public class Player extends JLabel{

    Image PlayerImage = new ImageIcon("src//animations//playerAnimation//player.png").getImage();
    Rectangle playerBounds = new Rectangle();
    double angle = 0;



    public Player(Main main){

        playerBounds.width = main.getWidth()*10/100;
        playerBounds.height = main.getHeight()*10/100;
        playerBounds.x = (main.getWidth() - (int)playerBounds.getWidth())  /2;
        playerBounds.y = (main.getHeight() - (int)playerBounds.getHeight())  /2;

        setIcon(new ImageIcon(PlayerImage.getScaledInstance((int)playerBounds.getWidth(),(int)playerBounds.getHeight(),0)));
        setBounds(playerBounds);
        
    }

    public void moving( int x , int y){
        setLocation(getX() +x , getY()+y);
    }

    public void shoot(){

    }

    @Override
    public void paint(Graphics g){
        Graphics2D g2 = (Graphics2D)g;
        AffineTransform at = g2.getTransform();
        at.rotate(angle,getWidth()/2,getHeight()/2);
        g2.setTransform(at);
        super.paint(g2);
    }



    
}
