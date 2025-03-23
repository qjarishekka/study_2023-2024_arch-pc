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
    Physics physics;

    boolean canShoot = true;

    




    public InputListener(Player player, Main proxy , Physics physics){
        this.player = player;
        this.proxy = proxy;
        this.physics = physics;
   

    }




    
    @Override
    public void mouseReleased(MouseEvent e) { 

        canShoot = true;
    }

    @Override
    public void mouseDragged(MouseEvent e) { 

        int oppositeLeg = (int)(e.getX() - player.getBounds().getCenterX());
        int adjacentLeg = (int)(  player.getBounds().getCenterY( )  - e.getY());
        player.angle = Math.atan2(oppositeLeg, adjacentLeg);
        player.repaint();

        if(canShoot){
            double radius = 10;
            int dx = e.getX() - (int)player.getBounds().getCenterX();
            int dy = e.getY() - (int)player.getBounds().getCenterY();
            double d = Math.sqrt(dx*dx + dy*dy);
            double r = radius/d;

            Bullet bullet = new Bullet(proxy,physics,player, dx*r, dy*r );
            proxy.add(bullet, 0);    
            canShoot = false;
        }
        



        //System.out.println("balla aniadida");
        proxy.repaint();
        

    }

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
        player.repaint();

        
    }

    @Override
    public void mouseClicked(MouseEvent e) {

        

        double radius = 10;
        int dx = e.getX() - (int)player.getBounds().getCenterX();
        int dy = e.getY() - (int)player.getBounds().getCenterY();
        double d = Math.sqrt(dx*dx + dy*dy);
        double r = radius/d;

        Bullet bullet = new Bullet(proxy,physics,player, dx*r, dy*r );
        proxy.add(bullet, 0);



        //System.out.println("balla aniadida");
        proxy.repaint();
        
    }

    @Override
    public void mousePressed(MouseEvent e) {
        
    }

    @Override
    public void keyTyped(KeyEvent e) {
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
