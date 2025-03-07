package juegoclase;

import java.awt.event.MouseMotionListener;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JLabel;


public class Controls implements MouseMotionListener , MouseListener {

    JLabel aim;
    Bullet bullet;
    Point LB;

    Controls(Point LB, JLabel aim, Bullet bullet){
        this.LB = LB;
        this.aim = aim;
        this.bullet = bullet;
    }


    @Override
    public void mouseClicked(MouseEvent e) {
       
    }

    @Override
    public void mousePressed(MouseEvent e) {
        Physics.proxy.startShooting();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        double radius = 200;
        int dx = e.getX() - LB.x;
        int dy = e.getY() - LB.y;
        double d= Math.sqrt(dx* dx + dy*dy);
        double r = radius/ d * Physics.proxy.power;

        bullet.setLocation(LB.x, LB.y - 100);
        bullet.shoot(dx*r, dy*r);
        Physics.proxy.stopShooting();
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        
    }

    @Override
    public void mouseExited(MouseEvent e) {
        
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        double radius = 400;
        int dx = e.getX() - LB.x;
        int dy = e.getY() - LB.y;
        double d = Math.sqrt(dx * dx + dy *dy);
        double r = radius / d;
        int ax = (int)(dx*r);
        int ay= (int)(dy*r);

        aim.setLocation(LB.x +ax -30 , LB.y+ay - 30);
    }




    
}
