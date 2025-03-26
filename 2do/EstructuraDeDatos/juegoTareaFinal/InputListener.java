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
    double x = 0;
    double y = 0;
    int a = 0;
    int d = 0;
    int w = 0;
    int s = 0;

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
            double radius = 20;
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
        //player.repaint();

        //System.out.println("angulo " +  player.angle );

        
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        double radius = 20;
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

                a = -10;
                    //player.moving(-10, 0);
                break;
            case 'd':
                d = 10;
                    //player.moving(10, 0);
                break;
            case 'w':

                w = -10;
                    //player.moving(0, -10);
                break;
            case 's':
                s = 10;
                    //player.moving(0, 10);
                break;
            case 27 : //escape  
                gameManager.stopPlaying();
                mainFrame.gameOver();

            default:
                break;
        }

        refreshAxis();

        
    }

    @Override
    public void keyPressed(KeyEvent e) {

        switch (e.getKeyChar()) {
            case 'a' :
                a = -10;
                    //player.moving(-10, 0);
                break;
            case 'd':
                d = 10;
                    //player.moving(10, 0);
                break;
            case 'w':
                w = -10;
                    //player.moving(0, -10);
                break;
            case 's':
                s = 10;
                    //player.moving(0, 10);
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
                    //player.moving(-10, 0);
                break;
            case 'd':
                d = 0;
                    //player.moving(10, 0);
                break;
            case 'w':

                w = 0;

                    //player.moving(0, -10);
                break;
            case 's':

                s = 0;
                    //player.moving(0, 10);
                break;
            case 27 : //escape  

            default:
                break;
        }
        refreshAxis();
        
    }



    public void refreshAxis(){
        x = a + d;
        y = w + s;
        //double alfa = 1 + 0.5;
        //System.out.println(   alfa );
    }

    
}
