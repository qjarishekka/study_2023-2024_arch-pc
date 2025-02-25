import javax.swing.*;
import java.awt.*;

public class App extends JFrame{

    App(){
        super("My first app");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(1280,720); //1280x720
        setLayout(null);

        JLabel label = new JLabel("hello its me Q'jari");
        label.setBounds(20,20,220, 40);
        label.setFont(new Font("Papyrus", Font.ITALIC, 20));
        label.setBackground(Color.RED);
        label.setForeground(Color.GREEN);
        label.setOpaque(true);

        JLabel pic = new JLabel(new ImageIcon("2do\\EstructuraDeDatos\\imagenRandom.jpg"));
        pic.setBounds(20,110,160,60 );
        add(pic);



        add(label);


        JButton button = new JButton("click me"); //PRIMER BOTON
        button.setBounds(40,60,160,40);
        add(button);

        JTextField inputField = new JTextField();
        inputField.setBounds(300,20,160,30);
        add(inputField);

        MyTextListener textListener = new MyTextListener(inputField,label);
        inputField.addActionListener(textListener);
        button.addActionListener(textListener);


        KeyBoard keyBoard = new KeyBoard(pic);
        addKeyListener(keyBoard);
        //inputField.addKeyListener(keyBoard);
        //inputField.setFocusable(false);

        Mouse mouse = new Mouse(pic);
        addMouseListener(mouse);

        inputField.addKeyListener(keyBoard);
        //addKeyListener(keyBoard);

        //inputField.setFocusable(false);  //esta linea desabilita el enfoque hacia los objetos
        button.setFocusable(false);


        

       /*  JButton button2 = new JButton("click me"); //SEGUNBDO BOTON
        button2.setBounds(40,120,160,40);
        add(button2);

        MyButtonlistener listener2 = new MyButtonlistener(button); // escuchador del segundo boton
        //listener.button = button; se puede hacer asi pero no se recomienda
        button2.addActionListener(listener2); */

        MyButtonlistener listener = new MyButtonlistener(pic,10,10); // escuchador del primer boton
        button.addActionListener(listener);
        //button.addActionListener(listener2);


        
        




        setVisible(true);

    }

    public static void main(String[] args){


        new App();

        //System.out.println("hola");
    }
}