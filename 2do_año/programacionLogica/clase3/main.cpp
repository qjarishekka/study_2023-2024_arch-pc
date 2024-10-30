#include <iostream>
#include "../clase2/value.h"
#include <string.h>


int main(){


}


Value parseFormula( std::string line){


int numeroDeFunciones = 4;


char* ops = new char[numeroDeFunciones]{'+','-','*','/'};
int br = 0;
int id = -1;

for(int i = 0; i<numeroDeFunciones ; i++ ){

    if(line[i] == '('){
        br++;
    }
    if(line[i] == ')'){
        br--;
    }

    if(br == 0 && line[i] == ops[0] ){
        id = i; 
    }
}

if(id != -1){

    return new Pair(new Atom( ops[0], new Pair( parseFormula() )))

}else{

    return new Atom(line);

}

}