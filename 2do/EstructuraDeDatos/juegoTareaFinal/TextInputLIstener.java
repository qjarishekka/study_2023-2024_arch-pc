package juegoTareaFinal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.JTextField;

public class TextInputLIstener implements ActionListener {

    Scores scores;
    JTextField input;
    int score;
    JLabel feedBack;
    boolean flag = false;

    public TextInputLIstener( JTextField input, Scores scores , MainFrame mainFrame , JLabel feedBack){
        this.input = input;
        this.scores = scores;
        score = mainFrame.score;
        this.feedBack = feedBack;
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if( !input.getText().isEmpty() ){
            String inputCleaned = input.getText().replace(" ", "");
            scores.setNewScore(inputCleaned,  score);
            //input.setText("");
        }

        if(scores.wasNewScoreSet()){    
            input.setFocusable(false);
            feedBack.setText("new name registered");
        }else{
            feedBack.setText("");
            feedBack.repaint();
            if(flag){
                feedBack.setText("name used, TRY AGAIN!");
                flag = !flag;
            }else{
                feedBack.setText("TRY AGAIN!");
                flag = !flag;
            }
            
        }


        
        


    }
    
}
