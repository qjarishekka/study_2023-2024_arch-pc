package juegoclase;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
public class Physics implements ActionListener{

    static Physics proxy;
    public static double GRAVITY = 100f;
    Bullet bullet;
    int delay;

    double MAXpower = 2;
    double power = 0;
    boolean shooting; 
    JLabel powerLabel;

    Physics(int delay, Bullet bullet , JLabel powerlabel){
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
       

    }

    
    


}
