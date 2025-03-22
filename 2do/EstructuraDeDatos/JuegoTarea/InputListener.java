package JuegoTarea;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.Component;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.text.JTextComponent.KeyBinding;
import java.awt.event.KeyEvent;

import javax.swing.JLabel;
import javax.swing.KeyStroke;

public class InputListener implements MouseListener, MouseMotionListener, KeyListener {

    
    Player player;
    Main proxy;



    public InputListener(Player player, Main proxy){
        this.player = player;
        this.proxy = proxy;
   

    }




    
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

        int oppositeLeg = (int)(e.getX() - player.getBounds().getCenterX());
        int adjacentLeg = (int)(  player.getBounds().getCenterY( )  - e.getY());

        player.angle = Math.atan2(oppositeLeg, adjacentLeg);
        //System.out.println(player.angle);
        player.repaint();

        
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
        switch (e.getKeyChar()) {
            case 'a':
                    player.moving(-10, 0);
                break;
            case 'd':
                    player.moving(10, 0);
                break;
            case 'w':
                    player.moving(0, -10);
                break;
            case 's':
                    player.moving(0, 10);
                break;
        
            default:
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }



    


}
