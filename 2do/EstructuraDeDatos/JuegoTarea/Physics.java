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

        while(bulletIterator.hasNext()){
            nexBullet = bulletIterator.next();
            nexBullet.moveTo(deltaTime);
            if(deltaTime - nexBullet.createdTime > 300 ){
                
                
                main.remove(nexBullet);
            }
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
