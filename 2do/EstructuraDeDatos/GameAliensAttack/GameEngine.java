package GameAliensAttack;

import java.util.Iterator;

public class GameEngine{
    Thread thread;


    
    class Engine implements Runnable{
        @Override
        public void run() {


            while (true) {

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
        Engine engine = new Engine();
        thread = new Thread(engine);
        thread.start();

    }

    
}
