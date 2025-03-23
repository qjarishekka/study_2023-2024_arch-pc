package JuegoTarea;

import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Enemy extends JLabel {
    
    Image enemyImage = new ImageIcon("src//alien.png").getImage();
    Main main;
    int lifePoints = 10;
    
    public Enemy(Main main){

        this.main = main;

        setIcon(    new ImageIcon( enemyImage.getScaledInstance( main.getWidth() * 5/100 , main.getWidth() * 5/100 , 0)  )     );
        setBounds(10,10,  getIcon().getIconWidth(), getIcon().getIconHeight());


    }



}
