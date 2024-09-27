#include <iostream>
#include "value.h"
#include <string>

using namespace std;

Value * parse( string);

int main(){

Atom* a = new Atom(1.0f);

Pair * b = new Pair( a, new Pair( new Atom(2) , new Atom(7)  ));

Pair * p = new Pair(a, new Atom(2));

a->print();
cout<<endl;

p->print();
cout<<endl;

cout << p->sum()<< endl;

Value *v1 = new Pair( new Atom(1.5) , new Pair(new Atom(1.3), new Atom(-3) ) );

cout<< v1->sum()<<endl;

Value * ejemplo = parse("1,2");

cout<< ejemplo->sum()<<endl;

Pair ejemplo1( a , new Atom(5));

cout<< ejemplo1.sum()<<endl;

cout << b->sum() << endl;



return 0;
}


Value * parse(string str){

if( str[0] == '(' && str[ str.length()-1 ] == ')'){

return parse( str.substr(1,str.length()-2));

}

bool aux = str.rfind(",");

if(aux){

    return new Atom( std::stof(str));

}

int coma = str.find(',');

cout<<"aqui"<<endl;

return new Pair(parse(str.substr(0,coma)),parse(str.substr(coma)));

}