#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Value{
public:
	virtual void out() = 0;

	virtual float sum() = 0;
	virtual float average() = 0;
	virtual int counter() = 0;
	virtual float deviationMax( float average) = 0;
	virtual float deviationMin( float average) = 0;
	virtual Value* replaceVar(std::string o , std::string n) = 0;		
};

class Atom : public Value{
public:
	float number;
	std::string val;
	//float number(){ return stof(val); }
	
	Atom(float number){
		this->number = number;
	}

	Atom(std::string n){

		this ->val = n;
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

	int counter() override {
		return 1;
	}

	float deviationMax( float average) override{
		
		return number;
	}

	float deviationMin( float average) override{
		return number;
	}

	Value* replaceVar(string o , string n) override{

		//return new Atom(val.replace(o,n));

		std::string new_val = std::to_string(number);

		if(number == 0){
			return new Atom(n);
		}



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

	int counter() override{
		int counter = 0;
		counter += left->counter() + right->counter();
		return counter;
	}

	float average() override{
		return this->sum() / this->counter();
	}

	float deviationMax( float average ) override{

		float devMax;
		
		float difR = abs(average - right->deviationMax( average) );
		float difL = abs(average - left->deviationMax( average));


		if(difL < difR ){

			devMax = right->deviationMax( average);

		}else{
			devMax = left->deviationMax( average);
		}
		return devMax;
	} 


	float deviationMin( float average ) override{

		float devMin;
		float difR = abs(average - right->deviationMin( average) );
		float difL = abs(average - left->deviationMin( average));

		if(difL > difR ){
			devMin = right->deviationMin( average);
		}else{
			devMin = left->deviationMin( average);
		}
		return devMin;
	} 

	Value * replaceVar(std::string o, std::string n) override{

		return new Pair(left->replaceVar(o,n), right->replaceVar(o,n));

	}
};
	


class Compiler{
	public:
	Variable*  headVar;

	Compiler(){}

	void run(Value* program){

		if( typeof(program) == (Atom*) ){

			cout<<((Atom*)program)->val<<endl;
			return;
		}

		Pair* p = (Pair*)program;

		if(typeid(p->left) == (Atom*) ){

			Atom*a = (Atom*)p->left;
			switch(a->val){
			
				case "var" : addVar(p->right);
				return;
				
				case "out": out(p->right);
				return;

				case "block" :
				if(typeof(p->right) == (Atom*)){

					run(p->right);
					return;
				}
			}


			Pair * next = (Pair*)p->right;
			while(next != nullptr){
				run(next->left);
				next = (Pair*)next->right;

			}
		}

	return;

}




void addVar(Value* var){

	Variable ** last = lastVar();
	*last = new Variable( ((Atom*)((Pair*)var)->left)->val , ((Atom*)(((Pair*)(((Pair*)(var))->right))->left))->val );


} 

Variable** lastVar(){  //doble ** sirve para devolver la direccion del puntero

	Variable** last = &headVar;

	while(*last != nullptr){
			last = &( (*last)->next );
	}

	return last;
}

void out(Value* val){

	val-> out();
}





};


struct Var{
Value* var;
Var* next;
};


struct Node{

	int value;
	Node * next;

};

struct Variable{

std::string name;
std::string type;
std::string value;
Variable* next;
};

Node* Vead;
