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
	bool flag;

	VarTemp(){
		name="temp";
		type="";
		value="";
		flag=true;
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
		cout<<endl;
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
		string value ="";

		if( (((Pair*)((Pair*)var)->right)->right)->isPair()){

			run(((Pair*)((Pair*)var)->right)->right);
			value = varTemp.value;
			type = varTemp.type;
		}else if(isVariable(((Atom*)((Pair*)((Pair*)var)->right)->right)->val)){
			
				value = getVariable(((Atom*)((Pair*)((Pair*)var)->right)->right)->val)->value;
				type = getVariable(((Atom*)((Pair*)((Pair*)var)->right)->right)->val)->type;

			}else{
				value = ((Atom*)((Pair*)((Pair*)var)->right)->right)->val;			
			}
		
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

	bool isFunction(string val){

		Func* functions = headFunc;

		while(functions->next != nullptr ){

			functions = functions->next;
		}

		if(functions->name == val){
			return true;
		}
		return false;
	}

//(for,( (block, ( (var,(nombre,(tipo,valor))) ,null ))   , (valorIncremtacion,(tope,body))  ))

	Func* getFunc(string name){

		Func * temp = headFunc;

		while(temp !=nullptr && temp->name != name){
			temp= temp->next;
		}

		return temp;

	}

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
//( while , ( (signo,(va1,var2)) , body)   )
	void cicloWhile(Value* val){

		Pair* p = (Pair*)val;

		run(p->left);
		//cout<<varTemp.flag<<endl;

		while(varTemp.flag){
			run(p->right);
			run(p->left);
		}

	}

//(if,((signo,(var1,var2)),(body)))
	void cicloIf(Value* val){

		Pair* p = (Pair*)val;

		run(p->left);
		if(varTemp.flag){
			run(p->left);
		}



	}

// nota mental cambiar los mensajes de errores
	void suma(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		//cout<<leftValue<<" "<<rightValue<<endl;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			//cout<<rightValue<<endl<<leftValue<<endl;
			varTemp.value = to_string(stof(leftValue) + stof(rightValue));
			varTemp.type = "float";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			
			

			if(isVariable(leftValue)&&isVariable(rightValue)){

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

			if(!isVariable(leftValue) && isVariable(rightValue)){
					string Rvar = (getVariable(rightValue))->value;

					if(getVariable(rightValue)->type == "int"){
						varTemp.value = to_string(stoi(Rvar) + stoi(leftValue));
						varTemp.type = "int";
					}
					if(getVariable(rightValue)->type == "float"){
						varTemp.value = to_string(stof(Rvar) + stof(leftValue));
						varTemp.type="float";
					}
			}

			if(isVariable(leftValue) && !isVariable(rightValue)){
					string Lvar = (getVariable(leftValue))->value;

					if(getVariable(leftValue)->type == "int"){
						varTemp.value = to_string(stoi(Lvar) + stoi(rightValue));
						varTemp.type = "int";
					}
					if(getVariable(leftValue)->type == "float"){
						varTemp.value = to_string(stof(Lvar) + stof(rightValue));
						varTemp.type="float";
					}
			}				
		}
	}

	void resta(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			//cout<<rightValue<<endl<<leftValue<<endl;
			varTemp.value = to_string(stof(leftValue) - stof(rightValue));
			varTemp.type="float";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){



			if(isVariable(leftValue)&&isVariable(rightValue)){

					string Rvar = (getVariable(rightValue))->value;
					string Lvar = (getVariable(leftValue))->value;

						if( (getVariable(rightValue))->type == "int"){
							varTemp.value = to_string(stoi(Lvar) - stoi(Rvar));
							varTemp.type = "int";
						}

						if( (getVariable(rightValue))->type == "float"){
							varTemp.value = to_string(stof(Lvar) - stof(Rvar));
							varTemp.type="float";
						}
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){
					string Rvar = (getVariable(rightValue))->value;

					if(getVariable(rightValue)->type == "int"){
						varTemp.value = to_string( stoi(leftValue) - stoi(Rvar) );
						varTemp.type = "int";
					}
					if(getVariable(rightValue)->type == "float"){
						varTemp.value = to_string( stof(leftValue) - stof(Rvar) );
						varTemp.type="float";
					}
			}

			if(isVariable(leftValue) && !isVariable(rightValue)){
					string Lvar = (getVariable(leftValue))->value;

					if(getVariable(leftValue)->type == "int"){
						varTemp.value = to_string(stoi(Lvar) - stoi(rightValue));
						varTemp.type = "int";
					}
					if(getVariable(leftValue)->type == "float"){
						varTemp.value = to_string(stof(Lvar) - stof(rightValue));
						varTemp.type="float";
					}
			}				
		}
	}

	void multiplicacion(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			//cout<<rightValue<<endl<<leftValue<<endl;
			varTemp.value = to_string(stof(leftValue) * stof(rightValue));
			varTemp.type="float";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){



			if(isVariable(leftValue)&&isVariable(rightValue)){

					string Rvar = (getVariable(rightValue))->value;
					string Lvar = (getVariable(leftValue))->value;

					//cout<<Lvar<<endl<<Rvar<<endl;

						if( (getVariable(rightValue))->type == "int"){
							varTemp.value = to_string(stoi(Rvar) * stoi(Lvar));
							varTemp.type = "int";
						}

						if( (getVariable(rightValue))->type == "float"){
							varTemp.value = to_string(stof(Rvar) * stof(Lvar));
							varTemp.type="float";
						}
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){
					string Rvar = (getVariable(rightValue))->value;

					if(getVariable(rightValue)->type == "int"){
						varTemp.value = to_string(stoi(Rvar) * stoi(leftValue));
						varTemp.type = "int";
					}
					if(getVariable(rightValue)->type == "float"){
						varTemp.value = to_string(stof(Rvar) * stof(leftValue));
						varTemp.type="float";
					}
			}

			if(isVariable(leftValue) && !isVariable(rightValue)){
					string Lvar = (getVariable(leftValue))->value;

					if(getVariable(leftValue)->type == "int"){
						varTemp.value = to_string(stoi(Lvar) * stoi(rightValue));
						varTemp.type = "int";
					}
					if(getVariable(leftValue)->type == "float"){
						varTemp.value = to_string(stof(Lvar) * stof(rightValue));
						varTemp.type="float";
					}
			}				
		}
	}

	void division(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			//cout<<rightValue<<endl<<leftValue<<endl;
			varTemp.value = to_string(stof(leftValue) / stof(rightValue));
			varTemp.type="float";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){


			if(isVariable(leftValue)&&isVariable(rightValue)){

					string Rvar = (getVariable(rightValue))->value;
					string Lvar = (getVariable(leftValue))->value;

						if( (getVariable(rightValue))->type == "int"){
							varTemp.value = to_string(stoi(Lvar) / stoi(Rvar));
							varTemp.type = "int";
						}

						if( (getVariable(rightValue))->type == "float"){
							varTemp.value = to_string(stof(Lvar) / stof(Rvar));
							varTemp.type="float";
						}
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){
					string Rvar = (getVariable(rightValue))->value;

					if(getVariable(rightValue)->type == "int"){
						varTemp.value = to_string(  stoi(leftValue) / stoi(Rvar));
						varTemp.type = "int";
						
					}
					if(getVariable(rightValue)->type == "float"){
						varTemp.value = to_string(  stof(leftValue) /stof(Rvar));
						varTemp.type="float";
			
					}
			}

			if(isVariable(leftValue) && !isVariable(rightValue)){
					string Lvar = (getVariable(leftValue))->value;

					if(getVariable(leftValue)->type == "int"){
						varTemp.value = to_string(stoi(Lvar) / stoi(rightValue));
						varTemp.type = "int";

					}
					if(getVariable(leftValue)->type == "float"){
						varTemp.value = to_string(stof(Lvar) / stof(rightValue));
						varTemp.type="float";
					}
			}				
		}
	}

	void resto(Value* val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			//cout<<rightValue<<endl<<leftValue<<endl;
			varTemp.value = to_string(   stoi(leftValue) % stoi(rightValue)  );
			varTemp.type="float";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){


			if(isVariable(leftValue)&&isVariable(rightValue)){

					string Rvar = (getVariable(rightValue))->value;
					string Lvar = (getVariable(leftValue))->value;

						if( (getVariable(rightValue))->type == "int"){
							varTemp.value = to_string(stoi(Rvar) % stoi(Lvar));
							varTemp.type = "int";
						}

						if( (getVariable(rightValue))->type == "float"){
							varTemp.value = to_string(stoi(Rvar) % stoi(Lvar));
							varTemp.type = "float";
						}
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){
					string Rvar = (getVariable(rightValue))->value;

					if(getVariable(rightValue)->type == "int"){
						varTemp.value = to_string(  stoi(leftValue) % stoi(Rvar));
						varTemp.type = "int";
						
					}
					if(getVariable(rightValue)->type == "float"){
						varTemp.value = to_string(  stoi(leftValue) %  stoi(Rvar));
						varTemp.type = "float";
			
					}
			}

			if(isVariable(leftValue) && !isVariable(rightValue)){
					string Lvar = (getVariable(leftValue))->value;

					if(getVariable(leftValue)->type == "int"){
						varTemp.value = to_string(stoi(Lvar) % stoi(rightValue));

					}
					if(getVariable(leftValue)->type == "float"){
						varTemp.value = to_string(stoi(Lvar) % stoi(rightValue));
						varTemp.type = "float";
					}
			}				
		}
	}

	void igual(Value * val){

		Pair* p = (Pair*)val;

		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue)){
			cout<<"ошибка: нельзя уравнять что-то на nonvariable"<<endl;
			exit(1);
		}else{

			if(p->right->isAtom()){
				Var *tmp = getVariable(leftValue);
				tmp->value = ((Atom*)p->right)->val;
				
			}else{
			run(p->right);

			Var *tmp = getVariable(leftValue);
			tmp->value = varTemp.value;
			tmp->type = varTemp.type;
			//cout<<varTemp.value<<varTemp.type<<endl;
			}
		}
	}

	void mayor(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) > stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) > stoi(Rvar);
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) > stoi(Rvar);
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) > stoi(rightValue);
				varTemp.type="bool";

			}



		}
	}

	void menor(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		//cout<<leftValue<<" "<<rightValue<<endl;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) < stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) < stoi(Rvar);//aqui
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) < stoi(Rvar);//aqui
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) < stoi(rightValue);//aqui
				varTemp.type="bool";

			}



		}
	}

	void CondIgual(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) == stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) == stoi(Rvar);//aqui
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) == stoi(Rvar);//aqui
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) == stoi(rightValue);//aqui
				varTemp.type="bool";

			}



		}
	}

	void mayorIgual(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) >= stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) >= stoi(Rvar);//aqui
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) >= stoi(Rvar);//aqui
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) >= stoi(rightValue);//aqui
				varTemp.type="bool";

			}



		}
	}

	void menorIgual(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) <= stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) <= stoi(Rvar);//aqui
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) <= stoi(Rvar);//aqui
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) <= stoi(rightValue);//aqui
				varTemp.type="bool";

			}



		}
	}

	void diferente(Value * val){

		Pair* p = (Pair*)val; 
		string rightValue = ((Atom*)p->right)->val;
		string leftValue = ((Atom*)p->left)->val;

		if(!isVariable(leftValue) && !isVariable(rightValue)){

			varTemp.flag= stoi(leftValue) != stoi(rightValue);//aqui
			varTemp.type="bool";

		}else if( isVariable(leftValue) || isVariable(rightValue) ){

			if(isVariable(leftValue)&&isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;
				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) != stoi(Rvar);//aqui
				varTemp.type = "bool";
				
			}

			if(!isVariable(leftValue) && isVariable(rightValue)){

				string Rvar = (getVariable(rightValue))->value;

				varTemp.flag = stoi(leftValue) != stoi(Rvar);//aqui
				varTemp.type="bool";

			}

			if(isVariable(leftValue) && !isVariable(rightValue)){

				string Lvar = (getVariable(leftValue))->value;

				varTemp.flag = stoi(Lvar) != stoi(rightValue);//aqui
				varTemp.type="bool";

			}



		}
	}

	void funReturn(Value * val){
		Pair* p = (Pair*)val;

		if(p->isAtom()){
			if(isVariable(((Atom*)p)->val)){
				varTemp.value = getVariable(((Atom*)p)->val)->value;
				varTemp.type = getVariable(((Atom*)p)->val)->type;
			}else{
				varTemp.value = ((Atom*)p)->val;
			}
		}else{

			run(p);
		
		}


		
	}

	void matchVariables(string funName, Value* entringVar){

		Func* function = getFunc(funName);
		int argsCount = function->argsCount;
		int counter = 0;

		Pair* parVariables = (Pair*)entringVar;
		string* VarNames = function->args;
		string* entringArgs= new string[argsCount];

		

		if(entringVar->len() == argsCount){

			for(int i = 0; i<argsCount; i++){

				Pair* var = new Pair(new Atom("var"),new Pair(new Atom(VarNames[i]),new Pair(new Atom("int"),new Atom("0"))));
				run(var);

			}

			while(parVariables != nullptr){

				entringArgs[counter] = ((Atom*)parVariables->left)->val;
				parVariables = (Pair*)parVariables->right;
				counter++;
			}

			for(int i = 0; i< argsCount; i++){

				if(isVariable(entringArgs[i])){

					getVariable(VarNames[i])->value = getVariable(entringArgs[i])->value;
					getVariable(VarNames[i])->type = getVariable(entringArgs[i])->type;

				}else{
					
					getVariable(VarNames[i])->value = entringArgs[i];
				}



			}
		}else{
			cout<<"ошибка: нет необходимых переменных"<<endl;
			exit(1);
		}



		
		
	}

	void run(Value* programm){ // исполнения кода
		//programm->out();
		//cout<<endl;
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
				
				Atom* signo = (Atom*)((Pair*)((Pair*)p->right)->left);
				//((Atom*)signo)->out();



				if(p->right->isAtom()){

					p->right->out();
					((Atom*)signo)->out();

					if(isVariable(b->val)){
					//cout<<"a->val vale "<<b->val<<endl;
					//encontrar la variable que se esta solicitando
					out(findValueOfVariable(b->val));
					//cout<<endl;
					}else{
						out(p->right);	
						cout<<endl;	
						
					}

				}else if( ((Atom*)signo)->val  == "+" || ((Atom*)signo)->val  == "-" || ((Atom*)signo)->val  == "*" || 
					((Atom*)signo)->val  == "/" || ((Atom*)signo)->val  == "%" || ((Atom*)signo)->val  == "="){
					run(p->right);
					cout<<varTemp.value<<endl;

				}else if(((Atom*)signo)->val  == ">" || ((Atom*)signo)->val  == "<" || ((Atom*)signo)->val  == "==" || 
					((Atom*)signo)->val  == ">=" || ((Atom*)signo)->val  == "<=" || ((Atom*)signo)->val  == "!="){

					run(p->right);
					cout<<varTemp.flag<<endl;

				}else if(isFunction(((Atom*)signo)->val)){
					run(p->right);
					cout<<varTemp.value<<endl;
				}
			}

			if(a->val == "+"){
				suma(p->right);
			}
			if(a->val =="-"){
				resta(p->right);
			}
			if(a->val =="*"){
				multiplicacion(p->right);
			}
			if(a->val =="/"){
				division(p->right);
			}
			if(a->val =="%"){
				resto(p->right);
			}
			if(a->val =="="){
				igual(p->right);
			}
			if(a->val ==">"){
				mayor(p->right);
			}
			if(a->val =="<"){
				menor(p->right);
			}
			if(a->val =="=="){
				CondIgual(p->right);
			}
			if(a->val==">="){
				mayorIgual(p->right);
			}
			if(a->val=="<="){
				menorIgual(p->right);
			}
			if(a->val=="!="){
				diferente(p->right);
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
			if(a->val=="if"){
				cicloIf(p->right);
			}

			if(a->val=="return"){
				funReturn(p->right);
				return;
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
							
							//variables en funciones
							matchVariables(a->val, p->right);


							//run(p->right);


							
/* 							if(p->right->isAtom()){
							if(isVariable(((Atom*)p->right)->val)){
								
								cout<<"is variable"<<endl;
							}

							}else{
								run(p->right);
							}
							 */
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
