#include <iostream>


using namespace std;

class Fact{
    public:
    string Parent;
    string child;
};

int main(){

    string fact = "parent(maria,samuel)";

    int indexStart = fact.find("(") +1;
    int indexMiddle = fact.find(",");
    int indexEnd = fact.find(")");

    string argument1;
    string argument2;

    argument1 = fact.substr(indexStart,indexMiddle-indexStart);
    argument2 = fact.substr(indexMiddle + 1 , indexEnd- indexMiddle -1);

    cout<<argument1<<" "<<argument2<<endl;

    if( fact.find("parent") != -1){
        Fact newFact;
        newFact.Parent = argument1;
        newFact.child = argument2;
    }

    if( fact.find("child") != -1){
        Fact newFact;
        newFact.Parent = argument2;
        newFact.child = argument1;
    }


    


    return 0;
}