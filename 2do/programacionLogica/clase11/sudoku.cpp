#include <iostream>
#include <string>
using namespace std;


class Matrix{

    string ** cells;

    Matrix(){
        cells = new string*[9];
        for (int i = 0; i < sizeof(cells)/sizeof(cells[1]); i++){
            cells[i] = new string[9];            
        }
        for(int i = 0; i < 9 ; i++){
            for(int j = 0; j< 9 ; j++){
                cells[i][j] = '1,2,3,4,5,6,7,8,9';
            }
        }
        
    }   

    bool isFinal(int i , int j){
        return cells[i][j].size() == 1;
        //return (int)cells[i][j].find('j')== -1;
    }

    void set(int i , int j, string value){
        cells[i][j] = value;
        removeRow(i , value);
        set(i,j);
    }
    void removeRow(int i, string value){
       

            for(int j = 0; j<9 ; j++){
                //agregar isFinal();
                //cells[i][j].replace(value,",");
                if(isFinal(i,j))
                set(i,j);
            
            }
            
        
    }
    void set(int i , int j){
        removeRow(i,cells[i][j]);
    }
    void checkRow(int i){

        string value = "123456789";
        for(int index = 0; index<9 ; index++)
        {    
            bool fl = false; int J = -1;
            string v = "";
            v = value[index];
            for(int j ; j<9; j++){
                if (cells[i][j].find(v))
                if(fl){
                    fl = false;
                    break;
                }else{
                    fl= true;
                    J=j;
                }
            if(fl){
                set(i,J,v);
            }
            }
        }
    }
};