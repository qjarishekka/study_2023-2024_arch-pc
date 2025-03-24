package juegoTareaFinal;
import java.awt.Color;
import  java.awt.Toolkit;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MainFrame extends JFrame{

    public boolean start = false;
    static MainFrame proxy;
    GameManager gameManager;
    Thread thread;
    




    public MainFrame(){

        

        super("MyFinalGame");

        Toolkit t = Toolkit.getDefaultToolkit();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize((int)t.getScreenSize().getWidth() , (int)t.getScreenSize().getHeight());
        setLayout(null);
        setVisible(true);

    

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
        proxy.gameStart();

        
        

    }
}
