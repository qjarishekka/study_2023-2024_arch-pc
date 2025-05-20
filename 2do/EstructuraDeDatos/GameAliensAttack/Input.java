package GameAliensAttack;

import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Input implements MouseListener,MouseMotionListener , KeyListener{

    static double horizontal= 0;
    static double vertical = 0;
    static Point cursor  = new Point(0,0);

    int a = 0;
    int d = 0;
    int w = 0;
    int s = 0;
    


    @Override
    public void keyPressed(KeyEvent e) {

        switch (e.getKeyChar()) {
            case 'a' :
                a = -1;
                    //player.moving(-1, 0);
                break;
            case 'd':
                d = 1;
                    //player.moving(1, 0);
                break;
            case 'w':
                w = -1;
                    //player.moving(0, -1);
                break;
            case 's':
                s = 1;
                    //player.moving(0, 1);
                break;
            case 27 : //escape  
   
                //mainFrame.gameOver();
                break;
        }
        refreshAxis();
    }

    @Override
    public void keyReleased(KeyEvent e) {

                switch (e.getKeyChar()) {
            case 'a' :

                a = 0;
                    //player.moving(-1, 0);
                break;
            case 'd':
                d = 0;
                    //player.moving(1, 0);
                break;
            case 'w':
                w = 0;
                    //player.moving(0, -1);
                break;
            case 's':
                s = 0;
                    //player.moving(0, 1);
                break;
            case 27 : //escape  
                   
            default:
                break;
        }
        refreshAxis();
       
    }

    @Override
    public void keyTyped(KeyEvent e) {
        
        switch (e.getKeyChar()) {
            case 'a' :

                a = -1;
                    //player.moving(-1, 0);
                break;
            case 'd':
                d = 1;
                    //player.moving(1, 0);
                break;
            case 'w':

                w = -1;
                    //player.moving(0, -1);
                break;
            case 's':
                s = 1;
                    //player.moving(0, 1);
                break;
            case 27 : //escape  
                //gameManager.stopPlaying();
                MainFrame.proxy.sceneManager.setScene("Pause");
                //System.out.println("pause");

            default:
                break;
        }

        refreshAxis();
       
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        cursor.setLocation(e.getX(), e.getY());
    }

    @Override
    public void mouseMoved(MouseEvent e) {

        cursor.setLocation(e.getX(), e.getY());
       
    }

    

    @Override
    public void mouseClicked(MouseEvent e) { }

    @Override
    public void mouseEntered(MouseEvent e) {}

    @Override
    public void mouseExited(MouseEvent e) {}

    @Override
    public void mousePressed(MouseEvent e) { }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    public void refreshAxis(){
        horizontal = a + d;
        vertical = w + s;

    }
    
}
