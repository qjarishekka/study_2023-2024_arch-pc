#include <stdio.h>
#include <string.h>

int main(){

char ZonaHoraria[3];

printf("эта программа даёт стоимость зависит от зоны от I до VI \n ");

do{
    printf("введите номер торифоной зоны\n");
    scanf("%s",ZonaHoraria);
}while(strcmp(ZonaHoraria,"I") && strcmp(ZonaHoraria,"II") && strcmp(ZonaHoraria,"III") && strcmp(ZonaHoraria,"IV") && strcmp(ZonaHoraria,"V") && strcmp(ZonaHoraria,"VI"));

//printf("usted inserto %s \n",ZonaHoraria);

if(strcmp(ZonaHoraria,"I")){

    if(strcmp(ZonaHoraria,"II")){

        if(strcmp(ZonaHoraria,"III")){

            if(strcmp(ZonaHoraria,"IV")){

                if(strcmp(ZonaHoraria,"V")){

                    if(strcmp(ZonaHoraria,"VI")){



                    }else{
                        printf("цена равна $6\n");
                    }

                }else{
                    printf("цена равна $5\n");
                }

            }else{
                printf("цена равна $4\n");
            }

        }else{
            printf("цена равна $3\n");
        }

    }else{
    printf("цена равна $2\n");
    }

}else{
    printf("цена равна $1\n");
}



} 