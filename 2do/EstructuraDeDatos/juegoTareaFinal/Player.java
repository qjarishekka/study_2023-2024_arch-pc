package juegoTareaFinal;

import java.awt.image.BufferedImage;

import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.geom.AffineTransform;


public class Player extends JLabel{
    
    String path = "src//animations//playerAnimation";

    Animator animator = new Animator(path);
    BoxCollider boxCollider = new BoxCollider(this);

    double angle;
    int lifePoints = 3;
    int playerSize;


    public Player(MainFrame main){

        playerSize = main.getHeight()*10/100;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(playerSize, playerSize, 0)));
        setBounds( main.getWidth()/2 - playerSize/2 , main.getHeight()/2 - playerSize/2 , playerSize,playerSize);


        System.out.println("numero de frames " + animator.bufferedImage.length);

    }

    public void moving ( int x , int y ){
        setLocation(getX() + x,getY()+ y);
        boxCollider.refresBoxCollider();
    }

    public void nextFrame(){
        setIcon( new ImageIcon( animator.nextFrame().getScaledInstance(playerSize, playerSize, 0) ));
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
