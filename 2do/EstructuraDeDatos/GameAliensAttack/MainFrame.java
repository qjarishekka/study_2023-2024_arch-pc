package GameAliensAttack;
import javax.swing.JFrame;
import java.awt.Toolkit;

public class MainFrame extends JFrame{
    public MainFrame(){
        super("Alien's Attack");

        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)t.getScreenSize().getWidth() , (int)t.getScreenSize().getHeight());
        setLayout(null);
        setVisible(true);

    }
    
}
