#include <stdio.h>
#include <string.h>

int main(){

int ZonaHoraria;

printf("эта программа даёт стоимость зависит от зоны от I до VI \n");



do{
    printf("введите номер торифоной зоны\n");
    scanf("%d",&ZonaHoraria);
}while(ZonaHoraria != 1 && ZonaHoraria != 2 && ZonaHoraria != 3 && ZonaHoraria != 4 && ZonaHoraria != 5 && ZonaHoraria != 6);




//printf("usted inserto %s \n",ZonaHoraria);
//printf("стоимость минуты разговора по телефону равна: $2");

switch(ZonaHoraria){

    case 1 : printf("стоимость минуты разговора по телефону равна: $10"); break;
    case 2 : printf("стоимость минуты разговора по телефону равна: $20"); break;
    case 3 : printf("стоимость минуты разговора по телефону равна: $30"); break;
    case 4 : printf("стоимость минуты разговора по телефону равна: $40"); break;
    case 5 : printf("стоимость минуты разговора по телефону равна: $50"); break;
    case 6 : printf("стоимость минуты разговора по телефону равна: $60"); break;


}



} 