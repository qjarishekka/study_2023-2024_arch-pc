package GameAliensAttack;
import java.awt.*;  
import java.awt.event.*;  
import javax.swing.*;  

public class EjemploPanelConEvento {  
    EjemploPanelConEvento() {  
        // Crear el marco principal
        JFrame frame = new JFrame("Ejemplo de Evento en JPanel");    

        // Crear el panel
        JPanel panel = new JPanel();  
        panel.setBounds(50, 50, 300, 300);    
        panel.setBackground(Color.LIGHT_GRAY);  

        // Crear el botón
        JButton boton = new JButton("Cambiar Color");  
        boton.setBounds(0,0,100,400);

        // Añadir el ActionListener para cambiar el color del panel
        boton.addActionListener(new ActionListener() {  
            public void actionPerformed(ActionEvent e) {  
                panel.setBackground(Color.ORANGE);  
            }  
        });  

        // Añadir el botón al panel y el panel al marco
        panel.add(boton);  
        frame.add(panel);  

        // Configurar el marco
        frame.setSize(400, 400);    
        frame.setLayout(null);    
        frame.setVisible(true);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }  

    public static void main(String[] args) {  
        new EjemploPanelConEvento();  
    }  
}
