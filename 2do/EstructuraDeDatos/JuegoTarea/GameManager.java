package JuegoTarea;

import java.util.ArrayList;
import java.util.Iterator;

public class GameManager implements Runnable {

    ArrayList <Bullet> bullets = new ArrayList<>();
    ArrayList <Enemy> enemies = new ArrayList<>();
    Main main;
    Iterator <Enemy> enemiesIterator;
    Iterator<Bullet> bulletIterator;
    Player player;
    boolean flag = true;

    double timer = 0 ;



    public GameManager(Main main){
        this.main = main;
        this.player = main.player;

    }




    @Override
    public void run() {

        enemies.add(new Enemy(main));
        main.add(enemies.get(0));
        enemies.add(new Enemy(main,300, 300));
        main.add(enemies.get(1));


        while(true){
            //System.out.println(bullets.size());

            timer++;

                if(timer % 3 == 0)
                main.player.ChangeFrame();


            
            
            try {
                
                Thread.sleep(10);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            
            enemiesIterator = enemies.iterator();
            while(enemiesIterator.hasNext()){

                Enemy nextEnemy = enemiesIterator.next();
                //nextEnemy.boxCollider.refresBoxCollider();
                if(nextEnemy.boxCollider.isColliding(player.boxCollider)){

                    //System.out.println("is collaiding");
                    enemiesIterator.remove();
                    main.remove(nextEnemy);
                }

                bulletIterator = bullets.iterator();
                
                while(bulletIterator.hasNext()){

                    Bullet nexBullet = bulletIterator.next();

    
                    if(nextEnemy.boxCollider.isColliding(nexBullet.boxCollider)){
                        //System.out.println("bulletCollaiding");
                        flag = false;
                        nextEnemy.lifePoints--;
                        main.remove(nexBullet);
                        bulletIterator.remove();
                        
                        if(nextEnemy.lifePoints <= 0 ){

                            main.remove(nextEnemy);
                            enemiesIterator.remove();
                        }
                        flag = true;
                    }
                    
                }
            }
            
            //enemies.get(0).followPlayer();









        }

         
        }
    


}
