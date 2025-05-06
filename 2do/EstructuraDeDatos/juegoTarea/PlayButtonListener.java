package juegoTarea;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;



public class PlayButtonListener implements ActionListener {
        MainFrame main;

    public PlayButtonListener(MainFrame main ){

        this.main = main;


    } 

    @Override
    public void actionPerformed(ActionEvent e) {
        
        main.gameStart();

    }



}
