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
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

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
    int score = 0;
    

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
        //Image playImage = new ImageIcon("src//play.png").getImage();
        //playButton.setIcon( new ImageIcon(playImage.getScaledInstance(playButtonWidth, playButtonHeight, 0))   );
        playButton.setText("PLAY");
        playButton.setFont(customFonts.font);
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

        try {
            thread.interrupt();
        } catch (Exception e) {
            // TODO: handle exception
        }
        
        

        getContentPane().removeAll();

        JLabel gameOverText = new JLabel();
        //gameOverText.setBounds(   (proxy.getWidth() - proxy.getWidth()*20/100)/2  , (proxy.getHeight() - proxy.getHeight()*20/100)/2  , proxy.getWidth()*20/100 , proxy.getHeight()*20/100);
        gameOverText.setBounds(   0 , 0 , proxy.getWidth()*20/100 , proxy.getHeight()*20/100);

        gameOverText.setLocation( (proxy.getWidth() - gameOverText.getWidth()) /2 ,   getHeight()*5/100 );
        gameOverText.setHorizontalAlignment(SwingConstants.CENTER);
        gameOverText.setText("GAME OVER");
        gameOverText.setFont(customFonts.font);
        gameOverText.setBackground(Color.WHITE);
        gameOverText.setOpaque(false);
        gameOverText.setForeground(Color.green);

        JTextField insertYourName = new JTextField();
        insertYourName.setBounds(0 , 0 , getWidth()*30/100 , getHeight()*5/100);
        insertYourName.setLocation( (int)gameOverText.getBounds().getCenterX() - (int)insertYourName.getWidth()/2 ,  (int)gameOverText.getBounds().getCenterY() + insertYourName.getHeight() )  ;
        insertYourName.setForeground(Color.green);
        insertYourName.setOpaque(false);
        insertYourName.setFocusable(true);
        insertYourName.setFont(customFonts.font);

        JLabel feedback = new JLabel();
        feedback.setBounds(insertYourName.getBounds());
        feedback.setLocation(feedback.getX() , feedback.getY() + (int)(feedback.getHeight()*1.5));
        //feedback.setOpaque(true);
        feedback.setFont(customFonts.font);
        feedback.setForeground(Color.green);
        feedback.setHorizontalAlignment(SwingConstants.CENTER);
        //feedback.setText("ejemplo");
        

        TextInputLIstener textInputLIstener = new TextInputLIstener(insertYourName, scores, proxy , feedback);
        insertYourName.addActionListener(textInputLIstener);

        JLabel laderBoard = new JLabel();
        

        
        


        
        add(feedback);
        add(insertYourName);
        add(gameOverText);
        add(background);


        //System.gc();
        //proxy.dispose();
        //System.exit(ABORT);
        repaint();


    }




    

    public static void main(String[] args){

        proxy = new MainFrame();
        proxy.gameOver();

        //proxy.gameStart();

    }
}
