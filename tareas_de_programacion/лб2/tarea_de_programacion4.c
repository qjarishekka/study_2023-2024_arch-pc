#include <stdio.h>

int main() {

int a = 0;
int b = 0;
int c = 0;

printf("это программа даёт порядок чисел: \n");

do{

    printf("введите 3 числа, два из них должны быть одинаковые: \n");

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
}while(a != b && a != c && b != c);

//printf("a = %d, b = %d, c = %d \n",a,b,c);

if(a == b && b == c && a == c){

    printf("1º %d,  1º %d,  1º %d \n",a,b,c);

}else{
        if(a == b){

            if(a < c){
                printf("1º %d,  1º %d,  2º %d \n",a,b,c);
            }else{
                printf("1º %d,  2º %d,  2º %d\n",c,b,a);
            }

        }else{

            if(b == c){

                if(a < b){
                    printf("1º %d,  2º %d,  2º %d\n",a,c,b);
                }else{
                    printf("1º %d,  1º %d,  2º %d\n",c,b,a);
                }

            }else{

                if(a == c){

                    if(a < b){
                        printf("1º %d,  1º %d,  2º %d\n",a,c,b);
                    }else{
                        printf("1º %d,  2º %d,  2º %d\n",b,c,a);
                    }

                }

            }
        }

        }

        }