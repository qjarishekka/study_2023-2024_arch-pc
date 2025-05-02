package juegoTareaFinal;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;

import javax.swing.JComponent;
import javax.swing.JLabel;

public class Field extends JComponent{
    
    char field[][];
    Point playerPosition;

    public Field(Player player , MainFrame mainFrame){

        field = new char[mainFrame.getWidth() / (mainFrame.gameManager.enemySize +6) ][ mainFrame.getHeight()  / (mainFrame.gameManager.enemySize +6) ];





    }





}
