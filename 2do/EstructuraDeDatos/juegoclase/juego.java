package juegoclase;
import javax.swing.*;
import java.awt.*;

public class juego extends JFrame {
    
    juego(){
        super("worms");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(800,500);
        setLayout(null);


        JLabel cannon = new JLabel(new ImageIcon(""));
        cannon.setBounds(0,getHeight() - 100 , 60 , 60);
        add(cannon);

        JLabel aim = new JLabel(new ImageIcon(""));
        aim.setBounds();


        

    }

}
