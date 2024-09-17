#include <iostream>
#include "value.h"

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