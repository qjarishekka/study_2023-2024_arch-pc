#include <iostream>
#include <string>
#include "Value.h"
#include <typeinfo>

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

struct VarTemp{
	string name;
	string type;
	string value;

	VarTemp(){
		name="temp";
		type="";
		value="";
	}
	
	VarTemp(string name, string type, string value){
		this->name = name;
		this->type = type;
		this->value = value;
	}
	~VarTemp(){};
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

	VarTemp varTemp;
	
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

		while(temp->next != nullptr && temp->name!=var){
			temp = temp->next;
		}

		if(temp->name != var){
			return false;
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

	Var* getVariable(string name){
		Var * temp = headVar;

		while(temp !=nullptr && temp->name != name){
			temp= temp->next;
		}

		return temp;
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




//(for,( (block, ( (var,(nombre,(tipo,valor))) ,null ))   , (valorIncremtacion,(tope,body))  ))



	void cicloFor(Value* val){
		
		Pair*p = (Pair*)val;

		run(p->left);

		int valorIncremento=stoi(((Atom*)(((Pair*)(p->right))->left))->val)  ;
		int tope = stoi(((Atom*)(((Pair*)((Pair*)(((Pair*)(p->right))->right)))->left))->val);
		string variableCambiante=  //encontrar el nombre de la variable
		((Atom*)(((Pair*)(((Pair*)(((Pair*)(((Pair*)(p->left))->right))->left))->right))->left))->val;
		Var* Variable = getVariable(variableCambiante);

		if(Variable->type != "int"){
			cout<<"ошибка: переменная в функции for не может быть типом "<<Variable->type<<endl;
			exit(1);
		}
		for(int i =stoi(Variable->value);i<tope ; i+=valorIncremento ){
				run(((Pair*)(((Pair*)(p->right))->right))->right);
				Variable->value = to_string(stoi(Variable->value) + valorIncremento);		
		}
	}

//dejamos de lado temporalmente hasta desarrollar los signos
//( while , (signo,(va1,var2)) )
	void cicloWhile(Value* val){

	}

// nota mental cambiar los mensajes de errores
	void suma(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.value = to_string(stof(leftValue) + stof(rightValue));

		}else if( !isVariable(leftValue) && isVariable(rightValue) ){



		}



		


/* 		Var* right = getVariable(rightValue);
		Var* left = getVariable(leftValue);

		cout<< right->name<<endl;

		if( right->type =="string" || left->type =="string" ){
			cout<<"нельзя складивать переменные типа string"<<endl;
			exit(1);
		}		

		if( (getVariable(rightValue))->type != (getVariable(leftValue))->type){
			cout<<"нельзя складивать"<<(getVariable(rightValue))->type <<"и" <<(getVariable(leftValue))->type <<endl;
			exit(1);
		}

		if(isVariable(rightValue)&&isVariable(leftValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

					if( (getVariable(rightValue))->type == "int"){
						varTemp.value = to_string(stoi(Rvar) + stoi(Lvar));
						varTemp.type = "int";
					}

					if( (getVariable(rightValue))->type == "float"){

						varTemp.value = to_string(stof(Rvar) + stof(Lvar));
						varTemp.type="float";
					}
		}
		 */
	}



	void igual(Value * val){\

		Pair* p = (Pair*)val;

		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue)){
			cout<<"ошибка: нельзя уравнять что-но на nonvariable"<<endl;
			exit(1);
		}else{
			run(p->right);

			Var *tmp = getVariable(leftValue);
			tmp->value = varTemp.value;
		}
	}






	void run(Value* programm){ // исполнения кода
		if(programm->isAtom()){
			//programm->out();
			return;
		}
		Pair* p = (Pair*)programm;
		if(p->left->isAtom()){
			Atom* a = (Atom*)p->left;
			Atom* b = (Atom*)p->right;
			if(a->val == "var"){
				addVar(p->right);
			}
			if(a->val == "def"){
				addFunc(p->right);
			}
			if(a->val == "out"){

				Atom* signo = (Atom*)((Pair*)((Pair*)p->right)->left)  ;
				if( ((Atom*)signo)->val  == "+" ){
					run(p->right);
					cout<<varTemp.value<<endl;

				}else if(isVariable(b->val)){
					//cout<<"a->val vale "<<b->val<<endl;
					//encontrar la variable que se esta solicitando
					out(findValueOfVariable(b->val));
					cout<<endl;
				}else{
					out(p->right);	
					cout<<endl;				
				}
			}

			if(a->val == "+"){
				suma(p->right);
			}

			if(a->val =="-"){
				//resta(p->right);
			}

			if(a->val =="*"){
				//multiplicacion(p->right);
			}

			if(a->val =="/"){
				//division(p->right);
			}
			if(a->val =="="){
				igual(p->right);
			}




			if(a->val == "block"){
				Pair* next = (Pair*)p->right;
				while(next != nullptr){ // пока не кончился список команд
					run(next->left); // выполним голову списка
					next = (Pair*)next->right; // дальше работаем с хвостом списка
				}
			}



			//(for,( (block,( (var,(nombre,(tipo,valor))),null )) , (valorIncremtacion,(tope,body))    ))
			if(a->val == "for"){
				cicloFor(p->right);
			}
			if(a->val == "while"){
				cicloWhile(p->right);
			}



			Func* func = headFunc;
			while(func != nullptr){
				if(func->name == a->val){
					//declarar las variables
					if(func->argsCount!=0){
						if(p->right == nullptr){
							std::cout<<"ошибка при вызове функции, нет нашлись необходимых переменных"<<endl;
							exit(1);
						}else{
							run(p->right);
						}
					}
					run(func->body);
					return;
				}
				func = func->next;
			}					
		}
		
	}
};
