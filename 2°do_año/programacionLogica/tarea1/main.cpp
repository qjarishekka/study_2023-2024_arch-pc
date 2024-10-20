#include <iostream>
#include <string>
#include "Value.h"
using namespace std;

Value* parse(string line){
	// отбросить пробелы
	if(line[0] == '(' && line[line.length() - 1] == ')') // отбросим внешние скобки
		return parse(line.substr(1, line.length() - 2));
	int coma = (int)line.find(',');
	if(coma == -1) // stof - string  to float - строка в нецелое число
		return new Atom(stof(line));
	return new Pair(parse(line.substr(0, coma)), parse(line.substr(coma + 1))); 
}



int main(){


/* 	Value* v1 = new Atom(0);
	v1->out();
	cout << endl << "Sum = " << v1->sum() << endl;
	v1 = new Pair(new Atom(1), new Atom(2)); // (1, 2)
	v1->out();
	cout << endl << "Sum = " << v1->sum() << endl;
	v1 = new Pair(new Atom(10), v1);
	v1->out();
	cout << endl << "Sum = " << v1->sum() << endl;
	v1 = parse("1, 4");
	v1->out();
	cout << endl; */

	Value * v3 = new Pair( new Atom(9), new Pair ( new Pair(new Atom(10), new Atom(4) )			, new Pair( new Atom(6), new Atom(8))		));

	cout << "Value: ";

	v3->out();

	cout<<endl; 

	cout<< "количество чисел: "<< v3->counter() << endl;

	cout<< "среднее число: " << v3->average()<<endl;

	cout << "максимальное отклонение: " << v3->deviationMax( v3->average() )<<endl;

	cout << "минимальное отклонение: " << v3->deviationMin( v3->average() )<<endl;



	return 0;
}
