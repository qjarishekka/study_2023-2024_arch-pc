package tarea1;

import javax.imageio.ImageIO;
import javax.swing.*;

//import clases.App;

import java.awt.*;
import java.awt.geom.Dimension2D;
import java.io.File;
import java.io.IOException;



public class homework extends JFrame {

    

    homework(){
        super("Homework1");
        /* Image img = null;
        try {
            img = ImageIO.read(new File("2do\\EstructuraDeDatos\\tarea1\\astronauta.jpg"));
        } catch (IOException e) {
        e.printStackTrace();
        } */
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(1280,720); //1280x720
        setLayout(null);
        //setFocusable(true);


        JLabel label = new JLabel("hello its me Q'jari");
        label.setBounds(60,20,220, 60);
        label.setFont(new Font("Microsoft Sans Serif", Font.PLAIN , 20));
        label.setBackground(Color.BLACK);
        label.setForeground(Color.WHITE);
        label.setOpaque(true);
        add(label);

        JTextField inputField = new JTextField();
        inputField.setBounds(80,100,160,30);
        add(inputField);

        JButton button = new JButton("click me"); //PRIMER BOTON
        button.setBounds(80,140,160,40);
        add(button);

        

        

        Image img  = new ImageIcon("2do\\EstructuraDeDatos\\tarea1\\astronauta.jpg").getImage(); 
        JLabel pic = new JLabel(new ImageIcon(img.getScaledInstance(100, 100,DO_NOTHING_ON_CLOSE )));
        pic.setBounds(400,400,100,100 );
        add(pic);

        add(pic);


        MyTextListener textListener = new MyTextListener(inputField,label,pic, img);
        inputField.addActionListener(textListener);
        
        button.addActionListener(textListener);

        Mouse mouse = new Mouse(pic);
        addMouseMotionListener(mouse);

        keyboard keyboard = new keyboard(pic);
        inputField.addKeyListener(keyboard);

        
        


        setVisible(true);
    }

    public static void main(String[] args) {

        
        new homework();
    }
}
