#include<iostream>

class Value{

public:
virtual void print() = 0;


};

class Atom : public Value{

public:

    float num;

    Atom(float n){
        num = n;
    }


    void print() override {

        std::cout<<num;

    }
};

class Pair : Value {

public:
Value* left;
Value* right;

Pair(Atom* l, Atom* r){

left = l;
right = r;

}


void print(){

std::cout<<"(";
left->print();
std::cout<< ",";
right->print();
std::cout<<")";

}

};