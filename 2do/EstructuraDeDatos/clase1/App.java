import javax.swing.*;
import java.awt.*;

public class App extends JFrame{

    App(){
        super("My first app");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(480,380);
        setLayout(null);

        JLabel label = new JLabel("hello");
        label.setBounds(20,20,60, 30);
        label.setFont(new Font("Papyrus", Font.ITALIC, 10));




        add(label);


        JButton button = new JButton("click me");
        button.setBounds(40,60,160,40);
        add(button);

        setVisible(true);

    }

    public static void main(String[] args){


        new App();
    }
}