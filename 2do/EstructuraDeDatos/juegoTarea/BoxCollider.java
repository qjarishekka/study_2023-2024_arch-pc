package juegoTarea;

import java.awt.Component;


public class BoxCollider {
    
    int x, y , dx , dy;
    Component component;
    
    
    public BoxCollider(Component component){

        this.component = component;
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
