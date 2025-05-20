package GameAliensAttack.Entities;

import javax.swing.ImageIcon;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Animator;
import GameAliensAttack.GameEngine.BoxCollider;
import GameAliensAttack.GameEngine.Input;
import GameAliensAttack.GameEngine.MonoBehavior;
import GameAliensAttack.GameEngine.RigidBody;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import GameAliensAttack.GameEngine.Input;


public class Player extends MonoBehavior{
    static public Player proxy;

    String path = "src//animations//playerAnimation";
    int playerSize = MainFrame.height*8/100;
    Animator animator = new Animator(path, this, playerSize);
    BoxCollider boxCollider = new BoxCollider(this);
    RigidBody rigidBody = new RigidBody(boxCollider);

    double angle;
    int lifePoints = 3;
    
    double velocity = 4;


    public Player(){
        proxy = this;
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
        g2.setTransform(at);
        super.paint(g2);
    }

    @Override
    public void update() {
        changeAngle();
        moving();

        if(Input.trigger()){
            Bullet bullet = new Bullet();
            //MainFrame.proxy.sceneManager.gamePanel.add(bullet);
            System.out.println("presionado");

        }

    }

    private void changeAngle(){
        int oppositeLeg = (int)(Input.cursor.getX() - getBounds().getCenterX());
        int adjacentLeg = (int)(getBounds().getCenterY() - Input.cursor.getY());
        angle = Math.atan2(oppositeLeg, adjacentLeg);
    }

}
