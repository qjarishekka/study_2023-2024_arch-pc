package juegoclase;

import java.awt.Graphics;
import java.awt.geom.AffineTransform;
import javax.swing.Icon;
import javax.swing.JLabel;
public class RotImage extends JLabel {

    double angle = Math.PI/4;
    RotImage(Icon image){
        super(image);
    }
    
    @Override
    public void paint(Graphics g){
        Graphics2d g2 = (Graphics2d)g;

    }
    
    
}
