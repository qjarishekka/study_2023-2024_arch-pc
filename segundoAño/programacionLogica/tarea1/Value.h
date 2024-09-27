#include <iostream>
#include <string>
using namespace std;

class Value{
public:
	virtual void out() = 0;
	virtual float sum() = 0;
	virtual float average() = 0;
	virtual int counter(Value * value) = 0;
};

class Atom : public Value{
public:
	float number;
	//float number(){ return stof(val); }
	
	Atom(float number){
		this->number = number;
	}
	
	void out() override {
		cout << number;
	}
	
	float sum() override {
		return number;
	}


	float average() override{
		return number;
	}

	int counter(Value * value) override {
		return 1;
	}
	
	
};

class Pair : public Value{
public:
	Value *left, *right;
	
	Pair(Value *left, Value *right){
		this->left = left;
		this->right = right;
	}
	
	void out() override {
		cout << '(';
		left->out();
		cout << ", ";
		right->out();
		cout << ')';
	}
	
	float sum() override {
		return left->sum() + right->sum();
	}

	int counter(Value * value) override{

		int counter = 0;

		if( (Value)value  )
		counter += value->counter( value );


		

	}

	float average() override{

		this->sum(); 

	}
};
	
