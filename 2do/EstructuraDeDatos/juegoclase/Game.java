package juegoclase;
import javax.swing.*;
import java.awt.*;
import java.text.CollationElementIterator;

public class Game extends JFrame {

    RotImage cannon,aim,bulletPic,back;
    
    Game(){
        
        super("worms");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(800,800);
        setLayout(null);


        //image:

        //Image cannonImg  = new ImageIcon("src//cannon.jpg").getImage();
        Image aimImg  = new ImageIcon("src//crosshair.png").getImage();
        Image bulletImg  = new ImageIcon("src//bullet.png").getImage();
        Image backgroundImg = new ImageIcon("src//windows.png").getImage();

        //Image cannonImg  = new ImageIcon("2do\\EstructuraDeDatos\\juegoclase\\src\\cannon.jpg").getImage();
        /* Image aimImg  = new ImageIcon("2do\\EstructuraDeDatos\\juegoclase\\src\\crosshair.png").getImage();
        Image bulletImg  = new ImageIcon("2do\\EstructuraDeDatos\\juegoclase\\src\\bullet.png").getImage();
        Image backgroundImg = new ImageIcon("2do\\EstructuraDeDatos\\juegoclase\\src\\windows.png").getImage(); */

        
        //cannon = new RotImage(new ImageIcon(cannonImg.getScaledInstance(100, 100,0 )));
        //AnImage cannon = new AnImage("2do\\EstructuraDeDatos\\juegoclase\\src\\animation");

        AnImage cannon = new AnImage("src//animation");
        cannon.setBounds(0, getHeight()-100 , 100 , 100);
        add(cannon);
         
        aim = new RotImage(new ImageIcon(aimImg.getScaledInstance(100, 100,0 )));
        aim.setBounds(cannon.getX() + 50, cannon.getY() - 50 , 60 , 60  );
        add(aim);

        
         
        bulletPic = new RotImage(new ImageIcon(bulletImg.getScaledInstance(90, 41,DO_NOTHING_ON_CLOSE )));
        bulletPic.setBounds(100 , 100 ,100 ,100);
        add(bulletPic);
        

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

        

        

        JLabel background = new JLabel(new ImageIcon(backgroundImg.getScaledInstance(800,800,DO_NOTHING_ON_CLOSE)));
        background.setBounds(0,0,800,800);
       
        add(background);
        
        setVisible(true);

        Parallel parallel = new Parallel(aim, cannon);
        parallel.run();
        Thread thread = new Thread(parallel);
        thread.start();
        

    }
    static Game proxy;

    public static void main(String[] args) {

        proxy = new Game();

    }

}
