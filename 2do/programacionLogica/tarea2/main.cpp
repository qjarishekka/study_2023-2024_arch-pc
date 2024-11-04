#include <iostream>
#include <fstream>
#include <string>
#include "Complier.h"

using namespace std;

Value* parse(string line){
	// отбросить пробелы
	int br = 0;
	int coma = -1;
	bool outter_brackets = line[0] == '(';				
	for(int i = 0; i < (int)line.length(); i++){  		//почему (int)?			
		if(line[i] == '(')										
			br++;
		if(line[i] == ')')								// ( 1 , ( 1 , 2 ) )	// 1 , ( 1 , 2)
			br--;
		if(br == 0 && i < (int)line.length() - 1){
			outter_brackets = false;
		}
		if(br == 0 && line[i] == ',')
			coma = i;
	}
	if(outter_brackets) 
		return parse(line.substr(1, line.length() - 2));// 1 , ( 1 , 2 )
	if(coma == -1){
		if(line == "null"){
			return nullptr;
		}
		return new Atom(line);
	}
	Value* left = parse(line.substr(0, coma));
	Value* right = parse(line.substr(coma + 1));
	return new Pair(left, right); 
}

Value* parseFormula(string line){
	// нужно снятие верхних скобок
	char* ops = new char[4]{'+', '-', '*', '/'}; // набор операций
	int id = -1; // позиция симовола оператора
	int oI = 0;
	while(id == -1 && oI < 4){
		for(int i = 0; i < (int)line.length(); i++){
			// добавить расчёт глубины скобок и игнорировать операции в скобках
			if(line[i] == ops[oI]){
				id = i;
			}
		}
		oI++;
	}
	if(id == -1) // если операций не найдено
		return new Atom(line); // вернём Атом от всей строки
	// иначе (т.е. операция нашлась)
	//						 						line[:id] // line[id+1:]
	return new Pair(new Atom( { line[id] } ), new Pair(parseFormula(line.substr(0, id)),
												parseFormula(line.substr(id+1))));
}

int main(){
	
	Complier* comp = new Complier();
	ifstream fin;
	fin.open("prog.txt");
	string text;
	getline(fin, text);
	cout << text;
	fin.close();
	Value* programm = parse(text);
	//programm -> out();
	/*
	Value* programm = new Pair(new Atom("block"), new Pair( new Pair( new Atom("out"), new Atom("Hello")),
												new Pair( new Pair( new Atom("out"), new Atom("World")),
														nullptr)));
	*/
	//programm -> out();
	cout << endl;

	comp->run(programm);
	cout<<endl;
	
	return 0;
}
