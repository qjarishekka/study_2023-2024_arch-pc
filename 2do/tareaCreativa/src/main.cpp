
#include<iostream>
using namespace std;


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

struct Vertice{
    int val;
    Vertice * next;

};



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
    Dupla operator&=(Dupla &a){
        Dupla tmp;
        tmp.x = a.x;
        tmp.y = a.y;
        return tmp;
    }
    ~Dupla(){}
};

class Graph{
    public:
    int numberOfVectors;
    int numberOfEdges;
    int **incidenceMatrix;
    int ** adjacencyMatrix;
    int matrixSize;
    Vertice * resVeartices;
    Vertice * stackVertices;

    Graph(){
        numberOfVectors = 0;
        matrixSize = numberOfVectors;
        numberOfEdges = 0;
        incidenceMatrix = nullptr;
        adjacencyMatrix = nullptr;
        resVeartices = nullptr;;
        stackVertices = nullptr;
    }

    Graph(int vectors,int **incidenceM){

        numberOfVectors = vectors;
        matrixSize = numberOfVectors;
        numberOfEdges = getNumberOfEdges(incidenceM);
        incidenceMatrix = incidenceM;
        adjacencyMatrix = getPointerOfAdjacencyMatrix(incidenceM);
        resVeartices = nullptr;
        stackVertices = nullptr;
    }


    int ** getPointerOfAdjacencyMatrix(int ** incidenceMatrix){

        return nullptr;
    }
   
    int getNumberOfEdges(int **incidenceMatrix){
        int counter = 0;

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

    void orderedDuplaOfVectors( Dupla *&duplaArray , int Edges){

        Dupla temp;
        Dupla min(99999999,99999999);
        int indexMin = 0;
        int edgeMin = 99999999;

        for(int j = 0; j<Edges ; j++){
            edgeMin = 99999999;
            indexMin = 0;

            for(int i = j; i<Edges; i++){
                if(incidenceMatrix[duplaArray[i].x][duplaArray[i].y] <= edgeMin ){
                    edgeMin = incidenceMatrix[duplaArray[i].x][duplaArray[i].y];
                    indexMin = i;
                }   
            }

            temp = duplaArray[j];
            duplaArray[j] = duplaArray[indexMin];
            duplaArray[indexMin] = temp;   
        }
    }

    bool isVectorInArray(Dupla vertice, int array[]){

        for(int i =0; i< numberOfVectors ; i++){
            if(vertice.x == array[i] || vertice.y == array[i]){
                return true;
            }

        }
        return false;

        
    }

    int ** kraskalAlgoritm(){
        Dupla * duplaOfVectors = new Dupla [numberOfEdges];
        Dupla * treeOfEdges = new Dupla[numberOfEdges];
        int indexOfduplaOfVectors = 0;
        int *arreyOfVectors = new int[numberOfVectors];
        

        for(int i = 0; i< matrixSize ; i++){
            for(int j = 0; j< i; j++){
                
                if(incidenceMatrix[i][j] != 0){
                    duplaOfVectors[indexOfduplaOfVectors].x = j;
                    duplaOfVectors[indexOfduplaOfVectors].y = i;
                    indexOfduplaOfVectors++;
                }

            }
        }

        orderedDuplaOfVectors(duplaOfVectors, numberOfEdges);



        treeOfEdges[0] = duplaOfVectors[0];
        for(int i = 0; i<numberOfEdges ; i++){
        

        treeOfEdges[i] = duplaOfVectors[i];

        cout<<isVectorInArray(duplaOfVectors[i], arreyOfVectors)<<endl;

        if(isVectorInArray(duplaOfVectors[i], arreyOfVectors) ){

        }


            
        }






/* //comprobacion de arreglos
        for(int i = 0; i< numberOfEdges ; i++){
            cout<<"("<<duplaOfVectors[i].x << ";" << duplaOfVectors[i].y<<")"<<" ";
        }
        cout<<endl<<endl;

        

        for(int i = 0; i< numberOfEdges ; i++){
            cout<<"("<<duplaOfVectors[i].x << ";" << duplaOfVectors[i].y<<")"<<" ";
        }

        cout<<endl;
        for(int i = 0; i<numberOfEdges; i++){
            cout<< incidenceMatrix[duplaOfVectors[i].x][duplaOfVectors[i].y]<< " ";
        }
        cout<<endl;
*/


        

        


        return 0;
    }
 
    void addVertice( int V){

        Vertice **temp = &stackVertices;

        while(*temp != nullptr){
            temp = &((*temp)->next);
        }

        Vertice * newVertice = new Vertice;

        newVertice->val = V;
        newVertice->next = nullptr;
        
        *temp = newVertice;

    }

    void printStack(){

        Vertice * temp = *&stackVertices;

        while(temp != nullptr){
            cout<<temp->val<<endl;
            temp= temp->next;
        }
    }

    bool isAllVerticesIn(){

        //declarar variables
       Vertice * temp = *&stackVertices;
       int * allVertices = new int [numberOfVectors];

       //llenar todo el arreglo con numbero del 1 al numberOfVectors
       for(int i = 0 ; i < numberOfVectors ; i++){
            allVertices[i-1] = i;
            cout<<allVertices[i-1]<<" ";
       }

        //cout<<endl;
        //comparar el arreglo con el valor de la pila

        while(temp != nullptr){
           
            
            for(int i = 0; i<numberOfVectors; i++){
                
                if(temp->val == allVertices[i]){
                    allVertices[i] = 0;
                    //cout<<allVertices[i]<<" ";
                }
            }
            temp= temp->next;
        }

        for(int i = 0; i<numberOfVectors ; i++){
            if(allVertices[i] != 0){

                return false;
            }
        }

        return true;
    }

    bool isLastIqualFirst(){
        Vertice * temp = *&stackVertices;
        int first = temp->val;
        while(temp != nullptr){
            temp = temp->next;
        }
        int last = temp->val;

        if(first == last){
            return true;
        }

        return false;
    }



    int * geteulercicle( int start){

    int **copyMatrix = new int*[numberOfVectors];
    for(int i = 0; i<numberOfVectors; i++){
        copyMatrix[i] = new int [numberOfVectors];
        for(int j = 0; j< numberOfVectors; j++){
            copyMatrix[i][j] = matrix[i][j];

        }
    }

    //inicio del algoritmo

    addVertice(start);

    while(isAllVerticesIn() && isLastIqualFirst()){
        
    }
    






        




    
   //cout<<resVeartices->val<<endl;










        return nullptr;

    }

    ~Graph(){
        delete[] incidenceMatrix;
        delete[] adjacencyMatrix;
    }



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
//cout<< G1.numberOfVectors<<" "<<G1.numberOfEdges<<endl;

//G1.kraskalAlgoritm();

G1.geteulercicle(0);






/* cout<<sizeof(matrix[0])/sizeof(matrix[0][0]) << endl;

for(int i = 0 ; i< 15 ; i++){

    for(int j = 0 ; j < 15 ; j++){

        cout<<pointerOfIncidenceMatrix[i][j] <<"\t";

    }
    cout<< endl;
} */
return 0;

}