package GameAliensAttack;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

import javax.swing.JLabel;

public class Scores extends Thread {
    BufferedReader bufferedReader;
    PrintWriter writer;

    long linesCounter;
    File file;
    FileReader fileReader;
    FileWriter fileWriter;
    int limitOfSaves = 5;
    int currentScore = 0;

    
    String leaderboard[];
    String maxScore[];

    boolean wasScoreSet;

    public Scores(){
        leaderboard = getLeaderBoard();
        maxScore = getMaxScore();
    }

    private String[] getLeaderBoard(){

        int counter = 0;
        String leaderboard[] = new String[1];
        try{
        file = new File("src//saves//leaderboard.txt");
        fileReader = new FileReader(file);
        bufferedReader = new BufferedReader(fileReader);
        bufferedReader.mark(10000000);
        while(bufferedReader.readLine() != null){
            counter++;
        }
        bufferedReader.reset();
        leaderboard = new String[counter];
        for(int i = 0; i< counter ; i++){
            leaderboard[i] = bufferedReader.readLine();
            
        }        

        }catch(Exception e){
            e.printStackTrace();
        }finally{
            try {
                if (null != fileReader) {
                    fileReader.close();
                }
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
        return leaderboard;
    }

    public void saveLeaderBoard(){
        
        try {
            
            fileWriter = new FileWriter(file);
            writer = new PrintWriter(fileWriter);

            for(int i = 0 ; i < leaderboard.length-1 ; i++){
                if(i < limitOfSaves)
                    writer.println(leaderboard[i]);
            }
            writer.print(leaderboard[leaderboard.length-1]);

        } catch (Exception e) {
            e.printStackTrace();
        }finally{
            try {
               
                fileWriter.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }


    }



    private String[] getMaxScore(){
        
        String maxScore[] = new String[2];
        int scores = 0; 
        int indexOfNumber = 0;

        for(int i = 0 ; i< leaderboard.length ; i++){

            indexOfNumber = leaderboard[i].indexOf(":", 0)+2;

            if(scores < Integer.parseInt(leaderboard[i].substring(indexOfNumber)) ){
                scores = Integer.parseInt(leaderboard[i].substring(indexOfNumber));
                maxScore[0] = leaderboard[i].substring(indexOfNumber); 
                maxScore[1] = leaderboard[i].substring(0, indexOfNumber-2);
            }
                
        }

        return maxScore;
    }

    public void setNewScore(String name , int score){

        boolean flag = true;
        
        for(int i = 0; i < leaderboard.length ; i++){
            if(leaderboard[i].startsWith(name)){
                flag = false;
            }
        }


        if(flag){
            String temp[] = new String[leaderboard.length + 1];
            for(int i = 0 ; i < leaderboard.length ; i++){
                temp[i] = leaderboard[i];
            }
            
            temp[temp.length-1] = name+ " : " + score;
            leaderboard = temp.clone();
        }

        wasScoreSet = flag;
        
        sortLeaderBoard();
        saveLeaderBoard();

    }

    public boolean wasNewScoreSet(){
        return wasScoreSet;
    }

    public void sortLeaderBoard(){

        int largest = 0;
        int smaller = 0;
        int indexL = 0;
        int indexS = 0;

        new Thread(this).start();

        for(int i = 0  ; i < leaderboard.length ; i++ ){
            for(int j = 0 ; j < leaderboard.length - i -1 ; j ++){

                indexL = leaderboard[j].indexOf(":");
                indexS = leaderboard[j+1].indexOf(":");
                largest = Integer.parseInt(leaderboard[j].substring(indexL + 2));
                smaller = Integer.parseInt(leaderboard[j+1].substring(indexS +2));

                if(largest < smaller){
                    String swap = leaderboard[j];
                    leaderboard[j] = leaderboard[j+1];
                    leaderboard[j+1] = swap;
                }
                /* if(array[j] > array[j+1]){
                    int swap = array[j];
                    array[j] = array[j+1];
                    array[j+1] = swap;
                } */
            }

        }

    }

    public String getLeaderBoardAsText(){

        String text = "<html>";
        
        /* for(int i = 0 ; i < leaderboard.length ; i++){
            text = text +"<p>" + leaderboard[i] + "</p>";
        } */
        text = text+ "hola";

        text = text+ "<html>";

        //System.out.println(text);
        return text;
    }

    public int getLengthOfLaderBoard(){

        return leaderboard.length;
    }

}
