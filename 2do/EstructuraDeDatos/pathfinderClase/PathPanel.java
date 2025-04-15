package pathfinderClase;

import javax.swing.*; 
import java.awt.*; 
import java.awt.event.MouseEvent; 
import java.awt.event.MouseListener; 
import java.util.ArrayList; 
import java.util.Random; 
 
public class PathPanel extends JComponent implements MouseListener, Runnable { 
    static final int CELL_SIZE = 30; 
    char [][] field; 
    Point start = new Point(0, 0), finish = new Point(0, 0); 
 
 
 
    class Path{ 
        ArrayList<Point> steps; 
        Path(){ 
            steps = new ArrayList<>(20); 
        } 
    } 
 
    Path currentPath = new Path(); 
    boolean searching = false; 
 
    PathPanel(int W, int H){ 
        setSize(W, H); 
        field = new char[W/CELL_SIZE][H/CELL_SIZE]; // 10 пикселей - клетка 
        gen(); 
        addMouseListener(this); 
    } 
 
    void gen(){ 
        Random rng = new Random(); 
        for(int i = 0; i < field.length; i++) 
            for(int j = 0; j < field[i].length; j++) { 
                int rnd = rng.nextInt(100); 
                if(rnd < 70){ 
                    field[i][j] = '_'; 
                } else { 
                    field[i][j] = '0'; 
                } 
            } 
    } 
    int [][] matrix; 
    void findPath(){ 
        searching = true; 
        currentPath = new Path(); 
        Path path = new Path(); 
 
        matrix = new int[field.length][field[0].length]; 
        for (int i = 0; i < matrix.length; i++) 
            for (int j = 0; j < matrix[i].length; j++) 
                matrix[i][j] = field[i][j] == '0' ? -2 : -1; 
 
 
        matrix[start.y][start.x] = 0; 
        boolean fl = true; 
        while (fl && matrix[finish.y][finish.x] < 0) { 
            fl = false; 
            // пересчитаем матрицу 
            for (int i = 0; i < matrix.length; i++) { 
                for (int j = 0; j < matrix[i].length; j++) { 
                    if (matrix[i][j] == -1 && j > 0 && matrix[i][j - 1] >= 0) { 
                        matrix[i][j] = matrix[i][j - 1] + 1; 
                        fl = true; 
                        sleep(1); 
                    } 
                    if (matrix[i][j] == -1 && i > 0 && matrix[i - 1][j] >= 0) { 
                        matrix[i][j] = matrix[i - 1][j] + 1; 
                        fl = true; 
                        sleep(1); 
                    } 
                    if (matrix[i][j] == -1 && j < matrix[i].length - 1 && matrix[i][j + 1] >= 0) { 
                        matrix[i][j] = matrix[i][j + 1] + 1; 
                        fl = true; 
                        sleep(1); 
                    } 
                    if (matrix[i][j] == -1 && i < matrix.length - 1 && matrix[i + 1][j] >= 0) { 
                        matrix[i][j] = matrix[i + 1][j] + 1; 
                        fl = true; 
                        sleep(1); 
                    } 
 
                } 
                //repaint(); 
                //System.out.println("find Sleep"); 
 
 
            } 
 
        } 
 
        if(matrix[finish.y][finish.x] < 0) {// no way; 
            searching = false; 
            return; 
        } 
        Point current = new Point(finish.x, finish.y); 
        while(current.x != start.x || current.y != start.y){ 
            if(current.x > 0 && matrix[current.y][current.x - 1] >= 0 && 
                    matrix[current.y][current.x - 1] < matrix[current.y][current.x]){ 
                current.x--; 
            }else if(current.x < matrix[0].length - 1 && matrix[current.y][current.x + 1] >= 0 && matrix[current.y][current.x + 1] < matrix[current.y][current.x]){ 
                current.x++; 
            }else if(current.y > 0 && matrix[current.y - 1][current.x] >= 0 && 
                    matrix[current.y - 1][current.x] < matrix[current.y][current.x]){ 
                current.y--; 
            }else if(current.y < matrix.length - 1 && matrix[current.y + 1][current.x] >= 0 &&matrix[current.y + 1][current.x] < matrix[current.y][current.x]){ 
                current.y++; 
            } 
            path.steps.add(new Point(current.x, current.y)); 
        } 
        path.steps.remove(current); // удаляем последний, т.к. 
        currentPath = path; 
        searching = false; 
 
    } 
 
    Color getColor(int i, int j){ 
        if (start.x == j && start.y == i) 
            return Color.GREEN; 
        if (finish.x == j && finish.y == i) 
            return Color.RED; 
        if(currentPath.steps.contains(new Point(j, i))) 
            return Color.blue; 
        switch (field[i][j]){ 
            case '_': 
                if(searching) { 
                    if (matrix[i][j] == -1) 
                        return Color.MAGENTA; 
                    return new Color(Math.min(matrix[i][j] * 3,255), Math.min(matrix[i][j] * 3,255), 0); 
                } 
                return Color.white; 
            case '0': return Color.gray; 
            default: return Color.black; 
        } 
    } 
 
    void sleep(int delay){ 
        try { 
            Thread.sleep(delay); 
        }catch (InterruptedException e){} 
    } 
 
    @Override 
    public void run() { 
        while (true) { 
            if(searching) 
                paint(getGraphics()); 
            //System.out.println("th Sleep"); 
            try { 
                Thread.sleep(16); 
            } catch (InterruptedException e) { 
            } 
        } 
    } 
 
    @Override 
    public void paint(Graphics g) { 
        //System.out.println("......paint......"); 
        for(int i = 0; i < field.length; i++) 
            for(int j = 0; j < field[i].length; j++) { 
                g.setColor(getColor(i,j)); 
                g.fillRect(j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE); 
            } 
 
    } 
 
    @Override 
    public void mousePressed(MouseEvent e) { 
        int I = e.getY() / CELL_SIZE; 
        int J = e.getX() / CELL_SIZE; 
        if(e.getButton() == MouseEvent.BUTTON1) 
            start = new Point(J, I); 
        else 
            finish = new Point(J, I); 
        findPath(); 
        repaint(); 
    } 
 
    @Override 
    public void mouseClicked(MouseEvent e) {} 
 
    @Override 
    public void mouseReleased(MouseEvent e) {} 
 
    @Override 
    public void mouseEntered(MouseEvent e) {} 
 
    @Override 
    public void mouseExited(MouseEvent e) {} 
} 