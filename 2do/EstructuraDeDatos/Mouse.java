import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JLabel;

public class Mouse implements MouseListener {

    JLabel pic;

    Mouse(JLabel p){
        pic = p;
    }

    @Override
    public void mouseClicked(MouseEvent e) { }

    @Override
    public void mousePressed(MouseEvent e) {
        System.out.println(e.getButton() + " " + e.getX() + " " + e.getXOnScreen());
     }

    @Override
    public void mouseReleased(MouseEvent e) { }

    @Override
    public void mouseEntered(MouseEvent e) { 
        pic.setVisible(true);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        pic.setVisible(false);
     }
    
}
