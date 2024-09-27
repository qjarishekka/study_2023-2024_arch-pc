#include<iostream>
#include <string>


class Value{
    public:
    virtual float calc()= 0;

};

class Atom: public Value{
public:
std::string val;

Atom(float val){
		this->val = val;
	}


float calc() override{

    return std::stof(val);
}


};

class Pair: public Value{
public:

Value *left, *right;
	
	Pair(Value *left, Value *right){
		this->left = left;
		this->right = right;
	}



float calc() override{


Atom a = (Atom)(left);

Pair p = (Pair)(right);

switch( a.val  ){

case "+":

    return p.left->calc() + p.right->calc();


};


}

};