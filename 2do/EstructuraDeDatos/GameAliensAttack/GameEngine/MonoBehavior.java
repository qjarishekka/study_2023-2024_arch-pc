package GameAliensAttack.GameEngine;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import javax.swing.JLabel;

public abstract class MonoBehavior extends JLabel {

    public static List<MonoBehavior> monoBehaviorsCollection = Collections.synchronizedList(new ArrayList<>());
    public static List<MonoBehavior> toAddBuffer = Collections.synchronizedList(new ArrayList<>());
    public static List<MonoBehavior> toRemoveBuffer = Collections.synchronizedList(new ArrayList<>());

    public BoxCollider boxCollider = null;
    public RigidBody rigidBody = null;
    public Animator animator = null;
    public static boolean objectInitialized = false;
    static int counter = 0;
    String tag = "";

    public MonoBehavior() {
        safeAdd(this);
        tag = Integer.toString(counter);
        counter++;
        objectInitialized = true;

    }

    public static void safeAdd(MonoBehavior obj) {
        toAddBuffer.add(obj);
    }

    public static void safeRemove(MonoBehavior obj) {
        toRemoveBuffer.add(obj);
    }
    public void setTag(String tag){
        this.tag = tag;
    }

    public abstract void update();
} 
