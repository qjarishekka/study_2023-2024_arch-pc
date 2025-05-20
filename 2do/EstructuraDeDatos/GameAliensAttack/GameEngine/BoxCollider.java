package GameAliensAttack.GameEngine;
import java.util.ArrayList;


public class BoxCollider {
    
    int x, y , dx , dy;
    MonoBehavior component;
    @SuppressWarnings({ "rawtypes", "unchecked" })
    public static ArrayList<BoxCollider> boxColliderCollection = new ArrayList(1);
    
    
    public BoxCollider(MonoBehavior component){
        boxColliderCollection.add(this);
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
    
    public Boolean isColliding(BoxCollider anotherCollider ){

        if(   x < anotherCollider.x && anotherCollider.x < dx    &&     y < anotherCollider.y && anotherCollider.y < dy  ){
            return true;
        }else if( x  < anotherCollider.dx && anotherCollider.dx < dx &&   y < anotherCollider.y && anotherCollider.y < dy ){
            return true;
        }else if(x < anotherCollider.x && anotherCollider.x < dx &&   y < anotherCollider.dy && anotherCollider.dy < dy){
            return true;
        }else if( x < anotherCollider.dx && anotherCollider.dx < dx && y < anotherCollider.dy && anotherCollider.dy < dy  ){
            return true;
        }else if( anotherCollider.x < x && x < anotherCollider.dx && anotherCollider.y < y && y < anotherCollider.dy && anotherCollider.x < dx && dx < anotherCollider.dx && anotherCollider.y < dy && dy < anotherCollider.dy){
            return true;
        }else if( x < anotherCollider.x && anotherCollider.x < dx && y < anotherCollider.y && anotherCollider.y <dy && x < anotherCollider.dx && anotherCollider.dx < dx && y < anotherCollider.dy && anotherCollider.dy < dy  ){
            return true;
        }
            return false;
    }
    


}
