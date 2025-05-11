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


            }
        }
    }


    public GameEngine(){
        Engine engine = new Engine();
        thread = new Thread(engine);
        thread.start();

    }

    
}
