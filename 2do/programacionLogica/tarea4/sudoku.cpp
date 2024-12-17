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
    bool hasFieldChanged;
    
    Sudoku(){
        size = 9;
        difficulty = 40;
        checkerOfSizeOfField();
        generateField();
        hasFieldChanged = true;
        
    }

    Sudoku(int s){
        size = s;

        checkerOfSizeOfField();
        generateField();
        hasFieldChanged = true;
       
    }

    Sudoku(int s, int d){
        size = s;
        difficulty = (size*size) - ( pow(3,d)  +  size*5 );

        checkerOfSizeOfField();
        generateField();
        hasFieldChanged = true;
        
    }

    Sudoku(string f[9][9],int s  ){
        size = s;
        
        Field =new string*[s];
        for(int i = 0; i< size; i++){
            Field[i] = new string[size];
            for(int j = 0 ; j< size; j++){
                Field[i][j] = f[i][j];
            }
        }

        difficulty = 0;
        hasFieldChanged = true;


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
            //Field[Y][X] = to_string( rand()%(size) + 1 );
            //printField();



            while(generationRowAndColumnsChecker(X,Y) ||  generationBoxChecker(X,Y) ){

                Field[Y][X] = to_string( rand()%(size) + 1 );
            
            }
        }
    }

    bool generationRowAndColumnsChecker(int X , int Y){
        
        for(int i = 0; i<size; i++){
            if( Field[Y][X] == Field[Y][i] ){
                if( i != X){
                    return true;
                }
            }
        }

        for(int i = 0; i< size ; i++){
            if( Field[Y][X] ==Field[i][X]){\
               if( i != Y){
                    return true;
                }
            }
            
        }
        return false;
    }

    bool generationBoxChecker(int X , int Y){
        
        int Xstart = 0 + ( 3* ((int)(X/3)) ) ;
        int Xend = Xstart+2;
        int Ystart = 0 + ( 3* ((int)(Y/3)) );
        int Yend = Ystart + 2;

        for(int i = Ystart ; i<=Yend ; i++){

                for(int j = Xstart ; j<=Xend ; j++){
                
                if(Field[Y][X] == Field[i][j] ){

                    if(X != j && Y!=i){
                        return true;
                    }   
                }
            }
        }

        return false;
    }

    void absoluteSolver(){
        int counter = 0;

        while(!isSodokuSolved() && hasFieldChanged){
            for(int Y = 0; Y < size ; Y++){
                for(int X = 0; X< size; X++){
                    cout<<X<< " " <<Y << endl;

                    rowSAndColumnSetter(X, Y);
                    boxSetter(X, Y);
                    printField();
                }
            }
            counter++;
            cout<<counter<<endl;
        }

            
            
        


    }

    void rowSAndColumnSetter(int X , int Y){

        hasFieldChanged = false;
        if(Field[Y][X].length() != 1){

            for(int i = 0; i<size; i++){

                if( Field[Y][i].length() == 1 &&  Field[Y][X].find(Field[Y][i]) != -1 && Field[Y][X].length() != Field[Y][i].length() ){
                    Field[Y][X].erase(Field[Y][X].begin() + Field[Y][X].find(Field[Y][i]));
                    hasFieldChanged = true;
                }


            }

            for(int i = 0; i<size; i++){

                if( Field[i][X].length() == 1 && Field[Y][X].find(Field[i][X]) != -1 && Field[Y][X].length() != Field[i][X].length() ){
                    
                    Field[Y][X].erase(Field[Y][X].begin() + Field[Y][X].find(Field[i][X]));
                    hasFieldChanged = true;
                }


            }

        }






                
/*                 if( Field[Y][X].length() == 1 ){

                    for(int i = 0 ; i< size; i++){

                        if(   X !=i &&  Field[Y][i].find(Field[Y][X]) != -1) {
                            

                            Field[Y][i].erase( Field[Y][i].begin() +  Field[Y][i].find(Field[Y][X]) );
                            hasFieldChanged = true;

                            
                        }
                    }


                    for(int i = 0 ; i< size; i++){

                        if( Y !=i &&  Field[i][X].find(Field[Y][X]) != -1 ) {
                           
                            Field[i][X].erase( Field[i][X].begin() +  Field[i][X].find(Field[Y][X]) );
                            hasFieldChanged = true;
                        }
                    }
                }           */     



    }

    void boxSetter(int X, int Y){
        //hasFieldChanged = false;

        int Xstart;
        int Xend;
        int Ystart;
        int Yend;


        if(Field[Y][X].length() != 1){



        }










/*                 Xstart = 0 + ( 3* ((int)(X/3)) ) ;
                Xend = Xstart+2;
                Ystart = 0 + ( 3* ((int)(Y/3)) );
                Yend = Ystart + 2;

                if( Field[Y][X].length() == 1 ){

                    for(int i = Ystart ; i <= Yend ; i++){
                        for(int j = Xstart; j<= Xend; j++){

                           if(  X !=j && Y!= i && Field[i][j].find(Field[Y][X]) != -1){
                                Field[i][j].erase( Field[i][j].begin() +  Field[i][j].find(Field[Y][X]) );
                                hasFieldChanged = true;
                           }

                        }
                    }

                } */




    }

    bool isSodokuSolved(){

        for(int i = 0 ; i< size ; i++){
            for(int j = 0 ; j< size ; j++){
                if(Field[i][j].length() != 1){
                    return false;
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
                    //cout<<"[]\t";
                    cout<<Field[i][j] << "\t";
                }
                
            }
            cout<< endl<<endl;
        }

        cout<<"-------------------------------------------"<<endl;
    }


};



int main(){

    srand(time(NULL));
//123456789
   string sudokuField[9][9] = {     {"123456789",   "4",            "123456789",        "123456789",    "123456789",    "123456789",         "123456789", "  123456789" ,    "6" },
                                    {"123456789",   "123456789",    "123456789",         "3",           "7",            "123456789",         "123456789",    "8",            "9" },
                                    {"9",           "123456789",    "123456789",        "123456789",    "123456789",    "123456789",         "123456789",    "123456789" ,   "6" },

                                    {"123456789",   "5",            "9",                "7",            "4",            "2",                 "8",            "6" ,           "1" },
                                    {"1",           "8",            "2",                "6",            "3",            "9",                 "7",            "3" ,           "123456789" },
                                    {"4",           "7",            "6",                "5",            "1",            "8",                 "123456789",    "123456789" ,   "2" },

                                    {"8",           "6",            "4",                "1",            "123456789",    "3",                 "9",            "123456789" ,   "7" },
                                    {"2",           "3",            "123456789",        "123456789",    "9",            "6",                 "1",            "5" ,           "8" },
                                    {"123456789",   "9",            "123456789",        "123456789",    "2",            "7",                 "6",            "3" ,           "4" }
 };


    Sudoku sudoku(sudokuField,9);
    
    
    //cout<<sudoku.size<<endl;
    sudoku.printField();
    sudoku.absoluteSolver();

    sudoku.printField();


    //cout<< rand()%9 + 1<<endl;
    //cout<<sudoku.Field[1][3].size()<<endl;


    return 0;
}