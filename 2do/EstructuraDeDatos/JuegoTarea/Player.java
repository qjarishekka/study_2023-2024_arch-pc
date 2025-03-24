package JuegoTarea;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Rectangle;

import javax.imageio.ImageIO;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class Player extends JLabel{

    String path = "src//animations//playerAnimation";

    Image PlayerImage = new ImageIcon("src//animations//playerAnimation//player_1frame.png").getImage();
    Rectangle playerBounds = new Rectangle();
    double angle = 0;
    BoxCollider boxCollider;
    int lifePoints = 3;

    BufferedImage bufferedImage[];
    int imageID = 0;





    public Player(Main main){

        playerBounds.width = main.getWidth()*10/100;
        playerBounds.height = main.getHeight()*10/100;
        playerBounds.x = (main.getWidth() - (int)playerBounds.getWidth())  /2;
        playerBounds.y = (main.getHeight() - (int)playerBounds.getHeight())  /2;

        setIcon(new ImageIcon(PlayerImage.getScaledInstance((int)playerBounds.getWidth(),(int)playerBounds.getHeight(),0)));
        setBounds(playerBounds);

        boxCollider = new BoxCollider(this);

        File dir = new File(path);
        File[] files = dir.listFiles();
        bufferedImage = new BufferedImage[files.length];
        for(int i = 0; i < files.length ; i++){ //
            try{
                bufferedImage[i] = ImageIO.read(files[i]);
            }catch(IOException e){}
        }
        
    }

    public void moving( int x , int y){
        setLocation(getX() +x , getY()+y);
        boxCollider.refresBoxCollider();
    }

    public void shoot(){
        
    }

    public void ChangeFrame(){
        setIcon(  new ImageIcon(bufferedImage[imageID].getScaledInstance((int)playerBounds.getWidth(), (int)playerBounds.getHeight(), 0)  )  );
        if(imageID < 2){
            imageID++;
        }else   
            imageID = 0;
    }


    @Override
    public void paint(Graphics g){


        //g.drawImage(animations.playerAnimation[2], NEXT, ABORT, labelFor);
        //g = animations.playerAnimation[1].getGraphics();
       
        Graphics2D g2 = (Graphics2D)g;

        AffineTransform at = g2.getTransform();
        at.rotate(angle,getWidth()/2,getHeight()/2);
        g2.setTransform(at);
        super.paint(g2);
        
    }



    
}
