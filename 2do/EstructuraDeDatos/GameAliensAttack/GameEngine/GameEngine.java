package GameAliensAttack.GameEngine;

import GameAliensAttack.MainFrame;

public class GameEngine {
    public static Thread thread = new Thread();
    public static boolean playing = true;
    public static Engine engine = new Engine();

    public static class Engine implements Runnable {
        @Override
        public void run() {
            while (true) {
                if (playing) {
                    synchronized (BoxCollider.boxColliderCollection) {
                        for (BoxCollider bc : BoxCollider.boxColliderCollection) {
                            bc.refresBoxCollider();
                        }
                        BoxCollider.boxColliderCollection.addAll(BoxCollider.toAddBuffer);
                        BoxCollider.toAddBuffer.clear();
                        BoxCollider.boxColliderCollection.removeAll(BoxCollider.toRemoveBuffer);
                        BoxCollider.toRemoveBuffer.clear();
                    }

                    synchronized (Animator.animatorsCollection) {
                        for (Animator ani : Animator.animatorsCollection) {
                            ani.animate();
                        }
                        Animator.animatorsCollection.addAll(Animator.toAddBuffer);
                        Animator.toAddBuffer.clear();
                        Animator.animatorsCollection.removeAll(Animator.toRemoveBuffer);
                        Animator.toRemoveBuffer.clear();
                    }

                    synchronized (RigidBody.rigidBodiesCollection) {
                        for (RigidBody rb : RigidBody.rigidBodiesCollection) {
                            rb.Update();
                        }
                        RigidBody.rigidBodiesCollection.addAll(RigidBody.toAddBuffer);
                        RigidBody.toAddBuffer.clear();
                        RigidBody.rigidBodiesCollection.removeAll(RigidBody.toRemoveBuffer);
                        RigidBody.toRemoveBuffer.clear();
                    }

                    synchronized (MonoBehavior.monoBehaviorsCollection) {
                        for (MonoBehavior mb : MonoBehavior.monoBehaviorsCollection) {
                            mb.update();
                        }
                        MonoBehavior.monoBehaviorsCollection.addAll(MonoBehavior.toAddBuffer);
                        MonoBehavior.toAddBuffer.clear();
                        MonoBehavior.monoBehaviorsCollection.removeAll(MonoBehavior.toRemoveBuffer);
                        MonoBehavior.toRemoveBuffer.clear();

                    }
                    
                }
                //MainFrame.proxy.requestFocus();
                Input.endFrame();
                MainFrame.proxy.repaint();
                

                try {
                    Thread.sleep(16);
                } catch (InterruptedException e) {
                    break;
                }
            }
        }
    }

    public GameEngine() {
        thread = new Thread(engine);
        thread.start();
    }

    public static void pause() {
        playing = false;
    }

    public static void play() {
        playing = true;
    }

    public static void removeObject(MonoBehavior object) {
        MonoBehavior.safeRemove(object);
        RigidBody.safeRemove(object.rigidBody);
        Animator.safeRemove(object.animator);
        BoxCollider.safeRemove(object.boxCollider);
    }

    public static boolean isThereObjectByTag(String tag){
        synchronized(MonoBehavior.monoBehaviorsCollection){

            for(MonoBehavior temp : MonoBehavior.monoBehaviorsCollection){
                if(temp.tag.equals(tag)){
                    return true;
                }
            }

        }

        return false;
    }

    public static void removeObjectsByTag(String tag){
        for(MonoBehavior mb : MonoBehavior.monoBehaviorsCollection){
            if(mb.tag.equals(tag)){
                
                RigidBody.safeRemove(mb.rigidBody);
                Animator.safeRemove(mb.animator);
                BoxCollider.safeRemove(mb.boxCollider);
                MonoBehavior.safeRemove(mb);
            }
        }
    }

    public static void removeAll(){
        MonoBehavior.toRemoveBuffer.addAll(MonoBehavior.monoBehaviorsCollection);
        BoxCollider.toRemoveBuffer.addAll(BoxCollider.boxColliderCollection);
        RigidBody.toRemoveBuffer.addAll(RigidBody.rigidBodiesCollection);
        Animator.toRemoveBuffer.addAll(Animator.animatorsCollection);
    }

/*     public static MonoBehavior[] findObjectByTag(String ){

    } */
}
