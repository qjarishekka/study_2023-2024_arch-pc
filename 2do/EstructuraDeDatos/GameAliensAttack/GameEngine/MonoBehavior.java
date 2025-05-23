package GameAliensAttack.GameEngine;

import java.util.ArrayList;

import javax.swing.JLabel;

public abstract class MonoBehavior extends JLabel{
    
    public static ArrayList<MonoBehavior> monoBehaviorsCollection = new ArrayList<>();
    public static ArrayList<MonoBehavior> monoBehaviorsBuffer = new ArrayList<>();
    public BoxCollider boxCollider = null;
    public RigidBody rigidBody = null;
    public static boolean objectInitialized = false;


    public MonoBehavior(){

        monoBehaviorsBuffer.add(this);
        objectInitialized = true;
        //GameEngine.play();
    }

    public abstract void update();

}
