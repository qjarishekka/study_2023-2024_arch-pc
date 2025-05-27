package GameAliensAttack.Scenes;

import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

import GameAliensAttack.MainFrame;
import GameAliensAttack.Entities.Enemy;
import GameAliensAttack.Entities.Player;
import GameAliensAttack.GameEngine.Scene;
import GameAliensAttack.src.fonts.CustomFonts;

public class GamePanel extends Scene {

    public static JLabel currentPoints = new JLabel();
    public static JLabel lifePoints = new JLabel();

    public GamePanel(){

        setLayout(null);
        setBounds(0,0, MainFrame.width, MainFrame.height);
        setTag("Game");

        
        currentPoints.setBounds(MainFrame.width/2 - MainFrame.width*7/100, 10, MainFrame.width*15/100, MainFrame.width*15/100);
        currentPoints.setText("Score: 000");
        currentPoints.setFont(new CustomFonts().font(40));
        currentPoints.setForeground(Color.green);
        currentPoints.setBackground(Color.WHITE);

        

        lifePoints.setBounds(MainFrame.width - MainFrame.width*20/100 - 10  , 10, MainFrame.width*20/100, MainFrame.height*20/100);
        lifePoints.setText("life points: 3");
        lifePoints.setFont(new CustomFonts().font(40));
        lifePoints.setForeground(Color.green);
        lifePoints.setBackground(Color.WHITE);

        JLabel backGround = new JLabel();
        backGround.setBounds(getBounds());
        backGround.setIcon(new ImageIcon(MainFrame.backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));

        
        add(currentPoints);
        add(lifePoints);
        add(backGround);

    }

    static public void setScore(int score){
        String textScore = Integer.toString(score);
        String newScore = "Score: " + textScore;  
        currentPoints.setText(newScore);
    }

    static public void setLife(int life){
        String textLife = Integer.toString(life);
        String newLife = "life points: " + textLife;
        lifePoints.setText(newLife);
    }

    
}
