#include <iostream>
#include<string>
#include<math.h>

#include <cstdlib>
#include <ctime>

using namespace std;




class Sudoku{
    public:
    int size;
    int difficulty;
    string ** Field;
    
    Sudoku(){
        size = 9;
        difficulty = 40;
        checkerOfSizeOfField();
        generateField();
    }

    Sudoku(int s){
        size = s;

        checkerOfSizeOfField();
        generateField();
    }

    Sudoku(int s, int d){
        size = s;
        difficulty = 81 - ( pow(3,d)  +  40 );

        checkerOfSizeOfField();
        generateField();
    }

    

    void checkerOfSizeOfField(){
        if(size%3 != 0){
            size += 3-(size%3);
        }
    }

    void generateField(){

        Field = new string*[size];

        int X = rand()%(size-1);
        int Y = rand()%(size-1);

        
        for(int i = 0; i< size ; i++){
            Field[i] = new string[size];
        }
        for(int i = 0; i< size ; i++){
            for(int j = 0; j< size ; j++){
                Field[i][j] = "123456789";
            }
        }

        //llenar el campo con numeros fijos
        //---------------------------------
        Field[Y][X] = to_string( rand()%(size-1) + 1 );
        
        for(int i = 0 ; i < difficulty ; i++){
            
            X = rand()%(size);
            Y = rand()%(size);
            //cout<<X<< " " << Y <<endl;
            Field[Y][X] = to_string( rand()%(size) + 1 );
            //printField();
            while(generationRowAndColumnsChecker(X,Y)){
                Field[Y][X] = to_string( rand()%(size) + 1 );
                printField();
            cout<<"--------------------------------------"<<endl;
            }
            
            printField();
            cout<<"--------------------------------------"<<endl;

        }
    }

    bool generationRowAndColumnsChecker(int X , int Y){
        
        for(int i = 0; i<size; i++){

            if( !(Field[Y][X] ==Field[Y][i]) ){
                return false;
            }
            
        }

        for(int i = 0; i< size ; i++){
            if(!(Field[Y][X] ==Field[i][X])){
                return false;
            }
            
        }
        return true;
    }

    bool generationBoxChecker(int X , int Y){
        
        int Xstart = 0 + ( 3* ((int)(X/3)) ) ;
        int Xend = Xstart+2;
        int Ystart = 0 + ( 3* ((int)(Y/3)) );
        int Yend = Ystart + 2;
        //cout<<Xstart<<" "<<Xend<<" "<<Ystart<<" "<<Yend<<" " <<X<<" " <<Y << " "<<(int)(X/3) <<endl;

        
        for(int i = Ystart ; i<=Yend ; i++){

                for(int j = Xstart ; j<=Xend ; j++){
                
                if(Field[Y][X].compare(Field[i][j])){
                    if(X != j && Y!=i){
                        return false;
                    }
                    
                }
                    

            }
        }
        return true;
    }



    void printField(){

        for(int i = 0 ; i< size; i++){
            for(int j = 0; j< size ; j++){ 
                if(Field[i][j].size() == 1){
                    cout<<Field[i][j] << "\t";
                }else{

                    //cambiar cuando haya acabado
                    cout<<"[]\t";
                    //cout<<Field[i][j] << "\t";
                }
                
            }
            cout<< endl<<endl;
        }
    }


};

int main(){

    srand(time(NULL));


    Sudoku sudoku;
    
    
    //cout<<sudoku.size<<endl;
    sudoku.printField();


    //cout<< rand()%9 + 1<<endl;
    //cout<<sudoku.Field[1][3].size()<<endl;


    return 0;
}