package juegoTareaFinal;

import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import java.util.Random;

public class Enemy extends JLabel {

    String path = "src\\animations\\enemyAnimation";

    Animator animator = new Animator(path);
    BoxCollider boxCollider = new BoxCollider(this); 

    int lifePoints = 5;
    int enemySize;
    double X0;
    double Y0;
    double vectorX;
    double vectorY;
    int mode = new Random().nextInt(2);
    


    public Enemy(int enemySize){

        this.enemySize = enemySize;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(enemySize, enemySize, 0)));
        setBounds(10 ,10 , enemySize, enemySize);
        X0 = 10;
        Y0 = 10;
        boxCollider.refresBoxCollider();
 

    

    }

    public Enemy(int enemySize, int x , int y){

        this.enemySize = enemySize;
        setIcon(new ImageIcon(animator.bufferedImage[0].getScaledInstance(enemySize, enemySize, 0)));
        setBounds(x ,y , enemySize, enemySize);
        X0 = x;
        Y0 = y;   
        boxCollider.refresBoxCollider();
        
    }

    public void moveTo(){

        X0 += vectorX;
        Y0 += vectorY;
        setLocation((int)X0 , (int)Y0);
        boxCollider.refresBoxCollider();

    }











}
