package GameAliensAttack;

import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
import GameAliensAttack.src.fonts.CustomFonts;

public class GamePanel extends JPanel {

    

    public GamePanel(){

        setLayout(null);
        setBounds(0,0, MainFrame.width, MainFrame.height);

        JLabel currentPoints = new JLabel();
        currentPoints.setBounds(MainFrame.width/2 - MainFrame.width*7/100, 10, MainFrame.width*15/100, MainFrame.width*15/100);
        currentPoints.setText("Score: 000");
        currentPoints.setFont(new CustomFonts().font(40));
        currentPoints.setForeground(Color.green);
        currentPoints.setBackground(Color.WHITE);

        JLabel lifePoints = new JLabel();

        lifePoints.setBounds(MainFrame.width - MainFrame.width*20/100 - 10  , 10, MainFrame.width*20/100, MainFrame.height*20/100);
        lifePoints.setText("life points: 3");
        lifePoints.setFont(new CustomFonts().font(40));
        lifePoints.setForeground(Color.green);
        lifePoints.setBackground(Color.WHITE);

        JLabel backGround = new JLabel();
        backGround.setBounds(getBounds());
        backGround.setIcon(new ImageIcon(MainFrame.backgroundImage.getScaledInstance(getWidth(), getHeight(), 0)));
        Player player = new Player();
        Enemy enemy = new Enemy();
        enemy.setTargetedEntity(player);
        
        add(enemy,0);
        add(player);
        add(currentPoints);
        add(lifePoints);
        add(backGround);

    }

    
}
