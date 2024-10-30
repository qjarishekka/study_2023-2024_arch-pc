#include <iostream>
#include <string>
#include <cmath>

using namespace std;


struct Node{
	int value;
	Node * next;
};

struct Var{
	string name;
	string type;
	string value;
	Value* var;
	Var* next;
};

struct Func{
	string name;
	string type;
	string* args;
	int argsCount;
	Value* body;
};

struct Variable{
	std::string name;
	std::string type;
	std::string value;
	Variable* next;
};

class Value{
public:
	virtual void out() = 0;

	virtual float sum() = 0;
	virtual float average() = 0;
	virtual int counter() = 0;
	virtual float deviationMax( float average) = 0;
	virtual float deviationMin( float average) = 0;
	virtual Value* replaceVar(std::string o , std::string n) = 0;	
	virtual bool isAtom()= 0;	
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
	bool isAtom() override{
		bool isAtom();
		return true;
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

	bool isAtom() override{
		bool isAtom();
		return false;
	}
	

	Value * replaceVar(std::string o, std::string n) override{

		return new Pair(left->replaceVar(o,n), right->replaceVar(o,n));

	}


};
	


class Compiler{
	public:
	Variable *  headVar;
	Func * headFunc;
	string space;

	Compiler(){}

	void run(Value* program){

		if( typeof(program) == (Atom*) ){

			cout<<((Atom*)program)->val<<endl;
			return;
		}

		Pair* p = (Pair*)program;

		if(typeof(p->left) == (Atom*) ){

			Atom*a = (Atom*)p->left;
			if(a->val == "var"){
			
				addVar(p->right);
			}

			if(a->val == "out"){
				
				out(p->right);
			}

			if(a->val == "block"){


				if(typeof(p->right) == (Atom*) ){
					run(p->right);
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


//hay que buscar como poner todos los para la estructura Variable

void addVar( Value* var){

	Variable ** last = lastVar();
	*last = new Variable{ ((Atom*)((Pair*)var)->left)->val /* , ((Atom*)(((Pair*)(((Pair*)(var))->right))->left))->val */ };


} 

Variable** lastVar(){  //doble ** sirve para devolver la direccion del puntero

	Variable** last = &headVar;

	while(*last != nullptr){
			last = &( (*last)->next );
	}

	return last;
}

void out( Value* val){

	val-> out();
}





};









Node* Head;




void addFunc (Value * val) {

	if( val->isAtom()){
		cout<< "Error";
		return;

	}

	Pair* pair = (Pair*)val;
	Pair* leftPair = (Pair*)pair->left;
	Pair* rightPair = (Pair*)pair->right;

	string name = ((Atom*)leftPair->left)->val;
	string type = ((Atom*)leftPair->right)->val;
	Pair* argsValue = ((Pair*)rightPair->left);

	int argsCount;
	if(argsValue== nullptr ){
		argsCount = 0;
	}else{
		argsCount = (to_string(argsCount)).length(); ///////si hay algun error mirar aca
	}

	Value * body = rightPair->right;
}
