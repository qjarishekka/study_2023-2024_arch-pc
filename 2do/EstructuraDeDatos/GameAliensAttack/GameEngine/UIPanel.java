package GameAliensAttack.GameEngine;

import java.awt.Color;
import java.util.ArrayList;

import javax.swing.JPanel;

import GameAliensAttack.MainFrame;

public class UIPanel extends JPanel {
    public static ArrayList<UIPanel> UICollection = new ArrayList<>();
    static int counter = 0;
    String tag;

    public UIPanel(){
        UICollection.add(this);
        counter++;
        tag = Integer.toString(counter);
        setLayout(null);
        setBounds(0, 0, MainFrame.width, MainFrame.height);
        setBackground(new Color(0, 0, 0, 100));   
    
    }

    public void setTag(String newTag){
        tag = newTag;
    }
    public String getTag(){
        return tag;
    }


}

