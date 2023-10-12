#include <stdio.h>
//Вывести названия дня по его номеру
int main(){
int day;
printf("Программа выводит названия дня недели по его номеру\n");
do{
printf("Введите номер дня недели от 1 до 7");
scanf("%d",&day);
}while(day <= 1 || day >= 7);
switch (day){
case	1 :	printf("Понедельник\n"); break;
case 2 : printf("Вторник\n"); break;
case 3 : printf("Среда\n");   break;
case 4 : printf("Четверг\n"); break;
case 5 : printf("Пятница\n"); break;
case 6 : printf("Суббота\n"); break;
case 7 :	printf("Воскресенье\n"); break;
}
}

