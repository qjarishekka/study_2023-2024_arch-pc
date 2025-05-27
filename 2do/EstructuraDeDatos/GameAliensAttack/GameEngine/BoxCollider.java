package GameAliensAttack.GameEngine;
import java.util.*;


public class BoxCollider {
    
    int x, y , dx , dy;
    MonoBehavior component;
    //@SuppressWarnings({ "rawtypes", "unchecked" })
    public static ArrayList<BoxCollider> boxColliderCollection = new ArrayList<>();
    //public static List<BoxCollider> boxColliderCollection = Collections.synchronizedList(new ArrayList<BoxCollider>(1));
    public static List<BoxCollider> toAddBuffer = Collections.synchronizedList(new ArrayList<>());
    public static List<BoxCollider> toRemoveBuffer = Collections.synchronizedList(new ArrayList<>());
    public MonoBehavior objectHitted = null;
    
    public BoxCollider(MonoBehavior component){
        safeAdd(this);
        //boxColliderCollection.add(this);
        this.component = component;
        this.component.boxCollider = this;
        x = component.getX();
        y = component.getY();
        dx = component.getWidth() + x;
        dy = component.getHeight() + y;

    }

    public void refresBoxCollider(){
        x = component.getX();
        y = component.getY();
        dx = component.getWidth() + x;
        dy = component.getHeight() + y;
    }

    public static void safeAdd(BoxCollider obj) {
        toAddBuffer.add(obj);
    }

    public static void safeRemove(BoxCollider obj) {
        toRemoveBuffer.add(obj);
    }
    
    public boolean isColliding(BoxCollider other) {

        this.refresBoxCollider();
        other.refresBoxCollider();

        boolean collisionX = this.x <= other.dx && this.dx >= other.x;
        boolean collisionY = this.y <= other.dy && this.dy >= other.y;
        return collisionX && collisionY;

    }


    public boolean isCollidingByTag(String tag){
        synchronized(boxColliderCollection){
            for(BoxCollider bc : boxColliderCollection){
                if (bc != this && isColliding(bc) && tag.equals(bc.component.tag)) {
                    objectHitted = bc.component;
                    return true;
                }
            }
        }
        return false;
    }

    public MonoBehavior getObjectHitted(){
        synchronized(boxColliderCollection){
            for(BoxCollider bc : boxColliderCollection){
                
                if(isColliding(bc)){
                    return bc.component;
                }
                
            }

            return null;
        }

    }

    public void setOffset(int offset){
        x -= offset;
        y -= offset;
        dx -= offset;
        dy -= offset;
    }


}
