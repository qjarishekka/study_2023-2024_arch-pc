
#include<iostream>
using namespace std;



struct Graph{
    int numbereOfVectors;
    int numberOfEdges;
    int **incidenceMatrix;
    int ** adjacencyMatrix;

    Graph(){
        numbereOfVectors = 0;
        numberOfEdges = 0;
        incidenceMatrix = nullptr;
        adjacencyMatrix = nullptr;
    }

    Graph(int vectors, int edges,int **incidenceM, int **adjacencyM ){

        numbereOfVectors = vectors;
        numberOfEdges = edges;
        incidenceMatrix = incidenceM;
        adjacencyMatrix = adjacencyM;    
    }

    ~Graph(){
        delete[] incidenceMatrix;
        delete[] adjacencyMatrix;
    }
};


                            // 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
int matrix[15][15] = {/*1*/  { 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 , 0 , 0 , 0} , 
                      /*2*/  { 2 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 5 , 8 , 0 , 0 , 0 , 0 , 0 } ,
                      /*3*/  { 0 , 4 , 0 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*4*/  { 0 , 0 , 6 , 0 , 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*5*/  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*6*/  { 0 , 0 , 0 , 8 , 0 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*7*/  { 0 , 0 , 0 , 0 , 3 , 0 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*8*/  { 0 , 0 , 0 , 0 , 0 , 0 , 5 , 0 , 5 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*9*/  { 3 , 5 , 0 , 0 , 0 , 0 , 0 , 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                     /*10*/  { 0 , 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 9 , 0 , 0 , 1 , 8 } ,
                     /*11*/  { 0 , 0 , 0 , 0 , 0 , 7 , 0 , 0 , 0 , 9 , 0 , 2 , 0 , 0 , 1 } ,
                     /*12*/  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 , 5 , 0 , 2 } ,
                     /*13*/  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 5 , 0 , 7 , 8 } ,
                     /*14*/  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 7 , 0 , 6 } ,
                     /*15*/  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 1 , 2 , 8 , 6 , 0 } ,
};




int main(){

int **pointerOfMatrix = new int*[sizeof(matrix[0])/sizeof(matrix[0][0])];
for(int i = 0; i<  sizeof(matrix[0])/sizeof(matrix[0][0]) ; i++ ){
    pointerOfMatrix[i] = new int [sizeof(matrix[0])/sizeof(matrix[0][0])];
}

for(int i = 0 ; i< 15 ; i++){
    for(int j = 0 ; j < 15 ; j++){
       pointerOfMatrix[i][j] = matrix[i][j];
    }
    cout<< endl;
}


Graph G1;

/* cout<<sizeof(matrix[0])/sizeof(matrix[0][0]) << endl;

for(int i = 0 ; i< 15 ; i++){

    for(int j = 0 ; j < 15 ; j++){

        cout<<pointerOfMatrix[i][j] <<"\t";

    }
    cout<< endl;
} */

}