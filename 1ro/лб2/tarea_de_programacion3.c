#include<stdio.h>

int main(){

int a, b, c, d;
int mayor1 = 0;
int mayor2= 0;
int suma = 0;

printf("эта программа даёт сумму двух больших чисел\n");

printf("напишите 4 числа: \n");

scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
scanf("%d",&d);

if(a >= b && a >= c && a >=d){
    mayor1 = a;
    
    
    if(b>=c && b>=d){
        mayor2 =b;
    }else{
        if(c>=d){
            mayor2=c;
        }else{
            mayor2=d;
        }
    }


}else{
    if(b>=c && b>=d){
        mayor1=b;


        if(a>=c && a>=d){
            mayor2 =a;
        }else{
            if(c>=d){
                mayor2=c;
            }else{
                mayor2=d;
            }
        }


    }else{
        if(c>=d){
            mayor1=c;
            
            
            if(a>=b && a>=d){
                mayor2 =a;
            }else{
                if(b>=d){
                    mayor2=b;
                }else{
                    mayor2=d;
                }
            }


        }else{
            mayor1=d;
            
            
            if(a>=b && a>=c){
                mayor2 =a;
            }else{
                if(b>=c){
                    mayor2=b;
                }else{
                    mayor2=c;
                }
            }


        }
    }
}

suma = mayor1 + mayor2;

printf("%d и %d наибольшие числа и сумма этих чисел равен %d\n",mayor1,mayor2,suma);




}