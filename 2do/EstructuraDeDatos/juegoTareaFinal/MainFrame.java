package juegoTareaFinal;
import java.awt.Color;
import  java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

import JuegoTarea.src.fonts.CustomFonts;

public class MainFrame extends JFrame{

    public boolean start = false;
    static MainFrame proxy;
    GameManager gameManager;
    Thread thread;

    Image backgroundImage = new ImageIcon("src//backGround.png").getImage();
    JLabel background = new JLabel();


    BufferedReader bufferedReader;
    File file;
    FileReader fileReader;
    Scores scores = new Scores();

    CustomFonts customFonts = new CustomFonts();
    




    public MainFrame(){

        

        super("MyFinalGame");

        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)t.getScreenSize().getWidth() , (int)t.getScreenSize().getHeight());
        setLayout(null);
        setVisible(true);

        background.setIcon(new ImageIcon(backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));
        background.setBounds(0,0,getWidth(),getHeight());
  
 



    

    }

    public void Menu(){

        add(background);

        repaint();

    }



    public void gameStart(){


        gameManager = new GameManager(this);
        thread = new Thread(gameManager);
        thread.start();

        System.out.println("numero de objetos " + getContentPane().getComponentCount());
        repaint();
    }




    

    public static void main(String[] args){

        proxy = new MainFrame();
        proxy.Menu();

        //proxy.gameStart();

        
        

    }
}
