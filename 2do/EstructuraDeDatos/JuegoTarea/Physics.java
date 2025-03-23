package JuegoTarea;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.Action;
import javax.swing.Timer;

public class Physics implements ActionListener {

    Timer timer;
    ArrayList <Bullet> bullets = new ArrayList<>();
    Long deltaTime;
    Main main;


    public Physics(Timer timer , Main main){
        this.timer = timer;
        this.main = main;
        deltaTime = 0l;
    }

    public void addBullets(Bullet bullet){
        this.bullets.addLast(bullet);
        
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        deltaTime++;

        for(int i = 0 ; i< bullets.size() ; i++){
           bullets.get(i).moveTo(deltaTime);

        }
        
        main.requestFocus();

    }

    
    
}
