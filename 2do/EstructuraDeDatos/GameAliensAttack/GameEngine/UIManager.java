package GameAliensAttack.GameEngine;

import java.util.ArrayList;

import javax.swing.JPanel;

import GameAliensAttack.MainFrame;
import GameAliensAttack.UI.PausePanel;

public class UIManager extends JPanel{

    public PausePanel pausePanel = new PausePanel();

    public UIManager(){
        
    }

    public static void showUIPanel(String panelName){
        for(UIPanel panel : UIPanel.UICollection ){
            if(panel.getTag().matches(panelName)){
                MainFrame.proxy.add(panel,0);
            }
        }
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();

    }

    public static void hideUIPanel(String panelName){
        for(UIPanel panel : UIPanel.UICollection ){
            if(panel.getTag().matches(panelName)){
                MainFrame.proxy.remove(panel);
            }
        }
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();
    }
    
    public static void addToPanelByTag(MonoBehavior object , String panelName){
        for(UIPanel panel : UIPanel.UICollection ){
            if(panel.getTag().matches(panelName)){
                panel.add(object,0);
            }
        }
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();

    }
    public static void removeToPanelByTag(MonoBehavior object , String panelName){
        for(UIPanel panel : UIPanel.UICollection ){
            if(panel.getTag().matches(panelName)){
                panel.remove(object);
            }
        }
        MainFrame.proxy.revalidate();
        MainFrame.proxy.repaint();

    }

    public static UIPanel getPanelByTag(String panelName){
        for(UIPanel panel : UIPanel.UICollection ){
            if(panel.getTag().equals(panelName)){
                return panel;
            }
        }
        return null;
    }

    
}
