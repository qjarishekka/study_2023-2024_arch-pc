package GameAliensAttack;

import java.awt.event.KeyEvent;

import GameAliensAttack.Entities.Player;
import GameAliensAttack.GameEngine.*;
import GameAliensAttack.Scenes.*;
import GameAliensAttack.UI.*;

public class GameManager extends MonoBehavior {

    
    public MenuPanel menuPanel = new MenuPanel();
    public GamePanel gamePanel = new GamePanel();
    public PausePanel pausePanel = new PausePanel();
    boolean paused = false;


public GameManager() {
        SceneManager.setScene("Menu");

        // Hilo separado que siempre escucha Escape
    new Thread(() -> {
        while (true) {
            if (Input.isKeyJustPressed(KeyEvent.VK_ESCAPE)) {
                if (!paused && !SceneManager.currentScene.equals("Menu")) {
                    UIManager.showUIPanel("Pause");
                    GameEngine.pause();
                } else {
                    UIManager.hideUIPanel("Pause");
                    GameEngine.play();
                }
                    paused = !paused;
                    try {
                        Thread.sleep(150); 
                    } catch (InterruptedException e) {}
                }
            }
        }).start();
    }



    @Override
    public void update() {
        
        if(Player.proxy.life <= 0){
            System.out.println("you lose");
        }

    }

    public void showGameOver(){
        
    }


}

