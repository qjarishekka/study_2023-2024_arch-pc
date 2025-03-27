package juegoTareaFinal;

import java.awt.Color;

import javax.swing.JLabel;

public class LeaderBoard extends JLabel{

    int rows = 5;
    MainFrame mainFrame;
    JLabel leaderBoard[] = new JLabel[rows];
    Scores scores;

    public LeaderBoard( MainFrame mainFrame){

    
        this.scores = mainFrame.scores;
        setBounds(0 , 0 , mainFrame.getWidth()*30/100 , mainFrame.getHeight()*50/100);
        setLocation((mainFrame.getWidth() - getWidth())/2 , (mainFrame.getHeight() + getHeight())/2*50/100  );

        setOpaque(true);

    }   

    public void setBoard(){

        for(int i = 0 ; i < rows; i ++){
            leaderBoard[i].setBounds(0, 0 , getWidth(), getHeight()/5);
            leaderBoard[i].setBackground(Color.green);
            leaderBoard[i].setOpaque(true);
            add(leaderBoard[i]);
        }

    }
    
}
