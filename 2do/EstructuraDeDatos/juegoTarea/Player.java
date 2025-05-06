package juegoTarea;

import java.awt.image.BufferedImage;

import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;
import java.awt.geom.AffineTransform;


public class Player extends JLabel{
    
    String path = "src//animations//playerAnimation";

    Animator animator = new Animator(path);
    BoxCollider boxCollider = new BoxCollider(this);

    double angle;
    int lifePoints = 3;
    int playerSize;
    double velocity = 1;


    public Player(MainFrame main){
     

        playerSize = main.getHeight()*8/100;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(playerSize, playerSize, 0)));
        setBounds( main.getWidth()/2 - playerSize/2 , main.getHeight()/2 - playerSize/2 , playerSize,playerSize);


        //System.out.println("numero de frames " + animator.bufferedImage.length);

    }

    public void moving ( double x , double y ){
        
        setLocation( (int)( getX() + (x*velocity) ), (int)( getY()+ (y*velocity)  ));
        


        boxCollider.refresBoxCollider();
    }

    public void nextFrame(){
        setIcon( new ImageIcon( animator.nextFrame().getScaledInstance(playerSize, playerSize, 0) ));
        this.repaint();
    }


    @Override
    public void paint(Graphics g){
        Graphics2D g2 = (Graphics2D)g;
        AffineTransform at = g2.getTransform();
        at.rotate(angle,getWidth()/2,getHeight()/2);
        //System.out.println(angle);
        g2.setTransform(at);
        super.paint(g2);
    }




}
