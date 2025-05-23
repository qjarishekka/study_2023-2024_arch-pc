package GameAliensAttack.GameEngine;
import java.util.ArrayList;


public class BoxCollider {
    
    int x, y , dx , dy;
    MonoBehavior component;
    @SuppressWarnings({ "rawtypes", "unchecked" })
    public static ArrayList<BoxCollider> boxColliderCollection = new ArrayList(1);
    public static ArrayList<BoxCollider> boxColliderBuffer = new ArrayList(1);
    
    
    public BoxCollider(MonoBehavior component){
        boxColliderBuffer.add(this);
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

        double x = component.getBounds().getCenterX();
        double y = component.getBounds().getCenterY();
        double dx = anotherCollider.component.getBounds().getCenterX() - x;
        double dy = anotherCollider.component.getBounds().getCenterY() - y;

        double dinstance = Math.sqrt(dx * dx + dy*dy);

        if(dinstance < component.getBounds().height*2 ){


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

        }

        
            return false;

        /* if(   x <= anotherCollider.x && anotherCollider.x <= dx    &&     y <= anotherCollider.y && anotherCollider.y <= dy  ){
            return true;
        }else if( x  <= anotherCollider.dx && anotherCollider.dx <= dx &&   y <= anotherCollider.y && anotherCollider.y <= dy ){
            return true;
        }else if(x <= anotherCollider.x && anotherCollider.x <= dx &&   y <= anotherCollider.dy && anotherCollider.dy <= dy){
            return true;
        }else if( x <= anotherCollider.dx && anotherCollider.dx <= dx && y <= anotherCollider.dy && anotherCollider.dy <= dy  ){
            return true;
        }else if( anotherCollider.x <= x && x <= anotherCollider.dx && anotherCollider.y <= y && y <= anotherCollider.dy && anotherCollider.x <= dx && dx <= anotherCollider.dx && anotherCollider.y <= dy && dy <= anotherCollider.dy){
            return true;
        }else if( x <= anotherCollider.x && anotherCollider.x <= dx && y <= anotherCollider.y && anotherCollider.y <=dy && x <= anotherCollider.dx && anotherCollider.dx <= dx && y <= anotherCollider.dy && anotherCollider.dy <= dy  ){
            return true;
        }     */

    }
    


}
