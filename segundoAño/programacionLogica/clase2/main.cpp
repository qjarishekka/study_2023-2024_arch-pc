#include <iostream>
#include "value.h"
#include <string>

using namespace std;

int main(){

Atom* a = new Atom(1.0f);

Pair * p = new Pair(a, new Atom(2));

a->print();
cout<<endl;

p->print();
cout<<endl;

cout << p->sum()<< endl;

Value *v1 = new Pair( new Atom(1.5) , new Pair(new Atom(1.3), new Atom(-3) ) );

cout<< v1->sum()<<endl;


return 0;
}

Value * parse(string str){

if( str[0] == '(' && str[str.length()-1] == ')'){

return parse( str.substr(1,str.length()-2));

}

if( str.find(',') == -1        ){

    return new Atom(stof(str));

}

int coma = str.find(',');

return Pair(parse(str.substr(0,coma)),parse(str.substr(coma)));

}