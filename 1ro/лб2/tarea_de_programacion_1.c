#include <stdio.h>
int main()
{
    int a, b, c,max ,min;

    printf("введите 3 числа: \n");
    
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if(a >= b && a >= c){
        printf("набольшее число:%d\n",a);
    }
        else{
            if(b >= c && b >= c){
                printf("наибольшее число:%d\n",b);
            }
                else{
                    printf("наибольшее число:%d\n",c);
                }

        }
    
      if(a <= b && a <= c){
        printf("наименшее число:%d\n",a);
    }
        else{
            if(b <= c && b <= c){
                printf("наименшее число:%d\n",b);
            }
                else{
                    printf("наименшее число:%d\n",c);
                }

        } 

}