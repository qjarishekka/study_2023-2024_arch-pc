package GameAliensAttack.GameEngine;

import java.util.Iterator;

import GameAliensAttack.MainFrame;

public class GameEngine{
    public static Thread thread = new Thread();
    public static int counter = 0;
    public static boolean playing = true;
    public static Engine engine = new Engine();


    
    public static class Engine implements Runnable{
        @Override
        public void run() {


            while (playing) {

                Iterator<BoxCollider>   boxColliderIterator = BoxCollider.boxColliderCollection.iterator();
                Iterator<MonoBehavior>  monoBehaviorIterator = MonoBehavior.monoBehaviorsCollection.iterator();
                Iterator<Animator>      animatorIterator = Animator.animatorsCollection.iterator();
                Iterator<RigidBody>     rigidBodyIterator = RigidBody.rigidBodiesCollection.iterator();

                BoxCollider temporalBoxCollider;
                while(boxColliderIterator.hasNext()){
                    temporalBoxCollider = boxColliderIterator.next();
                    temporalBoxCollider.refresBoxCollider();
                }
                MonoBehavior temporalMonoBehavior;                
                while (monoBehaviorIterator.hasNext()) {
                    temporalMonoBehavior = monoBehaviorIterator.next();
                    if(MonoBehavior.objectInitialized)
                        temporalMonoBehavior.update();
                }
                
                Animator temporalAnimator;
                while(animatorIterator.hasNext()){
                    temporalAnimator = animatorIterator.next();
                    temporalAnimator.animate();
                }

                RigidBody temporalRigidBody;
                while(rigidBodyIterator.hasNext()){
                    temporalRigidBody = rigidBodyIterator.next();
                    temporalRigidBody.Update();
                }

                MonoBehavior.monoBehaviorsCollection.addAll(MonoBehavior.monoBehaviorsBuffer);
                Animator.animatorsCollection.addAll(Animator.animatorsBuffer);
                BoxCollider.boxColliderCollection.addAll(BoxCollider.boxColliderBuffer);
                RigidBody.rigidBodiesCollection.addAll(RigidBody.rigidBodiesBuffer);


                MainFrame.proxy.repaint();
                MainFrame.proxy.requestFocus();
                

            }
        }
    }



    public GameEngine(){
        
        thread = new Thread(engine);
        thread.start();

    }

    static public void pause(){
        try{
            thread.interrupt();
            playing = false;
        }catch(Exception e){
            //e.printStackTrace();
        }
    }

    static public void play(){
        playing = true;
        thread = new Thread(engine);
        thread.start();

    }

    static public void sleep(int time){
        try {
            thread.sleep(time);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    
}
