package JuegoTarea;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.text.JTextComponent.KeyBinding;

import javax.swing.JLabel;
import javax.swing.KeyStroke;

public class InputListener extends KeyBinding implements MouseListener, MouseMotionListener {

    public InputListener(KeyStroke key, String actionName) {
        super(key, actionName);
        //TODO Auto-generated constructor stub
    }

    Player player;




    
    @Override
    public void mouseReleased(MouseEvent e) { }

    @Override
    public void mouseDragged(MouseEvent e) { }

    @Override
    public void mouseEntered(MouseEvent e) { }

    @Override
    public void mouseExited(MouseEvent e) { }




    //////////////////////////////////////////////
    @Override
    public void mouseMoved(MouseEvent e) {
        
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        
    }

    @Override
    public void mousePressed(MouseEvent e) {
        
    }



    


}
