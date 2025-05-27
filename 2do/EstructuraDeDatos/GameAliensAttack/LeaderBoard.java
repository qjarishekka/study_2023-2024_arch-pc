package GameAliensAttack;

import java.awt.Color;

import javax.swing.JLabel;
import javax.swing.SwingConstants;

import juegoTarea.src.fonts.CustomFonts;

public class LeaderBoard extends JLabel{

    int rows = 5;
    JLabel leaderBoard[] = new JLabel[rows];
    public Scores scores = GameManager.scores;
    CustomFonts customFonts = new CustomFonts();

    public LeaderBoard(){

        
        setBounds(0 , 0 , MainFrame.width*30/100 , MainFrame.height*rows/10);
        setLocation((MainFrame.width - getWidth())/2 , (MainFrame.height + getHeight())/2*50/100  );
        setOpaque(false);
        setBoard();

    }   

    public void setBoard(){

        //removeAll();

        //if(scores.leaderboard.length < rows)
         

        for(int i = 0 ; i < rows; i ++){
            leaderBoard[i] = new JLabel();
            leaderBoard[i].setBounds(0, 0 , getWidth(), getHeight()/5);
            leaderBoard[i].setLocation(0 , leaderBoard[0].getHeight()*i);
            //leaderBoard[i].setBackground(Color.green);
            leaderBoard[i].setOpaque(false);
            leaderBoard[i].setForeground(Color.green);
            leaderBoard[i].setFont(customFonts.font);
            if(i < scores.leaderboard.length ){
                leaderBoard[i].setText(scores.leaderboard[i]);
                leaderBoard[i].setHorizontalAlignment(SwingConstants.CENTER);
            }
            add(leaderBoard[i]);
        }

    }

    public void refresBoard(){

        //System.out.println(scores.leaderboard.length);
        rows = 5;
        if(scores.leaderboard.length < rows)
         rows = scores.leaderboard.length;

        for(int i = 0 ; i < rows ; i++ ){
            leaderBoard[i].setText(scores.leaderboard[i]);
            leaderBoard[i].setHorizontalAlignment(SwingConstants.CENTER); 

            //System.out.println(scores.leaderboard[i]);
        }

        //repaint();;
    }
    
}
