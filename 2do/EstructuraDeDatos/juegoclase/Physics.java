package juegoclase;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
import java.awt.Color;
public class Physics implements ActionListener{


    static Physics proxy;
    public static double GRAVITY = 100f;
    Bullet bullet;
    int delay;

    double MAXpower = 2;
    double power = 0;
    boolean shooting; 
    JLabel powerLabel;

    Physics(int delay, Bullet bullet , JLabel powerLabel){
        this.delay = delay;
        this.bullet = bullet;
        this.powerLabel = powerLabel;
        proxy = this;


    }

    void startShooting(){
        power = 0;
        shooting = true;

    }

    void stopShooting(){
        shooting = false;
        power = 0;
    }





    @Override
    public void actionPerformed(ActionEvent e) {

        if(shooting)
            power = Math.min(power +0.1 , MAXpower );
        
        bullet.move(delay * 0.001);
        double p = power / MAXpower;
        powerLabel.setBackground(new Color(  (int)(p*255)  , (int)(p*255)   ,   0)   );
        powerLabel.setSize((int)(100*p), 300);
    
    }
}
