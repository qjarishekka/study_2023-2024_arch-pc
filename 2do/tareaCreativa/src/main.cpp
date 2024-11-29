
#include<iostream>
using namespace std;

struct Dupla{
    int y;
    int x;

    Dupla( int X, int Y){
        x = X;
        y = Y;
    }
    Dupla(){
        y = 0;
        x = 0;
    }
    Dupla operator&=(Dupla a){
        Dupla tmp;
        tmp.x = a.x;
        tmp.y = a.y;
        return tmp;
    }
    ~Dupla(){}
};

class Graph{
    public:
    int numbereOfVectors;
    int numberOfEdges;
    int **incidenceMatrix;
    int ** adjacencyMatrix;
    int matrixSize;

    Graph(){
        numbereOfVectors = 0;
        matrixSize = numbereOfVectors;
        numberOfEdges = 0;
        incidenceMatrix = nullptr;
        adjacencyMatrix = nullptr;
        
    }

    Graph(int vectors,int **incidenceM){

        numbereOfVectors = vectors;
        matrixSize = numbereOfVectors;
        numberOfEdges = getNumberOfEdges(incidenceM);
        incidenceMatrix = incidenceM;
        adjacencyMatrix = getPointerOfAdjacencyMatrix(incidenceM);
        
        
    }

    int ** getPointerOfAdjacencyMatrix(int ** incidenceMatrix){

        return nullptr;
    }
   
    int getNumberOfEdges(int **incidenceMatrix){
        int counter = 0;
        
        //cout<<sizeof(incidenceMatrix)<<endl;

        for(int i = 0; i< matrixSize ; i++ ){
            for(int j = 0; j < i ; j++ ){
                if(incidenceMatrix[i][j] != 0){
                    counter++;
                }
            }
        }
        return counter;

    }

    void print(){
        for(int i = 0 ; i< 15 ; i++){
            for(int j = 0 ; j < 15 ; j++){
            cout<<incidenceMatrix[i][j] <<"\t";
            }
        cout<< endl;
        }

        cout<<endl;
    }

    int ** kraskalAlgoritm(){
        Dupla * duplaOfVectors = new Dupla [numberOfEdges];
        int indexOfduplaOfVectors = 0;
        

        for(int i = 0; i< matrixSize ; i++){
            for(int j = 0; j< i; j++){
                
                if(incidenceMatrix[i][j] != 0){
                    duplaOfVectors[indexOfduplaOfVectors].x = j;
                    duplaOfVectors[indexOfduplaOfVectors].y = i;
                    indexOfduplaOfVectors++;
                }

            }
        }

/*         for(int i = 0; i< numberOfEdges ; i++){
            cout<<duplaOfVectors[i].x << " " << duplaOfVectors[i].y<<endl;
        } */

       

        

        


        return 0;
    }



    ~Graph(){
        delete[] incidenceMatrix;
        delete[] adjacencyMatrix;
    }



};


                            // 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
int matrix[15][15] = {/*1*/  { 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 , 0 , 0 , 0 } , 
                      /*2*/  { 2 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 5 , 8 , 0 , 0 , 0 , 0 , 0 } ,
                      /*3*/  { 0 , 4 , 0 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*4*/  { 0 , 0 , 6 , 0 , 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*5*/  { 0 , 0 , 0 , 8 , 0 , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      /*6*/  { 0 , 0 , 0 , 0 , 3 , 0 , 6 , 0 , 0 , 0 , 7 , 0 , 0 , 0 , 0 } ,
                      /*7*/  { 0 , 0 , 0 , 0 , 0 , 6 , 0 , 5 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
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



int **pointerOfIncidenceMatrix = new int*[sizeof(matrix[0])/sizeof(matrix[0][0])];
for(int i = 0; i<  sizeof(matrix[0])/sizeof(matrix[0][0]) ; i++ ){
    pointerOfIncidenceMatrix[i] = new int [sizeof(matrix[0])/sizeof(matrix[0][0])];
}

for(int i = 0 ; i< 15 ; i++){
    for(int j = 0 ; j < 15 ; j++){
       pointerOfIncidenceMatrix[i][j] = matrix[i][j];
    }
}


Graph G1(15,pointerOfIncidenceMatrix);



G1.print();
//cout<< G1.numbereOfVectors<<" "<<G1.numberOfEdges<<endl;

G1.kraskalAlgoritm();







/* cout<<sizeof(matrix[0])/sizeof(matrix[0][0]) << endl;

for(int i = 0 ; i< 15 ; i++){

    for(int j = 0 ; j < 15 ; j++){

        cout<<pointerOfIncidenceMatrix[i][j] <<"\t";

    }
    cout<< endl;
} */
return 0;

}