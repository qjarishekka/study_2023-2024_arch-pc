#include <iostream>
#include <string>
#include "Value.h"

using namespace std;

struct Var{
	string name;
	string type;
	string value;
	Var* next;	
	
	Var(string name, string type, string value){
		this->name = name;
		this->type = type;
		this->value = value;
		this->next = nullptr;
	}
};

struct Func{
	string name;
	string type;
	int argsCount;
	string* args;
	Value* body;
	Func* next;	
	
	Func(string name, string type, int argsCount, string* args, Value* body){
		this->name = name;
		this->type = type;
		this->argsCount = argsCount;
		this->args = args;
		this->body = body;
		this->next = nullptr;
	}
};

class Complier{
public:	
	Var* headVar;
	
	Func* headFunc;
	
	Complier(){
		headVar = nullptr;
		headFunc = nullptr;
	}
	// (out, ...val...)
	void out(Value* val){
		val->out();
	}
	
	Var** lastVar(){ // конец списка переменных
		Var** last = &headVar;
		while(*last != nullptr){
			last = &((*last)->next);
		}
		return last;
	}

	bool isVariable(string var){

		if(headVar == nullptr){
			return false;
		}

		Var* temp = headVar;

		while(temp->next != nullptr){
			if(temp->name != var){
				return false;
			}
			temp = temp->next;
		} 
		return true;
	}

	Value* findValueOfVariable(string name){
		Var * temp = headVar;
		while(temp->next != nullptr && temp->name != name){
				temp = temp->next;
		}

		return new Atom(temp->value);

	}


	
	// (var, (name, (type, value)))
	void addVar(Value* var){ // добавление переменной
		Var** last = lastVar();
		string name = ((Atom*)((Pair*)var)->left)->val;
		string type = ((Atom*)((Pair*)((Pair*)var)->right)->left)->val;
		string value = ((Atom*)((Pair*)((Pair*)var)->right)->right)->val;
		*last = new Var(name, type, value);
	}
	
	Func** lastFunc(){ // конец списка функций
		Func** last = &headFunc;
		while(*last != nullptr){
			last = &((*last)->next);
		}
		return last;
	}
	// (def, ((name, type), ((args), (body)) ) )
	void addFunc(Value* val){ // добавление функции
		Func** last = lastFunc();
		Pair* pair = (Pair*) val;
		Pair* leftPair = (Pair*) pair->left;
		Pair* rightPair = (Pair*) pair->right;
		string name = ((Atom*)leftPair->left)->val;
		string type = ((Atom*)leftPair->right)->val;
		Pair* argsPair = (Pair*)rightPair->left;
		int argsCount;
		string* argsArray;
		if(argsPair == nullptr){
			argsCount = 0;
			argsArray = nullptr;	
		}else{
			argsCount = argsPair->len();
			argsArray = new string[argsCount];
			for(int i = 0; i < argsCount; i++){
				argsArray[i] = ((Atom*)argsPair->left)->val;
				argsPair = (Pair*)argsPair->right; // переходим в хвост
			}
		}
		Value* body = rightPair->right;
		*last = new Func(name, type, argsCount, argsArray, body);
	} 
	
	// (def, ( (f, void), ( ( int:x1 , (int:x2, null) ) , (...) ) ) )




	void cicloFor(Value* val){
	}



	void run(Value* programm){ // исполнения кода
		if(programm->isAtom()){
			//programm->out();
			return;
		}
		Pair* p = (Pair*)programm;
		if(p->left->isAtom()){
			Atom* a = (Atom*)p->left;
			if(a->val == "var"){
				addVar(p->right);
			}
			if(a->val == "def"){
				addFunc(p->right);
			}
			if(a->val == "out"){

				if(isVariable(a->val)){
					out(findValueOfVariable(a->val));
				}else{
					out(p->right);					
				}

			}
			if(a->val == "block"){
				Pair* next = (Pair*)p->right;
				while(next != nullptr){ // пока не кончился список команд
					run(next->left); // выполним голову списка
					next = (Pair*)next->right; // дальше работаем с хвостом списка
				}
			}

			// ( for, ( (variable i,tope) , (factorDeCrecimiento,body)   )  )
			if(a->val == "for"){
				cicloFor(p->right);
			}
			Func* func = headFunc;
			while(func != nullptr){

				if(func->name == a->val){

					if(func->argsCount!=0){
						
					}
					
/* 					if(p->right->isPair()){
						run(p->right);
					} */
					
					run(func->body);
					return;
				}
				func = func->next;
			}					
		}
		
	}
};
