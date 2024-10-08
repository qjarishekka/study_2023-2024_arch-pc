#include <iostream>
#include <string>


class Value{

virtual Value* replace( std::string o, std::string n) = 0;


};

class Atom: Value {

Value* replace(std::string o, std::string n) override {

    return new Atom( val.replace( o , n ));
    std::string new_val = val;

}


};