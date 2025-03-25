package juegoTareaFinal;

import java.awt.Color;
import java.awt.Font;
import  java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JButton;
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

        JButton playButton = new JButton();
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( (getWidth()/2) - (playButtonWidth/2)  ,(getHeight()/2) - (playButtonHeight/2),playButtonWidth,playButtonHeight);
        Image playImage = new ImageIcon("src//play.png").getImage();
        playButton.setIcon( new ImageIcon(playImage.getScaledInstance(playButtonWidth, playButtonHeight, 0))   );
        
        PlayButtonListener playButtonListener = new PlayButtonListener(proxy);
        playButton.addActionListener(playButtonListener);


        add(playButton);
        add(background);

        repaint();

    }


    public void gameStart(){

        getContentPane().removeAll();

        gameManager = new GameManager(this);
        thread = new Thread(gameManager);
        thread.start();

        System.out.println("numero de objetos " + getContentPane().getComponentCount());
        repaint();
    }

    public void gameOver(){

        
        
        thread.interrupt();
        getContentPane().removeAll();

        JLabel gameOverText = new JLabel();
        gameOverText.setBounds(   (proxy.getWidth() - proxy.getWidth()*20/100)/2  , (proxy.getHeight() - proxy.getHeight()*20/100)/2  , proxy.getWidth()*20/100 , proxy.getHeight()*20/100);
        //gameOverText.setLocation( (proxy.getWidth()  - gameOverText.getWidth())/2 ,  (proxy.getHeight()- gameOverText.getHeight())/2 );
        gameOverText.setText("GAME OVER");
        gameOverText.setFont(customFonts.font);
        gameOverText.setForeground(Color.green);
        add(gameOverText);
        add(background);



        //System.gc();
        //proxy.dispose();
        //System.exit(ABORT);
        repaint();


    }




    

    public static void main(String[] args){

        proxy = new MainFrame();
        proxy.Menu();

        //proxy.gameStart();

        
        

    }
}
