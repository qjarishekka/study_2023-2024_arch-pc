package GameAliensAttack.Entities;

import javax.swing.ImageIcon;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Animator;
import GameAliensAttack.GameEngine.BoxCollider;
import GameAliensAttack.GameEngine.Input;
import GameAliensAttack.GameEngine.MonoBehavior;
import GameAliensAttack.GameEngine.RigidBody;
import GameAliensAttack.GameEngine.SceneManager;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;


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
    boolean canShoot = true;

    public int life = 5;

    public Player(){
        proxy = this;
        setIcon(new ImageIcon(animator.getIgame(0)));
        setBounds( MainFrame.width/2 - playerSize/2 , MainFrame.height/2 - playerSize/2 , playerSize,playerSize);
    
        animator.play();
        animator.setFPS(0.1);
        rigidBody.crashingPhysics = true;
        setTag("Player");

    }

    public void moving(){

        rigidBody.setVelocity(Input.getHorizontalAxis() * velocity,Input.getVerticalAxis() * velocity);
        
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



        if(Input.triggerMouseClick() && canShoot){
            Bullet bullet = new Bullet();
            SceneManager.addToSceneByTag(bullet, "Game");
            canShoot = false;
        }

        //System.out.println(Input.getCursorPosition());

        if(!Input.isMousePressed()){
            canShoot = true;
        }

        loosingLife();

    }

    private void changeAngle(){
        int oppositeLeg = (int)(Input.getCursorPosition().getX() - getBounds().getCenterX());
        int adjacentLeg = (int)(getBounds().getCenterY() - Input.getCursorPosition().getY());
        angle = Math.atan2(oppositeLeg, adjacentLeg);
    }

    private void loosingLife(){
        if(boxCollider.isCollidingByTag("Enemy")){
            life--;
            System.out.println(life);
        }
    }

}
