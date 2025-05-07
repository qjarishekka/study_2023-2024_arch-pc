package GameAliensAttack;

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JPanel;

public class MenuPanel extends JPanel {

    public MenuPanel() {

        setBounds(0,0, MainFrame.width, MainFrame.height);
        //setBackground(Color.green);


        

        JButton playButton = new JButton();
        playButton.setBounds(0,0,300,400);
        playButton.setLocation(0,0);
        //JButton exitButton = new JButton("exit");



        add(playButton);
        //add(exitButton);
        setVisible(true);
    }

}
