package tarea1;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.*;

public class MyTextListener implements ActionListener{

    private JTextField input;
    private JLabel output;
    private String text[];
    private JLabel pic;
    private Image img;

    


    MyTextListener(JTextField ip, JLabel out , JLabel pic, Image img){
        input = ip;
        output = out;
        this.pic = pic;
        this.img = img;
        
    }

    @Override
    public void actionPerformed(ActionEvent e){

        text = input.getText().split(" ");
        String commands[] = {"moveto","relmove"};

       
        if( text[0].compareTo(commands[0]) == 0   ){

            if( text.length > 1)
            Move(Integer.parseInt(text[1]) ,Integer.parseInt(text[2]));
            else 
            output.setText("not enough arguments");
            
        }else if( text[0].compareTo(commands[1]) == 0   ){

            if( text.length > 1)
            RMove(Integer.parseInt(text[1]) ,Integer.parseInt(text[2]));
            else
            output.setText("not enough arguments");
            
        }else
            output.setText("command not found");
        

        //output.setText(input.getText());
        input.setText("");
        //input.transferFocus();

    }

    private void Move(int x, int y){

        pic.setLocation(x, y);
        output.setText("moved to " + x + " " + y);

    }

    private void RMove(int x ,int y){

        int a = pic.getX()+x;
        int b = pic.getY()+y;

        pic.setLocation(a, b);

        output.setText("moved to " + a + " " + b);

    }



}