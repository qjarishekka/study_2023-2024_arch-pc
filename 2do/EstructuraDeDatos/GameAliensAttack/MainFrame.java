package GameAliensAttack;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

import java.awt.Image;
import java.awt.Toolkit;
import GameAliensAttack.GameEngine.*;

public class MainFrame extends JFrame {

    public static int width , height;
    public static final Image backgroundImage = new ImageIcon("src//backGround.png").getImage();
    public SceneManager sceneManager;
    GameEngine gameEngine;
    GameManager gameManager;
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
        gameManager = new GameManager();
        sceneManager = new SceneManager();
        gameEngine = new GameEngine();
        Input.initialize(this);
        setVisible(true);

    }

    public static void main(String [] args){
        new MainFrame();
    }

}
