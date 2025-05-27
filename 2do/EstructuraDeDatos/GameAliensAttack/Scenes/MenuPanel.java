package GameAliensAttack.Scenes;

import java.awt.Color;
import java.awt.event.ActionEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import GameAliensAttack.GameManager;
import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.GameEngine;
import GameAliensAttack.GameEngine.Scene;
import GameAliensAttack.GameEngine.SceneManager;
import GameAliensAttack.GameEngine.UIManager;
import GameAliensAttack.src.fonts.CustomFonts;

public class MenuPanel extends Scene {

        static public boolean enable = true;
        static public JButton playButton = new JButton();
        static public JButton options = new JButton("Options");
    
    public MenuPanel() {

        setLayout(null);
        setBounds(0,0, MainFrame.width, MainFrame.height);
        setTag("Menu");
        
        
        int playButtonWidth = getWidth() * 30 / 100;
        int playButtonHeight = getHeight() * 20 / 100;
        playButton.setBounds( (getWidth()/2) - (playButtonWidth/2)  ,(getHeight()/2) - (playButtonHeight/2),playButtonWidth,playButtonHeight);
        playButton.setText("PLAY");
        playButton.setFont(  new CustomFonts().font(70) );
        playButton.setOpaque(false);
        playButton.setContentAreaFilled(false);
        playButton.setBorderPainted(false);
        playButton.setForeground(Color.green);
        playButton.setFocusPainted(false);
        playButton.addActionListener((ActionEvent e)->{
            if(this.enable){
                SceneManager.setScene("Game");
                GameEngine.play();
            }
            
        });

        
        int optionsWidth = getWidth()*30/100;
        int optionsHeight = getHeight()*10/100;
        options.setBounds(playButton.getX(), playButton.getY() + playButton.getHeight() , optionsWidth, optionsHeight);
        options.setFont(  new CustomFonts().font(70) );
        options.setOpaque(false);
        options.setBackground(null);
        options.setContentAreaFilled(false);
        options.setBorderPainted(false);
        options.setForeground(Color.green);
        options.addActionListener((ActionEvent e )->{
            if(this.enable){
                options.setEnabled(false);
                playButton.setEnabled(false);
                UIManager.showUIPanel("Options");
                GameManager.options = true;
                enable = false;
            }
            
        });
        
        JLabel backGround = new JLabel();
        backGround.setBounds(getBounds());
        backGround.setIcon(new ImageIcon(MainFrame.backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));
        add(options,0);
        add(playButton);
        add(backGround);
        repaint();
        setVisible(true);
    }

}
