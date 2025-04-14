package pathfinder;

import javax.swing.JButton;
import javax.swing.JFrame;

public class Main extends JFrame{

    Main(){
        super("Heuristic");
        setSize(30*PathPanel.CELL_SIZE + 100,30 * PathPanel.CELL_SIZE);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);

        PathPanel pathPanel = new PathPanel(getWidth(), getHeight());
        pathPanel.setLocation(0 , 0);
        add(pathPanel);

        JButton genButton = new JButton("gen");
        genButton.setBounds(getWidth() - 100 , 0,  100 , 30);
        genButton.setVisible(true);
        
        genButton.addActionListener(e->{
            pathPanel.gen();
            pathPanel.repaint();
        });

        add(genButton);







        setVisible(true);

    }
    



    public static void main(String[] args){
        new Main();
    }

}
