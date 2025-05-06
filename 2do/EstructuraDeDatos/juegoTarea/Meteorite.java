package juegoTarea;


import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.geom.AffineTransform;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class Meteorite  extends JLabel{

    static final float SIZE_CONSTANT = 0.1f;
    BoxCollider boxCollider = new BoxCollider(this);
    static final String path = "src//meteorite.png";
    static final Image meteoriteImage = new ImageIcon(path).getImage();

    char value = '_';
    double angle = 0;
    int meteoriteSize;
    int x , y = 0;


    
    public Meteorite(int screenHeight){
        meteoriteSize = (int)(screenHeight*SIZE_CONSTANT);

        setBounds(x  , y , meteoriteSize , meteoriteSize);
        setOpaque(true);
        setBackground(new Color(0,0,0,0));
        setIcon(new ImageIcon(meteoriteImage.getScaledInstance(meteoriteSize, meteoriteSize, 0)));
        genAngle();

    }

    @Override
    public void paint(Graphics g){
        Graphics2D g2 = (Graphics2D)g;
        AffineTransform at = g2.getTransform();
        at.rotate(angle,getWidth()/2,getHeight()/2);
        g2.setTransform(at);
        super.paint(g2);

    }

    public void genAngle(){
        Random rng = new Random();
        angle = rng.nextDouble() + rng.nextInt(2) -1;
    }
    public char getValue(){
        return value;
    }

}
