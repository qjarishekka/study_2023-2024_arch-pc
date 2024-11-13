#include<iostream>
#include<string.h>
using namespace std;

class Complier{
    public:
    bool outsliner(string request){

    }
};


class Fact{
    string type;
    int argsCount;
    string * args;
    virtual bool check()= 0;
};

class Rule: public Fact, public Complier{
    string body;

    bool check() override{
        if( (int)body.find(';') >= 0 ){
            string* pands = body.split(';');
            for(int i = 0; i< sizeof(pands)/ sizeof(pands[0]); i++){
                if(Complier::outsliner(pands[i]))
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

