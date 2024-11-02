#include<iostream>
#include <time.h>
#include <stdlib.h>  
#include<stdio.h>

using namespace std;



int main(){

srand(time(NULL)); 
int sudoku[9][9];

for(int i = 0; i < 9; i++){

    for(int j = 0; j < 9 ; j++){

        sudoku[i][j] = 0;
    
    }
}



for(int i = 0; i < 9; i++){

    for(int j = 0; j < 9 ; j++){

        if(rand()% 10 < 5){

            sudoku[i][j] =rand()% 10 +1;

        }

        
    
    }

}

for(int i = 0; i < 9; i++){

    for(int j = 0; j < 9 ; j++){

        cout<< sudoku[i][j]<< "\t";
    
    }
    cout<<endl;
}


return 0;
}


int resolver( int &sudoku) {




}