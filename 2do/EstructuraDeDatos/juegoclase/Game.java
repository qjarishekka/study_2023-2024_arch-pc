package juegoclase;
import javax.swing.*;
import java.awt.*;
import java.text.CollationElementIterator;

public class Game extends JFrame {
    
    Game(){
        super("worms");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(800,800);
        setLayout(null);


        //JLabel cannon = new JLabel(new ImageIcon("src\\cannon.jpg"));
        Image cannonImg  = new ImageIcon("src//cannon.jpg").getImage(); 
        JLabel cannon = new JLabel(new ImageIcon(cannonImg.getScaledInstance(100, 100,0 )));
        cannon.setBounds(0, getHeight()-200 , 100 , 100);
        add(cannon);



        JLabel aim = new JLabel(new ImageIcon("src//crosshair.png"));
        aim.setBounds(cannon.getX() + 100, cannon.getY() - 100 , 60 , 60  );
        add(aim);

        //JLabel bulletPic =  new JLabel(new ImageIcon("src//bullet.png"));
        Image bulletImg  = new ImageIcon("src//bullet.png").getImage(); 
        JLabel bulletPic = new JLabel(new ImageIcon(bulletImg.getScaledInstance(100, 100,DO_NOTHING_ON_CLOSE )));
        
        bulletPic.setBounds(100 , 100 ,100 ,100);

        Bullet bullet = new Bullet(bulletPic);
        
        JLabel power = new JLabel("");
        power.setBounds(10, getHeight()-500,10,50);
        power.setBackground(Color.green);
        power.setOpaque(true);
        add(power);

        Controls controls= new Controls(new Point(0,getHeight()) , aim, bullet   );
        addMouseMotionListener(controls);
        addMouseListener(controls);

        Physics physics = new Physics(17, bullet, power);
        Timer timer = new Timer(17 , physics);
        timer.start();
        
        setVisible(true);
        

    }

    public static void main(String[] args) {
        new Game();
    }

}
