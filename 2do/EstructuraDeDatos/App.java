import javax.swing.*;
import java.awt.*;
public class App extends JFrame{

    App(){
        super("My first app");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(480,380);
        setLayout(null);

        JLabel label = new JLabel("hello its me michael");
        label.setBounds(20,20,220, 40);
        label.setFont(new Font("Papyrus", Font.ITALIC, 20));
        label.setBackground(Color.RED);
        label.setForeground(Color.GREEN);
        label.setOpaque(true);



        add(label);


        JButton button = new JButton("click me");
        button.setBounds(40,60,160,40);
        add(button);

        MyButtonlistener listener = new MyButtonlistener();
        button.addActionListener(listener);
        




        setVisible(true);

    }

    public static void main(String[] args){


        new App();

        //System.out.println("hola");
    }
}