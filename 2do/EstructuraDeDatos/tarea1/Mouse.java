package tarea1;

import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.geom.Dimension2D;
import java.util.Random;

import javax.swing.JLabel;

public class Mouse implements MouseMotionListener {

    JLabel pic;
 
    

    Mouse(JLabel p){
        pic = p;
        
    }


    @Override
    public void mouseDragged(MouseEvent e) {
        
    }


    @Override
    public void mouseMoved(MouseEvent e) {


        int imgX = pic.getX();  //38 61 -61 -1
        int imgY = pic.getY();
        int imgXX = imgX + (int)(pic.getSize().getWidth());
        int imgYY = imgY + (int)(pic.getSize().getHeight());
        Random aleatorio = new Random(System.currentTimeMillis());
        int rand1 = aleatorio.nextInt(520);
        int rand2 = aleatorio.nextInt(520);
        

        //38 22 61 1

        if(imgX < e.getX() && e.getX() < imgXX && imgY < e.getY() && e.getY() < imgYY ){

            pic.setLocation(rand1,rand2);
        }

        //System.out.println(imgX + " " + imgXX + " " + imgY + " " +imgYY +" mouse: " + e.getX() + " " + e.getY());



        /* Dimension2D size = pic.getSize();
        int X = pic.getX();
        int Y = pic.getY();

        if( X < e.getX() && e.getX() < (int)size.getWidth()+X && Y < e.getY() && e.getY() < (int)size.getHeight()+Y  ){
            pic.setLocation(0 , 0);
        }

        System.out.println(e.getX() + " " + e.getY());
         */
    }

    
    

    
    
}
