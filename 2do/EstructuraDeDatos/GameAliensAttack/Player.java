package GameAliensAttack;

import java.awt.image.BufferedImage;
import java.util.ArrayList;

import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;
import java.awt.geom.AffineTransform;


public class Player extends MonoBehavior{
    

    String path = "src//animations//playerAnimation";
    int playerSize = MainFrame.height*8/100;
    Animator animator = new Animator(path, this, playerSize);
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);

    double angle;
    int lifePoints = 3;
    
    double velocity = 4;


    public Player(){
        
        setIcon(new ImageIcon(animator.getIgame(0)));
        setBounds( MainFrame.width/2 - playerSize/2 , MainFrame.height/2 - playerSize/2 , playerSize,playerSize);
        animator.play();
        animator.setFPS(0.1);

    }

    public void moving (){
        
        rigidBody.setVelocity(Input.horizontal * velocity,Input.vertical * velocity);
        
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




    @Override
    public void update() {

        changeAngle();
        moving();
    

    }

    private void changeAngle(){
        int oppositeLeg = (int)(Input.cursor.getX() - getBounds().getCenterX());
        int adjacentLeg = (int)(getBounds().getCenterY() - Input.cursor.getY());
        angle = Math.atan2(oppositeLeg, adjacentLeg);
        //repaint();

    }




}
