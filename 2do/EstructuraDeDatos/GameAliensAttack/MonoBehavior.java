package GameAliensAttack;

import java.util.ArrayList;

import javax.swing.JLabel;

public abstract class MonoBehavior extends JLabel{
    
    public static ArrayList<MonoBehavior> monoBehaviorsCollection = new ArrayList<>();

    public MonoBehavior(){
        monoBehaviorsCollection.add(this);
    }

    public abstract void update();

}
