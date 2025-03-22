package JuegoTarea;

import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Bullet extends JLabel{
    
    Image bulletImage = new ImageIcon("src//bullet.png").getImage();
    Main main;

    public Bullet(Main main){
        this.main = main;

        setIcon(new ImageIcon(bulletImage.getScaledInstance(main.getWidth()*1/300,main.getHeight()*2/300,0)));
        setBounds(10,10, getIcon().getIconWidth() , getIcon().getIconHeight()  );
        
    }


    
}
