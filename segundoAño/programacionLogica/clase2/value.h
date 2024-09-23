#include<iostream>

class Value{
    public:
    virtual void print() = 0;
    virtual float sum() = 0;
};

class Atom : public Value{
public:
    float num;
    Atom(float n){
        num = n;
    }

    Atom(Atom &atom){
        num = atom.num;
    }

    void print() override {
        std::cout<<num;
    }

    float sum() override{
        return num;
    }
};


class Pair : public Value {

    public:
    Value* left;
    Value* right;

    Pair(Atom* l, Atom* r){
        left = l;
        right = r;
    }

    Pair(Pair & pair){

        left = pair.left;
        right= pair.right;

    }

    Pair( Value * l, Value *r){
        

    }


    Pair(Atom* l, Pair* r){
        left = l;
        right = r;
    }

    void print() override{
        std::cout<<"(";
        left->print();
        std::cout<< ",";
        right->print();
        std::cout<<")";
    }

    float sum() override{
        return left->sum() + right->sum();
    }


};