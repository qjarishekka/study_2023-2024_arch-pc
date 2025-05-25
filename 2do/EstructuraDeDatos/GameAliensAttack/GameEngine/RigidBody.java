package GameAliensAttack.GameEngine;

import java.awt.Point;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;
public class RigidBody {

    public static ArrayList<RigidBody> rigidBodiesCollection = new ArrayList<>(0);
    //public static List<RigidBody> rigidBodiesCollection = Collections.synchronizedList(new ArrayList<RigidBody>(0));
    public static List<RigidBody> toAddBuffer = Collections.synchronizedList(new ArrayList<>());
    public static List<RigidBody> toRemoveBuffer = Collections.synchronizedList(new ArrayList<>());
    
    Iterator<RigidBody> rigidBodyIterator;

    double velocityVector[] = {0,0};
    double accelerationVector[] = {0,0};
    double mass = 1;
    BoxCollider boxCollider;
    Instant time = Instant.now();
    double chronometer = 0;
    public boolean crashingPhysics = true;

    
    public RigidBody(BoxCollider boxCollider){
        safeAdd(this);
        //rigidBodiesCollection.add(this);
        this.boxCollider = boxCollider;
    }

    public void giveForce(double x , double y){
        accelerationVector[0] = x/mass;
        accelerationVector[1] = y/mass;
    }

    public static void safeAdd(RigidBody obj) {
        toAddBuffer.add(obj);
    }

    public static void safeRemove(RigidBody obj) {
        toRemoveBuffer.add(obj);
    }

    private void crash(){
        for (RigidBody other : rigidBodiesCollection) {
            if (other == this || !other.crashingPhysics) continue;

            if (boxCollider.isColliding(other.boxCollider)) {
                Point location = boxCollider.component.getLocation();

                double deltaX = other.boxCollider.component.getBounds().getCenterX() - boxCollider.component.getBounds().getCenterX();
                double deltaY = other.boxCollider.component.getBounds().getCenterY() - boxCollider.component.getBounds().getCenterY();

                if (Math.abs(deltaX) > Math.abs(deltaY)) {
                    // Colisión horizontal
                    boxCollider.component.setLocation(location.x - (int)velocityVector[0], location.y);
                    velocityVector[0] = 0; // O rebote: velocityVector[0] *= -1;
                } else {
                    // Colisión vertical
                    boxCollider.component.setLocation(location.x, location.y - (int)velocityVector[1]);
                    velocityVector[1] = 0; // O rebote: velocityVector[1] *= -1;
                }
            }
        }
    }


    public void setPosition(){
        
        if(chronometer >= 0.01){

            double x = boxCollider.component.getBounds().getX();
            double y = boxCollider.component.getBounds().getY();

            velocityVector[0] = velocityVector[0] + accelerationVector[0]*0.01;
            velocityVector[1] = velocityVector[1] + accelerationVector[1]*0.01;
            boxCollider.component.setLocation((int)(x+velocityVector[0]) ,(int)(y+velocityVector[1]));
            time = Instant.now();
        }

        chronometer = Duration.between(time, Instant.now()).getNano()/1e9;
    }

    public double getVelocity(){
        return Math.sqrt(velocityVector[0]*velocityVector[0] + velocityVector[1]*velocityVector[1] );
    }

    public void setVelocity(double x , double y){
        velocityVector[0] = x;
        velocityVector[1] = y;
    }
    public void setAcceleration(double x , double y){
        accelerationVector[0] = x;
        accelerationVector[1] = y;
    }


    void Update(){
        crash();
        setPosition();
    }



}
