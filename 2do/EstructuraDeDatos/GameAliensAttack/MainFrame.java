package GameAliensAttack;

import javax.swing.JFrame;

import java.awt.Rectangle;
import java.awt.Toolkit;

public class MainFrame extends JFrame {

    MenuPanel menuPanel;
    public static int width , height;

    public MainFrame() {
        super("Alien's Attack");
        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        width = (int) t.getScreenSize().getWidth();
        height = (int) t.getScreenSize().getHeight();
        
        setSize(width,height);
        setLayout(null);

        menuPanel = new MenuPanel();
        

        //menuPanel.setVisible(true);
        add(menuPanel);




        setVisible(true);
    }


    public static void main(String [] args){
        new MainFrame();
    }

}
