package GameAliensAttack;

import java.awt.Point;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Iterator;

public class RigidBody {

    public static ArrayList<RigidBody> rigidBodiesCollection = new ArrayList<>(0);
    Iterator<RigidBody> rigidBodyIterator;

    double velocityVector[] = {0,0};
    double accelerationVector[] = {0,0};
    double mass = 1;
    BoxCollider boxCollider;
    Instant time = Instant.now();
    double chronometer = 0;
    boolean crashingPhysics = true;

    
    public RigidBody(BoxCollider boxCollider){
        rigidBodiesCollection.add(this);
        this.boxCollider = boxCollider;
    }

    public void giveForce(double x , double y){
        accelerationVector[0] = x/mass;
        accelerationVector[1] = y/mass;
    }

    private void crash(){

        rigidBodyIterator = rigidBodiesCollection.iterator();
        RigidBody temporalRigidBody;
        Point location = boxCollider.component.getLocation();

        while(rigidBodyIterator.hasNext()){
            temporalRigidBody = rigidBodyIterator.next();
            if(temporalRigidBody.boxCollider.isColliding(boxCollider) && temporalRigidBody.crashingPhysics ){
                if(Math.abs(temporalRigidBody.boxCollider.component.getBounds().getCenterX() - boxCollider.component.getBounds().getCenterX()) > 
                Math.abs(temporalRigidBody.boxCollider.component.getBounds().getCenterY() - boxCollider.component.getBounds().getCenterY())  ){
                    boxCollider.component.setLocation(location.x + (int)(velocityVector[0]*-1), location.y );
                }else{
                     boxCollider.component.setLocation(location.x , location.y + (int)(velocityVector[1]*-1));
                }
                if(Math.abs(temporalRigidBody.boxCollider.component.getBounds().getCenterX() - boxCollider.component.getBounds().getCenterX()) < 
                Math.abs(temporalRigidBody.boxCollider.component.getBounds().getCenterY() - boxCollider.component.getBounds().getCenterY())  ){
                    boxCollider.component.setLocation(location.x , location.y + (int)(velocityVector[1]*-1));
                }else{
                     boxCollider.component.setLocation(location.x + (int)(velocityVector[0]*-1), location.y );
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
