#include <stdio.h>
#define lim 30

int main(){

int arreglo[lim];
int i = 0;
int n = 0;
int counter = 0;

printf("эта программа выводит первое число, которое удобледворяет уравенство Ak < An \n");


do{
    printf("сколько чисел вы ведёте? \nколичество должно удавлетворять неравество 0 < n < 30 \n");
    scanf("%d",&n);
}while(n<=0 || n>30);

do{
    counter = 0;

    printf("введите %d чисел, не должно быть ни одного нуля \n",n);

    for(i=0;i<n;i++){

        scanf("%d",&arreglo[i]);

        if(arreglo[i] == 0){

            counter++;

        }

    }


}while(counter != 0);

/*for(i=0;i<n;i++){

    printf("%d",arreglo[i]);

}*/

for(i=0;i<n;i++){

    if(arreglo[i]< arreglo[n-1]){
        printf("первое число, которое удавлетворяет неравенство Ak < An равно: %d \n",arreglo[i]);
        i=n;
    }

}


}