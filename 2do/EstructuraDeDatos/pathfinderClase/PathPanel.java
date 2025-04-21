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

    boolean checkOutRange(int x ,int y ){

        return y < 0 || y >= matrix.length || x < 0 || x >= matrix[y].length;
    }

    boolean checkNeighbor(int i , int j , int dy , int dx){
        if(checkOutRange(j + dx , i + dy)){
            
            return false;
        }
            
        
        if (  matrix[i + dy][j + dx] >= 0 && ( matrix[i][j] == -1  ||  matrix[i][j] > matrix[i + dy][j + dx] + 1 )    ) {
            
            matrix[i][j] = matrix[i + dy][j + dx] + 1; 
            sleep(1);
            return true;
        } 
        return false;
    }


    

    void findPath(){ 
        searching = true; 
        currentPath = new Path(); 
        Path path = new Path(); 

        
 
        matrix = new int[field.length][field[0].length]; 
        for (int i = 0; i < matrix.length; i++) 
            for (int j = 0; j < matrix[i].length; j++) 
                matrix[i][j] = field[i][j] == '0' ? -2 : -1; 
 
 
        Point []neighbors = new Point[]{
                new Point(0 , 1),
                new Point(0 , -1),
                new Point(1 , 0),
                new Point(-1 , 0),
    
            };

        matrix[start.y][start.x] = 0; 
        boolean fl = true; 
        while (fl && matrix[finish.y][finish.x] < 0) { 
            fl = false; 
            // пересчитаем матрицу 
            for (int i = 0; i < matrix.length; i++) { 
                for (int j = 0; j < matrix[i].length; j++) { 
                    for(Point neighbor : neighbors ){
                        fl = fl || checkNeighbor(i  , j , neighbor.y, neighbor.x);
                    }
                } 
                //repaint(); 
                //System.out.println("find Sleep"); 
 
 
            } 
            //System.out.println("aqui");
 
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

            }else if(current.x < matrix[0].length - 1 && matrix[current.y][current.x + 1] >= 0 && 
                    matrix[current.y][current.x + 1] < matrix[current.y][current.x]){ 
                current.x++; 

            }else if(current.y > 0 && matrix[current.y - 1][current.x] >= 0 && 
                    matrix[current.y - 1][current.x] < matrix[current.y][current.x]){ 
                current.y--; 

            }else if(current.y < matrix.length - 1 && matrix[current.y + 1][current.x] >= 0 &&
                    matrix[current.y + 1][current.x] < matrix[current.y][current.x]){ 
                current.y++; 
            } 
            path.steps.add(new Point(current.x, current.y)); 
            
        }
        path.steps.remove(current); // удаляем последний, т.к. 
        currentPath = path; 
        searching = false; 
 
    } 


    

    class Node{
        int x , y, step, length;
        boolean check = false;
        Node(int x , int y , int step){
            this.x = x ;
            this.y = y;
            this.step = step;
            estimate();
        }

        void estimate(){
            length = (int)(finish.x - x  + Math.abs(finish.y - y));
        }
        boolean lessThan(Node other){
            if(other.check) 
                return true;

            return step + length < other.step + other.length;
        }

    }
 

    void AStar(){
        searching = true;
        currentPath = new Path();
        Path path = new Path();
        Node current = new Node(start.x, start.y, 0);

        Point[] steps = new Point[]{
            new Point(0 , 1),
            new Point(0 , -1),
            new Point(1 , 0),
            new Point(-1 , 0),
    
        };


        ArrayList<Node> nodes  = new ArrayList<>(4);
        while(current.x != finish.x && current.y != finish.y){

            
            for(Point step : steps){
                if(checkOutRange(current.x + step.x , current.y + step.y)  && matrix[current.x + step.x][current.y + step.y ] != '0' ){
                    if(current.x + step.x == finish.x && current.y + step.y == finish.getY()){
                        current = new Node(finish.x , finish.y , current.step+1);
                        break;
                    }
                        

                    nodes.add(new Node(current.x + step.x , current.y + step.y, current.step +1));
                }
            }
            Node min = nodes.get(0);
            for(Node node : nodes){
                if(node.lessThan(min)){
                    min = node;
                }
            }
            current = min;
        }

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