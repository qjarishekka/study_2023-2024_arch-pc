#include <stdio.h>

int main(){

int NumeroEstudiante = 0;

printf("это программа даёт фамилю нашей группы\n");

do{

    printf("введите номер студента от 1 до 29\n");
    scanf("%d", &NumeroEstudiante);


}while(NumeroEstudiante > 29 || NumeroEstudiante < 1 );

switch(NumeroEstudiante){
case 1 : printf("Абдул Васе Файсал Ахмад\n");break;
case 2 : printf("Андреева Софья Владимировна\n");break;
case 3 : printf("Андрюшин Никита Сергеевич\n");break;
case 4 : printf("Астахов Эдуард Алексеевич\n");break;
case 5 : printf("Барабаш Полина Витальевна\n");break;
case 6 : printf("Бегин Станислав Александрович\n");break;
case 7 : printf("Белов Алексей Дмитриевич\n");break;
case 8 : printf("Богаткина Алёна Александровна\n");break;
case 9 : printf("Бызова Мария Олеговна\n");break;
case 10 : printf("Верниковская Екатерина Андреевна\n");break;
case 11 : printf("Габралян Георгий Александрович\n");break;
case 12 : printf("Гадаборшев Заур Закреевич\n");break;
case 13 : printf("Газизянов Владислав Альбертович\n");break;
case 14 : printf("Гурылев Артем Андреевич\n");break;
case 15 : printf("Жаворонков Кирилл Александрович\n");break;
case 16 : printf("Жибицкая Евгения Дмитриевна\n");break;
case 17 : printf("Земелан Марва Халил Абдулрашид Али\n");break;
case 18 : printf("Иванов Сергей Владимирович\n");break;
case 19 : printf("Калашникова Ольга Сергеевна\n");break;
case 20 : printf("Кализая Арсе Кхари Жекка\n");break;
case 21 : printf("Кобзев Дмитрий Константинович\n");break;
case 22 : printf("Колонтырский Илья Русланович\n");break;
case 23 : printf("Комягин Андрей Николаевич\n"); break;
case 24 : printf("Куашев Бетал Муратович\n"); break;
case 25 : printf("Кубанов Мухаммад Азрет-Алиевич\n"); break;
case 26 : printf("Лазарев Даниил Михайлович\n"); break;
case 27 : printf("Лемуш Гонсалвеш Дуарти Афонсу Де\n"); break;
case 28 : printf("Луговцов Петр Николаевич\n"); break;
case 29 : printf("Мантуров Татархан Бесланович\n"); break;
//case default : printf("студент не существует\n");
}


}