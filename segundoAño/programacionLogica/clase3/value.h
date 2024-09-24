#include<iostream>

class Value{
    public:
    virtual float calc()= 0;

};

class Atom: public Value{
public:
std::string val;

float calc() override{

    return stof(val);
}


};

class Pair: public Value{
public:

Value *left, * right;

float calc() override{

Atom a = (Atom)(left);
Pair p = (Pair)(right);

switch(a.val){

case "+":

    return p.left->calc() + p.right->calc();


};


}

};