#include <iostream>
#include <string.h>

using namespace std;

int calcularpi(double precision){

cout<<"calculo de pi"<<endl;

//reservar memoria

int Largo_memoria = (precision * 10) / 3;

cout <<"largo de memoria "<< Largo_memoria<< endl<<endl;

int i;
int j;
int l = 0;

int *calculo = new int[Largo_memoria];
int *pi = new int[Largo_memoria];


int multiplicacion = 0;
int suma = 0;
int presto = 0;



for(i = 0; i < Largo_memoria; i++){

    calculo[i] = 2;

}



// empieza el algoritmo

for(j = 0; j < precision;j++){

    for(i = Largo_memoria-1; i > -1; i--){  //fijarse aqui si hay error

        if(i == 0){

            //cout<<"se ejecuta el i==0"<<endl;


            multiplicacion = calculo[i] * 10;

            //cout<<"multiplicacion: "<<multiplicacion<<endl;


            suma = multiplicacion + presto;

            //cout<< "suma"<<suma<< endl;


            presto = suma/10;

            //cout<<presto<<endl;


            calculo[i] = suma %10;

            //cout<<calculo[i]<<endl;

            /////////////////////////////////////
            /////RASTREO DE NUMEROS INVALIDOS////
            /////////////////////////////////////

            if(presto<10){
            pi[j] = presto;
            presto = 0;
            }else{

                pi[j-l] = presto %10;
                presto = presto / 10;
                l++;
                pi[j-l] +=presto; 

                while(pi[j-l]>9){

                    pi[j-l] = pi[j-l] + presto;


                    l++;

                }



            }


        }else{


            multiplicacion = calculo[i] * 10;

            //cout<<"multiplicacion: "<<multiplicacion<<endl;


            suma = multiplicacion + presto;

            //cout<< "suma"<<suma<< endl;

            calculo[i] = suma % ((i*2) +1);

            presto = (suma/((i*2) + 1)) * i;

            //cout << presto << " "<<i<< endl;

        }




    }


    
    




    for(int k = 0; k < Largo_memoria; k++){

            //cout<<calculo[k]<< " ";
 
    }



}



cout<<pi[0]<<",";


for(int m = 1; m< precision;m++){
cout<< pi[m];

}


cout <<endl;
return 0;

}





int main(){

double precision;


cin>> precision;    //3.14159265358979323846
                    //

calcularpi(precision);

}