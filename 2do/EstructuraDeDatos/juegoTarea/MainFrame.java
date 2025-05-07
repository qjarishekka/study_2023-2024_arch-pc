package juegoTarea;

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

import GameAliensAttack.MenuPanel;
import juegoTarea.src.fonts.CustomFonts;


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
    LeaderBoard leaderBoard;

    JButton playButton;
    
    




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

        playButton = new JButton();
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( (getWidth()/2) - (playButtonWidth/2)  ,(getHeight()/2) - (playButtonHeight/2),playButtonWidth,playButtonHeight);
        playButton.setText("PLAY");
        playButton.setFont(  customFonts.font(70)  );
        playButton.setOpaque(false);
        playButton.setContentAreaFilled(false);
        playButton.setBorderPainted(false);
        playButton.setForeground(Color.green);
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
        insertYourName.setBackground(new java.awt.Color(0,0,0,1));
        insertYourName.setBorder(null);
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
        
        /* JLabel leaderBoard = new JLabel();
        leaderBoard.setBounds(feedback.getBounds());
        leaderBoard.setSize(leaderBoard.getWidth(), getHeight()/2);
        leaderBoard.setOpaque(true);
        leaderBoard.setFont(customFonts.font);
        leaderBoard.setText(scores.getLeaderBoardAsText());
        leaderBoard.setHorizontalAlignment(SwingConstants.CENTER); */

        leaderBoard = new LeaderBoard(proxy);

        TextInputLIstener textInputLIstener = new TextInputLIstener(insertYourName, scores, proxy , feedback, leaderBoard);
        insertYourName.addActionListener(textInputLIstener);

        playButton = new JButton();
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( 0 ,0 ,playButtonWidth,playButtonHeight);
        playButton.setLocation( getWidth()*10/100 , getHeight()/2 );
        playButton.setText("PLAY AGAIN");
        playButton.setFont(  customFonts.font(70)  );
        playButton.setOpaque(false);
        playButton.setContentAreaFilled(false);
        playButton.setBorderPainted(false);
        playButton.setForeground(Color.green);
        PlayButtonListener playButtonListener = new PlayButtonListener(proxy);
        playButton.addActionListener(playButtonListener);

        JButton exitButton = new JButton();
        int exitButtonWidth = getWidth() * 30 / 100;
        int exitButtonHeight = getHeight() * 20 / 100;
        exitButton.setBounds( 0 ,0 ,exitButtonWidth,exitButtonHeight);
        exitButton.setLocation( getWidth()*90/100 - exitButtonWidth , getHeight()/2 );
        exitButton.setText("EXIT");
        exitButton.setFont(  customFonts.font(70)  );
        exitButton.setOpaque(false);
        exitButton.setContentAreaFilled(false);
        exitButton.setBorderPainted(false);
        exitButton.setForeground(Color.green);
        ExitButtonListener exitButtonListener = new ExitButtonListener(proxy);
        exitButton.addActionListener(exitButtonListener);

        



        //Sort sort = new Sort(proxy);

        //add(sort);

        
        add(exitButton);
        add(playButton);
        add(leaderBoard);
        add(feedback);
        add(insertYourName);
        add(gameOverText);
        add(background);

        insertYourName.requestFocus();


        //System.gc();
        //proxy.dispose();
        //System.exit(ABORT);
        repaint();


    }




    

    public static void main(String[] args){

        proxy = new MainFrame();
       //proxy.Menu();;
       proxy.gameStart();


    }
}
