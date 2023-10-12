#include <stdio.h>

int main(){

int NumeroEstudiante = 0;

printf("это программа даёт фамилю нашей группы \n ");

do{

    printf("введите номер студента от 1 до 29\n");
    scanf("%d", NumeroEstudiante);


}while(NumeroEstudiante > 30 && NumeroEstudiante < 1 );

switch(NumeroEstudiante){
case 1 : printf("Абдул Васе Файсал Ахмад");break;
case 2 : printf("Андреева Софья Владимировна");break;
case 3 : printf("Андрюшин Никита Сергеевич");break;
case 4 : printf("Астахов Эдуард Алексеевич");break;
case 5 : printf("Барабаш Полина Витальевна");break;
case 6 : printf("Бегин Станислав Александрович");break;
case 7 : printf("Белов Алексей Дмитриевич");break;
case 8 : printf("Богаткина Алёна Александровна");break;
case 9 : printf("Бызова Мария Олеговна");break;
case 10 : printf("Верниковская Екатерина Андреевна");break;
case 11 : printf("Габралян Георгий Александрович");break;
case 12 : printf("Гадаборшев Заур Закреевич");break;
case 13 : printf("Газизянов Владислав Альбертович");break;
case 14 : printf("Гурылев Артем Андреевич");break;
case 15 : printf("Жаворонков Кирилл Александрович");break;
case 16 : printf("Жибицкая Евгения Дмитриевна");break;
case 17 : printf("Земелан Марва Халил Абдулрашид Али");break;
case 18 : printf("Иванов Сергей Владимирович");break;
case 19 : printf("Калашникова Ольга Сергеевна");break;
case 20 : printf("Кализая Арсе Кхари Жекка");break;
case 21 : printf("Кобзев Дмитрий Константинович");break;
case 22 : printf("Колонтырский Илья Русланович");break;
case 23 : printf("Комягин Андрей Николаевич"); break;
case 24 : printf("Куашев Бетал Муратович"); break;
case 25 : printf("Кубанов Мухаммад Азрет-Алиевич"); break;
case 26 : printf("Лазарев Даниил Михайлович"); break;
case 27 : printf("Лемуш Гонсалвеш Дуарти Афонсу Де"); break;
case 28 : printf("Луговцов Петр Николаевич"); break;
case 29 : printf("Мантуров Татархан Бесланович"); break;
//case default : printf("студент не существует");
}


}