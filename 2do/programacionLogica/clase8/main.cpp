#include<iostream>
#include<string.h>
using namespace std;

class Compiler{
    public:
    bool outsliner(string request){
        return true;
    }
};


class Fact{
    string type;
    int argsCount;
    string * args;
    virtual bool check()= 0;
};

class Rule: public Fact, public Compiler{
    string body;

    bool check() override{
        if( (int)body.find(';') >= 0 ){
            string* pands = body.split(';');
            for(int i = 0; i< sizeof(pands)/ sizeof(pands[0]); i++){
                if( Compiler::outsliner(pands[i]))
                return true;
            }
            return false;
        }


        if((int)body.find(';') ){
            //...
        }
    }

};




class DB{
    bool contain(Fact* fact){
    //-----------
    // return true/ false;
    }



};

