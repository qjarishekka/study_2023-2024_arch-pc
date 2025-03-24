package juegoTareaFinal;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class InputListener implements MouseListener,MouseMotionListener , KeyListener {

    MainFrame mainFrame;
    GameManager gameManager;
    Player player;
    boolean canShoot = true;

    public InputListener(MainFrame mainFrame){

        System.out.println("inicio de InputListener " );

        this.mainFrame = mainFrame;
        this.gameManager = mainFrame.gameManager;
        this.player = mainFrame.gameManager.player;
        //System.out.println("final de InputListener " );
    }


    @Override
    public void mouseDragged(MouseEvent e) {
        
        int oppositeLeg = (int)(e.getX() - player.getBounds().getCenterX());
        int adjacentLeg = (int)(player.getBounds().getCenterY() - e.getY());
        player.angle = Math.atan2(oppositeLeg, adjacentLeg);
        player.repaint(); // por si aca dejo esto aqui;

        if(canShoot){
            double radius = 10;
            int dx = e.getX() - (int)player.getBounds().getCenterX();
            int dy = e.getY() - (int)player.getBounds().getCenterY();
            double d = Math.sqrt(dx*dx + dy*dy);
            double r = radius/d;

            gameManager.addBullet(dx*r, dy*r);
            canShoot = false;

        }



    }

    @Override
    public void mouseMoved(MouseEvent e) {

        int oppositeLeg = (int)(e.getX() - player.getBounds().getCenterX());
        int adjacentLeg = (int)(player.getBounds().getCenterY() - e.getY());
        player.angle = Math.atan2(oppositeLeg, adjacentLeg);
        player.repaint();

        //System.out.println("angulo " +  player.angle );

        
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        double radius = 10;
            int dx = e.getX() - (int)player.getBounds().getCenterX();
            int dy = e.getY() - (int)player.getBounds().getCenterY();
            double d = Math.sqrt(dx*dx + dy*dy);
            double r = radius/d;


            gameManager.addBullet(dx*r, dy*r);
            canShoot = false;
    }

    @Override
    public void mousePressed(MouseEvent e) {
        
    }

    @Override
    public void mouseReleased(MouseEvent e) {
       canShoot = true;
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        
    }

    @Override
    public void mouseExited(MouseEvent e) {
        
    }



    @Override
    public void keyTyped(KeyEvent e) {

        switch (e.getKeyChar()) {
            case 'a' :
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
            case 27 : //escape
  
            default:
                break;
        }
        
    }

    @Override
    public void keyPressed(KeyEvent e) {

        switch (e.getKeyChar()) {
            case 'a' :
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
            case 27 : //escape
  
            default:
                break;
        }
        
    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }



    
}
