package juegoclase;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import javax.swing.Icon;
import javax.swing.JLabel;



public class RotImage extends JLabel {

    double angle =  0;  //Math.PI/4;
    RotImage(Icon image){
        super(image);
    }
    
    @Override
    public void paint(Graphics g){
        Graphics2D g2 = (Graphics2D)g;
        AffineTransform at = g2.getTransform();
        at.rotate(angle,getWidth()/2,getHeight()/2);
        g2.setTransform(at);
        super.paint(g2);
    }
   
    
}
