package GameAliensAttack.GameEngine;

import GameAliensAttack.MainFrame;
import GameAliensAttack.Panels.GamePanel;
import GameAliensAttack.Panels.MenuPanel;
import GameAliensAttack.Panels.PausePanel;

public class SceneManager {

    public GamePanel gamePanel;
    public MenuPanel menuPanel;
    public PausePanel pausePanel;


    public SceneManager(){
        gamePanel = new GamePanel();
        menuPanel = new MenuPanel(this);
        pausePanel = new PausePanel(this);
    }



    public void setScene(String sceneName){

        if(sceneName.equals("Menu")){
            MainFrame.proxy.remove(gamePanel);
            MainFrame.proxy.add(menuPanel);
        }
        if(sceneName.equals("Game")){
            MainFrame.proxy.remove(menuPanel);
            MainFrame.proxy.remove(pausePanel);
            MainFrame.proxy.add(gamePanel);
            MainFrame.proxy.repaint();
        }
        if(sceneName.equals("Pause")){
            GameEngine.pause();
            MainFrame.proxy.add(pausePanel,0);
            MainFrame.proxy.repaint();
            
        }
    
    }

    
}
