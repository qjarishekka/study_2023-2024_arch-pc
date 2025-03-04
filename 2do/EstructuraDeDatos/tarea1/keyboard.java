package tarea1;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JLabel;

public class keyboard implements KeyListener {

    JLabel pic;

    keyboard(JLabel pic){
        this.pic = pic;
    }

    @Override
    public void keyTyped(KeyEvent e) {

        
       
    }

    @Override
    public void keyPressed(KeyEvent e) {
        
        if(e.getKeyChar() == 'a'){
            pic.setLocation(pic.getX()-5,pic.getY());
        }

        if(e.getKeyChar() == 's'){
            pic.setLocation(pic.getX(),pic.getY()+5);
        }

        if(e.getKeyChar() == 'd'){
            pic.setLocation(pic.getX()+5,pic.getY());
        }

        if(e.getKeyChar() == 'w'){
            pic.setLocation(pic.getX(),pic.getY()-5);
        }

    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }
    
}
