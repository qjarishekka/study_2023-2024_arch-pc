#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int main(){



int i = 0;
int n = 10;
double max = 100;
double min = -100;
srand(time(NULL));

double *xp = new double[n];

cout<<"исходный массив:\n";

for(i=0;i<n;i++){

    xp[i] = (rand()%100)/10.0;

    cout<< xp[i]<<endl;

}

cout << endl;

for(i=0;i<n;i++){

    if(xp[i] > min){

        min = xp[i];

    }
    
    if(xp[i] < max){

        max = xp[i];

    }


}

cout<< "max:" << min << endl;
cout << "min:" << max << endl;



    return 0;
}