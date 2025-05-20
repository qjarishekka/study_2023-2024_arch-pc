package GameAliensAttack;

import java.util.Iterator;

public class GameEngine{
    public static Thread thread;
    public static int counter = 0;
    public static boolean playing = true;
    public static Engine engine = new Engine();


    
    public static class Engine implements Runnable{
        @Override
        public void run() {


            while (playing) {
                

                Iterator<BoxCollider>   boxColliderInterator = BoxCollider.boxColliderCollection.iterator();
                Iterator<MonoBehavior>  monoBehaviorIterator = MonoBehavior.monoBehaviorsCollection.iterator();
                Iterator<Animator>      animatorIterator = Animator.animatorsCollection.iterator();
                Iterator<RigidBody>     rigidBodyIterator = RigidBody.rigidBodiesCollection.iterator();

                BoxCollider temporalBoxCollider;
                while(boxColliderInterator.hasNext()){
                    temporalBoxCollider = boxColliderInterator.next();
                    temporalBoxCollider.refresBoxCollider();
                }

                MonoBehavior temporalMonoBehavior;
                while (monoBehaviorIterator.hasNext()) {
                    temporalMonoBehavior = monoBehaviorIterator.next();
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
            playing = false;
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    static public void play(){
        playing = true;
        thread = new Thread(engine);
        thread.start();

    }    
}
