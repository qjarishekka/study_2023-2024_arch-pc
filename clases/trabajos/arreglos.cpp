#include <iostream>
#include <time.h>
using namespace std;
int main (){

int i = 0;
int j = 0;

int buff = 0;


srand(time(NULL));

int * X;
int n = 10;
X = new int [n];

for(int i=0;i<n -1 ;i++){
    X[i] = (rand()%10000)/100 - 50;

}

for(int i = 0; i<n-1;i++){

    cout << X[i]<< endl;

}
 
 cout << endl << "упорядочный массив";


for(int i = 0; i <n-1; i++){

    for(j = 0; i <n-2; i++){
        
    }



    



}


return 0;
}