package juegoTareaFinal;

import java.awt.Image;
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
    


    public Enemy(int enemySize, long createdTime){

        this.enemySize = enemySize;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(enemySize, enemySize, 0)));
        setBounds(10 ,10 , enemySize, enemySize);
        X0 = 10;
        Y0 = 10;
        boxCollider.refresBoxCollider();
        this.createdTime = createdTime;
 

    

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

    public void moveTo(){

        X0 += vectorX;
        Y0 += vectorY;
        setLocation((int)X0 , (int)Y0);
        boxCollider.refresBoxCollider();

    }

    public void nextFrame(){
        
        setIcon( new ImageIcon( animator.nextFrame().getScaledInstance(enemySize, enemySize, 0) ));
        //this.repaint();
        
    }











}
