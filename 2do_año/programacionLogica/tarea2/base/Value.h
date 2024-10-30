#include <iostream>
#include <string>
using namespace std;

class Value{
public:
	virtual void out() = 0;
	virtual float sum() = 0;
	virtual float calc() = 0;
	virtual Value* replaceVar(string varName, string varValue) = 0;
	virtual string type() = 0;
	virtual bool isAtom() = 0;
	virtual bool isPair() = 0;
	virtual int len() = 0;
};

class Atom : public Value{
public:
	//float number;
	string val;
	float number(){ return stof(val); } 
	
	string type() override { return "Atom"; }
	bool isAtom() override { return true; }
	bool isPair() override { return false; }
	
	Atom(string val){
		this->val = val;
	}
	
	void out() override {
		cout << val;
	}
	
	float sum() override {
		return number();
	}
	
	float calc() override {
		return number();
	}
	int len() override {
		return 1;
	}
	// (+, (X, 0)).replace(X, 1)
	// (+, (X, X0)).replace(X, 1)
	Value* replaceVar(string varName, string varValue){
		if(val == varName)
			return new Atom(varValue);
		return new Atom(val);
	}
};

class Pair : public Value{
public:
	Value *left, *right;
	
	Pair(Value *left, Value *right){
		this->left = left;
		this->right = right;
	}
	
	string type() override { return "Pair"; }
	bool isAtom() override { return false; }
	bool isPair() override { return true; }
	
	void out() override {
		cout << '(';
		if(left == nullptr)
			cout << "null";
		else
			left->out();
		cout << ", ";
		if(right == nullptr)
			cout << "null";
		else
			right->out();
		cout << ')';
	}
	
	float sum() override {
		return left->sum() + right->sum();
	}
	
	float calc() override {
		// проверить, что пара подходит
		Atom* a = (Atom*) left;
		Pair* p = (Pair*) right;
		if(a->val == "+")
			return p->left->calc() + p->right->calc();
		if(a->val == "*")
			return p->left->calc() * p->right->calc();
		cout << endl << "Wrong command" << endl;
		return 0;
	}
	int len() override {
		int l = left == nullptr ? 0 : left->len();
		int r = right == nullptr ? 0 : right->len();
		return l + r;
	}
	
	Value* replaceVar(string varName, string varValue){
		return new Pair(left->replaceVar(varName, varValue), right->replaceVar(varName, varValue));
	}
};
	
