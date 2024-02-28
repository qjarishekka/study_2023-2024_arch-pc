#include <iostream>

using namespace std;

int X = 0;

struct student{
int id;
string names;
string group;
student *next;

};

int main(){

student *stlist = NULL, *tmp;




for(int i = 0; i<3 ;i++){

tmp = new student;

cout<< "введите ID" << "\n";
cin >> tmp -> id;
cout << "введите имя" << "\n";
cin >> tmp -> names;
cout << "введите группу" << "\n";
cin >> tmp -> group;

tmp -> next = stlist;
stlist = tmp;

}


tmp = stlist;

while(tmp != NULL){

    cout << "Студент" << tmp -> names <<"\n";

    cout << "ID=" << tmp->id << "\n";

    tmp = tmp -> next;

}

    return 0;

}
