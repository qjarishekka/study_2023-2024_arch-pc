package pathfinderClase;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main  extends JFrame {

    Main(){
        super("Heuristic");
        setSize(30*PathPanel.CELL_SIZE + 100, 30*PathPanel.CELL_SIZE);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);

        PathPanel pathPanel = new PathPanel(getWidth()-100, getHeight());
        pathPanel.setLocation(0, 0);
        add(pathPanel);

        JButton genButton = new JButton("GEN");
        genButton.setBounds(getWidth() - 100, 0, 100, 30);
        add(genButton);
        genButton.addActionListener(e -> {
            pathPanel.gen();
            pathPanel.repaint();
        });

        JButton pathButton = new JButton("Find path");
        pathButton.setBounds(getWidth() - 100, 30, 100, 30);
        add(pathButton);
        pathButton.addActionListener(e -> {
            pathPanel.findPath();
            pathPanel.repaint();
        });



        setVisible(true);
        new Thread(pathPanel).start();
    }

    public static void main(String[] args) {
        new Main();

    }

}