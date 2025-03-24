package JuegoTarea;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.Action;
import javax.swing.Timer;

public class Physics implements ActionListener {

    Timer timer;
    
    GameManager gameManager;
    Long deltaTime;
    Main main;
    Bullet nexBullet;
    Enemy nextEnemy;
    


    public Physics(Timer timer , Main main , GameManager gameManager){
        this.timer = timer;
        this.main = main;
        this.gameManager = gameManager;
        deltaTime = 0l;
    }

    public void addBullets(Bullet bullet){
        gameManager.bullets.addLast(bullet);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        deltaTime++;

        Iterator<Bullet> bulletIterator = gameManager.bullets.iterator();
        while(bulletIterator.hasNext() && gameManager.flag){

            nexBullet = bulletIterator.next();
            nexBullet.moveTo(deltaTime);
            nexBullet.boxCollider.refresBoxCollider();
            if(deltaTime - nexBullet.createdTime > 300 ){
                bulletIterator.remove();
                main.remove(nexBullet);
            }
        }

        if(deltaTime%100 == 0 && gameManager.flag){
            if(gameManager.enemies.size() > 0)
            gameManager.enemies.getLast().followPlayer();
        }

        


        /* for(int i = 0 ; i< bullets.size() ; i++){
           bullets.get(i).moveTo(deltaTime);
           if(  deltaTime - bullets.get(i).createdTime > 10   ){
                bullets.get(i) = null
                bullets.remove(i);
           }

        } */
        main.repaint();
        main.requestFocus();

    }

    
    
}
