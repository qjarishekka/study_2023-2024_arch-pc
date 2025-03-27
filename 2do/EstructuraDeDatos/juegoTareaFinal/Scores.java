package juegoTareaFinal;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Scores {
    BufferedReader bufferedReader;
    PrintWriter writer;

    long linesCounter;
    File file;
    FileReader fileReader;
    FileWriter fileWriter;

    
    public String leaderboard[];
    public String maxScore[];

    boolean wasScoreSet = false;

    Scores(){
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

        try {
            
            fileWriter = new FileWriter(file);
            writer = new PrintWriter(fileWriter);
            boolean flag = true;

            for(int i = 0 ; i < leaderboard.length ; i++){

                writer.println(leaderboard[i]);
                if(leaderboard[i].startsWith(name)){
                    flag = false;
                }
            }

            if(flag){
                writer.print(name + " : " + score);
            }
            
            wasScoreSet = flag;
            

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

    public boolean wasNewScoreSet(){
        return wasScoreSet;
    }

}
