package JuegoTarea;

import java.awt.Image;
import java.awt.Point;
import java.awt.Rectangle;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Player extends JLabel{

    Image PlayerImage = new ImageIcon("src//animations//playerAnimation//player.png").getImage();
    Rectangle playerBounds = new Rectangle();


    public Player(Main main){

       



        playerBounds.width = main.getWidth()*10/100;
        playerBounds.height = main.getHeight()*10/100;
        playerBounds.x = (main.getWidth() - (int)playerBounds.getWidth())  /2;
        playerBounds.y = (main.getHeight() - (int)playerBounds.getHeight())  /2;

        setIcon(new ImageIcon(PlayerImage.getScaledInstance((int)playerBounds.getWidth(),(int)playerBounds.getHeight(),0)));
        setBounds(playerBounds);
        
    }

    public void moving( int x , int y){
        setLocation(getX() +x , getY()+y);
    }

    public void shoot(){

    }

    public void rotate(double angle){

    }



    
}
