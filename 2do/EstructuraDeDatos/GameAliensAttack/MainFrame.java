package GameAliensAttack;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;

public class MainFrame extends JFrame {

    static MenuPanel menuPanel;
    public static int width , height;
    public static final Image backgroundImage = new ImageIcon("src//backGround.png").getImage();
    SceneManager sceneManager;
    public static MainFrame proxy;
    //public static final Image backgroundImage = new ImageIcon("src//backGround.png").getImage();
    //JLabel background = new JLabel();
    

    public MainFrame() {
        super("Alien's Attack");
        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        width = (int) t.getScreenSize().getWidth();
        height = (int) t.getScreenSize().getHeight();
        setSize(width,height);
        setLayout(null);
        proxy = this;


        //setIcon(new ImageIcon(backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));
        //setIconImage(backgroundImage);

        /* SceneManager sceneManager = new SceneManager();
        sceneManager.setScene("Menu"); */
        
        //sceneManager.setScene("Menu");
        
        

        /* menuPanel = new MenuPanel();
        add(menuPanel); */

        GamePanel gamePanel = new GamePanel();
        add(gamePanel);

        setVisible(true);
    }


    public static void main(String [] args){
        new MainFrame();
    }

}
