package JuegoTarea;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JLabel;

public class Controls implements MouseListener, MouseMotionListener, KeyListener {

    Player player;



    public Controls(Player player){

        this.player = player;
    }

    @Override
    public void mouseReleased(MouseEvent e) { }

    @Override
    public void mouseDragged(MouseEvent e) { }

    @Override
    public void mouseEntered(MouseEvent e) { }

    @Override
    public void mouseExited(MouseEvent e) { }

    @Override
    public void keyReleased(KeyEvent e) { }


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

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    
    


}
