package JuegoTarea;

import java.util.ArrayList;
import java.util.Iterator;

public class GameManager implements Runnable {

    ArrayList <Bullet> bullets = new ArrayList<>();
    ArrayList <Enemy> enemies = new ArrayList<>();
    Main main;
    Iterator <Enemy> enemiesIterator;


    public GameManager(Main main){
        this.main = main;
    }

    @Override
    public void run() {
        while(true){

            enemiesIterator = enemies.iterator();
            
            while(enemiesIterator.hasNext()){
                Enemy nextEnemy = enemiesIterator.next();           
            }
            

        }
    }
    


}
