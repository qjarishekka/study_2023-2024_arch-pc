package GameAliensAttack;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

import java.awt.Image;
import java.awt.Toolkit;

public class MainFrame extends JFrame {

    public static int width , height;
    public static final Image backgroundImage = new ImageIcon("src//backGround.png").getImage();
    SceneManager sceneManager;
    GameEngine gameEngine;
    Input input = new Input();
    public static MainFrame proxy;

    public MainFrame() {
        super("Alien's Attack");
        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        width = (int) t.getScreenSize().getWidth();
        height = (int) t.getScreenSize().getHeight();
        setSize(width,height);
        setLayout(null);
        proxy = this;
        sceneManager = new SceneManager();
        sceneManager.setScene("Menu");
        gameEngine = new GameEngine();
        addKeyListener(input);
        addMouseListener(input);
        addMouseMotionListener(input);

        setVisible(true);
    }


    public static void main(String [] args){
        new MainFrame();
    }

}
