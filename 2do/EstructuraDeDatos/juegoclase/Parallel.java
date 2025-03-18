package juegoclase;

import java.lang.Runnable;


public class Parallel implements Runnable{

    public RotImage pic;
    public AnImage animation;
    public Parallel(RotImage pic){
        this.pic = pic;
    }

    @Override
    public void run(){
        while(true){
            pic.angle+= Math.PI / 120;
            animation.frameID = (animation.frameID+1)%animation.images.length;
            pic.repaint();
            try {
                Thread.sleep(32);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}

