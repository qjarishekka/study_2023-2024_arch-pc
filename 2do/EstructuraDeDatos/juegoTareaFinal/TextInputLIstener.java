package juegoTareaFinal;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextField;

public class TextInputLIstener implements ActionListener {

    Scores scores;
    JTextField input;
    int score;

    public TextInputLIstener( JTextField input, Scores scores , MainFrame mainFrame){
        this.input = input;
        this.scores = scores;
        score = mainFrame.score;
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if( !input.getText().isEmpty() ){
            String inputCleaned = input.getText().replace(" ", "");
            scores.setNewScore(inputCleaned,  score);
            input.setText("");
        }

        input.setFocusable(false);
        


    }
    
}
