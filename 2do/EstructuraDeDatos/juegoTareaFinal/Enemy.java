package juegoTareaFinal;

import java.awt.Image;
import java.awt.Point;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import java.util.Random;

public class Enemy extends JLabel {

    String path = "src//animations//enemyAnimation";

    Animator animator = new Animator(path);
    BoxCollider boxCollider = new BoxCollider(this); 

    int lifePoints = 5;
    int enemySize;
    double X0;
    double Y0;
    double vectorX;
    double vectorY;
    Random random = new Random();

    int velocity = 1;
    int mode = new Random().nextInt(2);
    public long createdTime;

    Field field;
    Player player;
    GameManager gameManager;
    


    public Enemy(int enemySize, long createdTime , GameManager gameManager){

        this.enemySize = enemySize;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(enemySize, enemySize, 0)));
        setBounds(10 ,10 , enemySize, enemySize);
        //vectorX = random.nextInt(20) - 10;
        //vectorY = random.nextInt(20) - 10;
        boxCollider.refresBoxCollider();
        this.gameManager = gameManager;
        this.createdTime = createdTime;
        this.field = gameManager.field;
        this.player = gameManager.player;

    }

    public Enemy(int enemySize, int x , int y , long createdTime){

        this.enemySize = enemySize;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(enemySize, enemySize, 0)));
        setBounds(x ,y , enemySize, enemySize);
        X0 = x;
        Y0 = y;   
        vectorX = random.nextInt(20) - 10;
        vectorY = random.nextInt(20) - 10;

        boxCollider.refresBoxCollider();
        this.createdTime = createdTime;
        
    }

    public void setXY(int i , int y){
        X0 = i;
        Y0 = y;
    }

    public void moveTo(Point target){

        int meteoriteSize = field.meteoritesField[0][0].meteoriteSize;

        vectorX = target.x* meteoriteSize- getX();
        vectorY = target.y* meteoriteSize - getY();

        X0 += vectorX *0.1;
        Y0 += vectorY * 0.1 ;
        setLocation((int)X0 , (int)Y0);
        boxCollider.refresBoxCollider();

    }

    public void nextFrame(){
        
        setIcon( new ImageIcon( animator.nextFrame().getScaledInstance(enemySize, enemySize, 0) ));
        //this.repaint();
        
    }

}
