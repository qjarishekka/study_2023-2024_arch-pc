#include <stdio.h>

int main() {

int NombreCarta;

printf("эта программа определяет достоинство соответствующей карты\n ");

do{
    printf("напишите номер карта от 11 до 14: \n");
    scanf("%d\n",&NombreCarta);

}
    while(11<= NombreCarta || NombreCarta <=14);
