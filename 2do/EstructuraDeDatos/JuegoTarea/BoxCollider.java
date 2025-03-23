package JuegoTarea;

import java.awt.Component;

import javax.swing.JLabel;

public class BoxCollider {

    int x, y , dx , dy;
    
    
    public BoxCollider(Component component){

        x = component.getX();
        y = component.getY();
        dx = component.getWidth() + x;
        dy = component.getHeight() + y;


    }

    public void reduceCollaider(int percent ){


    }

    public Boolean isColliding(BoxCollider anotherCollider ){

        



        return true;
    }
}
