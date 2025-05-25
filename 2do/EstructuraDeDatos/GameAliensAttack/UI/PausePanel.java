package GameAliensAttack.UI;

import java.awt.Color;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JPanel;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.GameEngine;
import GameAliensAttack.GameEngine.UIManager;
import GameAliensAttack.GameEngine.UIPanel;
import GameAliensAttack.src.fonts.CustomFonts;

public class PausePanel extends UIPanel {

    public PausePanel(){

        //GameEngine.pause();

        setLayout(null);
        setBounds(0, 0, MainFrame.width, MainFrame.height);
        setBackground(new Color(0, 0, 0, 100));   
        setTag("Pause");

        //Continue button
        int continueButtonWidth = getWidth()*30/100;
        int continueButtonHeight = getHeight()*20/100;
        JButton continueButton = new JButton("CONTINUE");
        continueButton.setBounds((getWidth()/2) - (continueButtonWidth/2)  ,(getHeight()/2) - (continueButtonHeight/2),continueButtonWidth,continueButtonHeight);
        continueButton.setFont(  new CustomFonts().font(70) );
        continueButton.setOpaque(false);
        continueButton.setBackground(null);
        continueButton.setContentAreaFilled(false);
        continueButton.setBorderPainted(false);
        continueButton.setForeground(Color.green);
        continueButton.addActionListener((ActionEvent e )->{
            UIManager.hideUIPanel("Pause");
            GameEngine.play();
        });
        

        //Exit button
        int exitButtonWidth = getWidth()*20/100;
        int exitButtonHeight = getHeight()*10/100;
        JButton exitButton = new JButton("EXIT");
        exitButton.setBounds((getWidth()/2) - (exitButtonWidth/2)  ,(getHeight()/2) + (exitButtonHeight/2),exitButtonWidth,exitButtonHeight);
        exitButton.setFont(  new CustomFonts().font(70) );
        exitButton.setOpaque(false);
        exitButton.setContentAreaFilled(false);
        exitButton.setBorderPainted(false);
        exitButton.setForeground(Color.green);
        exitButton.addActionListener((ActionEvent e )->{
            //System.gc();
            MainFrame.proxy.dispose();
            System.exit(128);

        });

        add(exitButton);
        add(continueButton);
        //repaint();


    }

}
