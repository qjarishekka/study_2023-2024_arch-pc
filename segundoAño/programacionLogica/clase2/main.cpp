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






return 0;
}