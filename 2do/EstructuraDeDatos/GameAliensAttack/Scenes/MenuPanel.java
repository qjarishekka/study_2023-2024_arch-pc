package GameAliensAttack.Scenes;

import java.awt.Color;
import java.awt.event.ActionEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Scene;
import GameAliensAttack.GameEngine.SceneManager;
import GameAliensAttack.src.fonts.CustomFonts;

public class MenuPanel extends Scene {
    
    public MenuPanel() {

        setLayout(null);
        setBounds(0,0, MainFrame.width, MainFrame.height);
        setTag("Menu");
        
        JButton playButton = new JButton();
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
            SceneManager.setScene("Game");
        });
        
        JLabel backGround = new JLabel();
        backGround.setBounds(getBounds());
        backGround.setIcon(new ImageIcon(MainFrame.backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));
        add(playButton);
        add(backGround);
        repaint();
        setVisible(true);
    }

}
