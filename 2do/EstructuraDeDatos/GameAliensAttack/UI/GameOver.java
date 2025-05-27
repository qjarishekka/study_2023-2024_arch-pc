package GameAliensAttack.UI;

import java.awt.Color;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import GameAliensAttack.GameManager;
import GameAliensAttack.LeaderBoard;
import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.UIManager;
import GameAliensAttack.GameEngine.UIPanel;
import GameAliensAttack.src.fonts.CustomFonts;
import juegoclase.Game;

public class GameOver extends UIPanel {
    
    public LeaderBoard leaderBoard = new LeaderBoard();
    JLabel gameOverText = new JLabel();
    GameManager gameManager;
    public JTextField insertYourName = new JTextField();
    public JLabel feedback = new JLabel();
    JButton playButton = new JButton();
    public boolean flag = false;


    public GameOver(GameManager gameManager){
        this.gameManager = gameManager;

        setTag("GameOver");

        setBackground(new Color(Color.TRANSLUCENT));


        //gameOverText.setBounds(   (proxy.getWidth() - proxy.getWidth()*20/100)/2  , (proxy.getHeight() - proxy.getHeight()*20/100)/2  , proxy.getWidth()*20/100 , proxy.getHeight()*20/100);
        gameOverText.setBounds(   0 , 0 , MainFrame.width*40/100 , MainFrame.height*20/100);

        gameOverText.setLocation( (MainFrame.width - gameOverText.getWidth()) /2 ,   getHeight()*5/100 );
        gameOverText.setHorizontalAlignment(SwingConstants.CENTER);
        gameOverText.setText("GAME OVER");
        gameOverText.setFont( new CustomFonts().font(70));
        gameOverText.setBackground(Color.WHITE);
        gameOverText.setOpaque(false);
        gameOverText.setForeground(Color.green);

        
        insertYourName.setBounds(0 , 0 , getWidth()*30/100 , getHeight()*5/100);
        insertYourName.setLocation( (int)gameOverText.getBounds().getCenterX() - (int)insertYourName.getWidth()/2 ,  (int)gameOverText.getBounds().getCenterY() + insertYourName.getHeight() )  ;
        insertYourName.setBackground(new java.awt.Color(0,0,0,1));
        insertYourName.setBorder(null);
        insertYourName.setForeground(Color.green);
        insertYourName.setOpaque(false);
        insertYourName.setFocusable(true);
        insertYourName.setFont( new CustomFonts().font(40));


        


        
        feedback.setBounds(insertYourName.getBounds());
        feedback.setLocation(feedback.getX() , feedback.getY() + (int)(feedback.getHeight()*1.5));
        //feedback.setOpaque(true);
        feedback.setFont( new CustomFonts().font(40));
        feedback.setForeground(Color.green);
        feedback.setHorizontalAlignment(SwingConstants.CENTER);

        insertYourName.addActionListener((ActionEvent e)->{

            if( !insertYourName.getText().isEmpty() ){
                String inputCleaned = insertYourName.getText().replace(" ", "");
                leaderBoard.scores.setNewScore(inputCleaned,  GameManager.score);

            }

            if(GameManager.scores.wasNewScoreSet()){    
                insertYourName.setFocusable(false);
                feedback.setText("new name registered");
                insertYourName.setText("");
        
            }else{
                feedback.setText("");
                feedback.repaint();
                if(flag){
                    feedback.setText("name used, TRY AGAIN!");
                    flag = !flag;
                }else{
                    feedback.setText("TRY AGAIN!");
                    flag = !flag;
                }
                
            }
        
            leaderBoard.refresBoard();
        });

        
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( 0 ,0 ,playButtonWidth,playButtonHeight);
        playButton.setLocation( getWidth()*10/100 , getHeight()/2 );
        playButton.setText("PLAY AGAIN");
        playButton.setFont( new CustomFonts().font(40)  );
        playButton.setOpaque(false);
        playButton.setContentAreaFilled(false);
        playButton.setBorderPainted(false);
        playButton.setForeground(Color.green);
        //PlayButtonListener playButtonListener = new PlayButtonListener(proxy);
        playButton.addActionListener((ActionEvent e)->{
            
            UIManager.hideUIPanel("GameOver");
            gameManager.playAgain();

        });

        JButton exitButton = new JButton();
        int exitButtonWidth = getWidth() * 30 / 100;
        int exitButtonHeight = getHeight() * 20 / 100;
        exitButton.setBounds( 0 ,0 ,exitButtonWidth,exitButtonHeight);
        exitButton.setLocation( getWidth()*90/100 - exitButtonWidth , getHeight()/2 );
        exitButton.setText("EXIT");
        exitButton.setFont( new CustomFonts().font(40)  );
        exitButton.setOpaque(false);
        exitButton.setContentAreaFilled(false);
        exitButton.setBorderPainted(false);
        exitButton.setForeground(Color.green);
        //ExitButtonListener exitButtonListener = new ExitButtonListener(proxy);
        exitButton.addActionListener((ActionEvent e)->{

            MainFrame.proxy.dispose();
            System.exit(128);


        });

        



        //Sort sort = new Sort(proxy);

        //add(sort);

        
        add(exitButton);
        add(playButton);
        add(leaderBoard);
        add(feedback);
        add(insertYourName);
        add(gameOverText);
        //add(background);

        insertYourName.requestFocus();
        



        //add(gameOver);

    }



}
