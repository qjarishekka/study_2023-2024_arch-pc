package clases;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JLabel;

public class KeyBoard implements KeyListener {

    JLabel pic;

    KeyBoard(JLabel pic){
        this.pic = pic;
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

        switch (e.getKeyChar()) {
            case 'S':
                pic.setLocation(pic.getX(),pic.getY()+5);
                break;
            case 's':
                pic.setLocation(pic.getX(),pic.getY()+15);
        
            default:
                break;
        }
            
    }

    @Override
    public void keyReleased(KeyEvent e) {
      
    }
    
}
