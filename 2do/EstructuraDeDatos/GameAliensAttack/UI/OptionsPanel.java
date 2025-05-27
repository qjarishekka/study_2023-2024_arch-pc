package GameAliensAttack.UI;

import java.awt.Color;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import GameAliensAttack.GameManager;
import GameAliensAttack.MainFrame;
import GameAliensAttack.GameEngine.Scene;
import GameAliensAttack.GameEngine.SceneManager;
import GameAliensAttack.GameEngine.UIManager;
import GameAliensAttack.GameEngine.UIPanel;
import GameAliensAttack.Scenes.MenuPanel;
import GameAliensAttack.src.fonts.CustomFonts;

public class OptionsPanel extends UIPanel{

    JLabel difficulty = new JLabel("1");
    
    public OptionsPanel(){
        setTag("Options");
        setBackground(new Color(0,0,0,200));

        JLabel chooseDifficulty = new JLabel("CHOOSE DIFFICULTY");
        int chooseDifficultyWidth = MainFrame.width*50/100;
        int chooseDifficultyHeight = MainFrame.height*10/100; 
        chooseDifficulty.setBounds((getWidth() - chooseDifficultyWidth)/2, (getHeight() - chooseDifficultyHeight*3)/2, chooseDifficultyWidth, chooseDifficultyHeight);
        chooseDifficulty.setForeground(Color.GREEN);
        chooseDifficulty.setHorizontalAlignment(SwingConstants.CENTER);
        chooseDifficulty.setFont(new CustomFonts().font(70));
        

        int buttonsSize = MainFrame.height*10/100;
        JButton decrease = new JButton("<");
        decrease.setBounds(getWidth() / 2 - buttonsSize*3/2 , getHeight()/2 , buttonsSize, buttonsSize);
        decrease.setFont(  new CustomFonts().font(70) );
        decrease.setOpaque(false);
        decrease.setBackground(null);
        decrease.setContentAreaFilled(false);
        decrease.setBorderPainted(false);
        decrease.setHorizontalAlignment(SwingConstants.CENTER);
        decrease.setForeground(Color.green);
        decrease.addActionListener((ActionEvent e)->{

            if(GameManager.difficulty > 1  ){
                GameManager.difficulty--;
                difficulty.setText(Integer.toString(GameManager.difficulty));
            }


        });


         JButton increase = new JButton(">");
        increase.setBounds(getWidth() / 2  + buttonsSize/2  , getHeight()/2 , buttonsSize, buttonsSize);
        increase.setFont(  new CustomFonts().font(70) );
        increase.setOpaque(false);
        increase.setBackground(null);
        increase.setContentAreaFilled(false);
        increase.setBorderPainted(false);
        increase.setHorizontalAlignment(SwingConstants.CENTER);
        increase.setForeground(Color.green);
        increase.addActionListener((ActionEvent e)->{
            
            if( GameManager.difficulty < 3 ){
                GameManager.difficulty++;
                difficulty.setText(Integer.toString(GameManager.difficulty));
            }

        });

        difficulty.setBounds((getWidth() - buttonsSize)/2 , getHeight()/2 , buttonsSize, buttonsSize);
        difficulty.setForeground(Color.GREEN);
        difficulty.setHorizontalAlignment(SwingConstants.CENTER);
        difficulty.setFont(new CustomFonts().font(70));

        JButton accept = new JButton("accept");
        int acceptWidth = MainFrame.width*30/100;
        int acceptHeight = MainFrame.height*10/100;
        accept.setBounds((getWidth() - acceptWidth)/2, getHeight() - acceptHeight*2, acceptWidth, acceptHeight);
        accept.setFont(  new CustomFonts().font(70) );
        accept.setOpaque(false);
        accept.setBackground(null);
        accept.setContentAreaFilled(false);
        accept.setBorderPainted(false);
        accept.setHorizontalAlignment(SwingConstants.CENTER);
        accept.setForeground(Color.green);
        accept.addActionListener((ActionEvent e)->{
            UIManager.hideUIPanel("Options");
            MenuPanel.options.setEnabled(true);
            MenuPanel.playButton.setEnabled(true);
            MenuPanel.enable = true;

        });

        add(accept);
        add(difficulty);
        add(increase);
        add(decrease);
        add(chooseDifficulty);
        
    }






}
