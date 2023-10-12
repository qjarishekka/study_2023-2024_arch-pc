#include <stdio.h>
#include <string.h>
//Вывести названия дня по его номеру
int main(){
char a[3];


/*
char I[3] = "I";
char II[3] = "II";
char III[3] = "III";
char IV[3] = "IV";
char V[3] = "V";
char VI[3] = "VI";
*/

do{
printf("hola inserte numero romano \n");
scanf("%s",a);

}while(strcmp(a,"I") && strcmp(a,"II") && strcmp(a,"III") && strcmp(a,"IV") && strcmp(a,"V") && strcmp(a,"VI"));

printf("usted inserto %s \n",a);

}

