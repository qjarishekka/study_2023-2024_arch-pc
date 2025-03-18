package juegoclase;

import java.lang.Runnable;


public class Parallel implements Runnable{

    public RotImage pic;
    public Parallel(RotImage pic){
        this.pic = pic;
    }

    @Override
    public void run(){
        while(true){
            pic.angle+= Math.PI / 120;
            pic.repaint();
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}

