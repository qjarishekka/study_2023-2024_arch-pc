#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define lim1 10
#define lim2 10

int main() {

int m = 0; 
int n = 0;
int arreglo[lim1][lim2];
int random = 0;
int i = 0;
int j = 0;


do{

printf("введите значение для \"n\" и \"m\" не больше десяти и не меньше нуля\n");

scanf("%d",&n);
scanf("%d",&m);

}while(n<=0 || n >10 || m<=0 || m>10);



for(i=0;i<n;i++){

    for(j=0;j<m;j++){

        arreglo[i][j] = rand() % 11;

    }


}

//for(i=0;i<n;i++){for(j=0;j<m;j++){printf("%d\t",arreglo[i][j]);}printf("\n\n");}






}