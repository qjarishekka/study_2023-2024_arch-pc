package JuegoTarea;

import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Enemy extends JLabel {
    
    Image enemyImage = new ImageIcon("src//alien.png").getImage();
    Main main;
    int lifePoints = 5;
    public BoxCollider boxCollider;

    
    
    public Enemy(Main main){

        this.main = main;

        setIcon(    new ImageIcon( enemyImage.getScaledInstance( main.getWidth() * 5/100 , main.getWidth() * 5/100 , 0)  )     );
        setBounds(100,100,  getIcon().getIconWidth(), getIcon().getIconHeight());

        boxCollider = new BoxCollider(this);


    }

    public Enemy(Main main , int x , int y){

        this.main = main;

        setIcon(    new ImageIcon( enemyImage.getScaledInstance( main.getWidth() * 5/100 , main.getWidth() * 5/100 , 0)  )     );
        setBounds(x,y,  getIcon().getIconWidth(), getIcon().getIconHeight());

        boxCollider = new BoxCollider(this);


    }

    public void followPlayer(){
        /* double radius = 10;
        int dx = e.getX() - (int)player.getBounds().getCenterX();
        int dy = e.getY() - (int)player.getBounds().getCenterY();
        double d = Math.sqrt(dx*dx + dy*dy);
        double r = radius/d; */

        double radius = 10;
        int dx = (int)(main.player.getBounds().getCenterX() - getBounds().getCenterX());
        int dy = (int)(main.player.getBounds().getCenterY() - getBounds().getCenterY() );
        double d = Math.sqrt(dx * dx + dy*dy);
        double r = radius/d;

        setLocation(    (int)(getBounds().getCenterX() + dx*r) , (int)(getBounds().getCenterY() + dy*r));
        boxCollider.refresBoxCollider();

    }



}
