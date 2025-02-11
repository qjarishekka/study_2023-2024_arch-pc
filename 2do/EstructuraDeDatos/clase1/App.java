import javax.swing.*;

public class App extends JFrame{

    App(){
        super("My first app");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(480,380);
        setLayout(null);

        JLabel label = new JLabel("hello");
        label.setBounds(20,20,60, 30);
        add(label);

        setVisible(true);

    }

    public static void main(String[] args){

     
        new App();
    }
}