package GameAliensAttack.GameEngine;

import java.util.ArrayList;

import javax.swing.JPanel;

public class UIPanel extends JPanel {
    public static ArrayList<UIPanel> UICollection = new ArrayList<>();
    static int counter = 0;
    String tag;

    public UIPanel(){
        UICollection.add(this);
        counter++;
        tag = Integer.toString(counter);
    
    }

    public void setTag(String newTag){
        tag = newTag;
    }
    public String getTag(){
        return tag;
    }


}

