package GameAliensAttack.GameEngine;

import java.util.ArrayList;

import javax.swing.JPanel;

public class Scene extends JPanel{
    public static ArrayList<Scene> scenesCollection = new ArrayList<>();
    static int counter = 0;
    String tag;


    public Scene(){
        scenesCollection.add(this);
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
