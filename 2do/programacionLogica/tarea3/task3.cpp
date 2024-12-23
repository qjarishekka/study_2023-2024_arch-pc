#include <iostream>
using namespace std;

class Fact{
    public:
    string Parent;
    string child;

    bool operator==( const Fact& c2){
        if(this->Parent == c2.Parent && this->child == c2.child)
            return true;
        return false;
    }
};


struct Node{
    Fact fact;
    Node * next;

    Node(){

    }

    Node( Fact f){
        fact = f;
        next = nullptr;
    }
};






class DB: public Fact{
    
    Node * head;
    
    public:

    DB(){
       head = nullptr;
    }

    Fact parse(string fact){


        int indexStart = fact.find("(") +1;
        int indexMiddle = fact.find(",");
        int indexEnd = fact.find(")");
        string argument1;
        string argument2;
        Fact newFact;

        argument1 = fact.substr(indexStart,indexMiddle-indexStart);
        argument2 = fact.substr(indexMiddle + 1 , indexEnd- indexMiddle -1);
        //cout<<argument1<<" "<<argument2<<endl;

        if( fact.find("parent") != -1){   
            newFact.Parent = argument1;
            newFact.child = argument2;
        }
        if( fact.find("child") != -1){ 
            newFact.Parent = argument2;
            newFact.child = argument1;
        }

        return newFact;
    }


    void addFact(string fact ){

        if(fact.find("child") == -1 && fact.find("parent") == -1 && fact.find("print")!=-1){
            cout<<"comand not found"<<endl;
            return;
        }

        Fact newfact = parse(fact);
        Node ** temp = &head;
        while( *temp != nullptr){
            if( (*temp)->fact == newfact ){
                cout<<"this fact was already registered"<<endl;
                return;
            }
            temp = &((*temp)->next);
        }
        *temp = new Node(newfact);
    }



    void printDataBase(){
        Node * temp = *&head;
        while(temp != nullptr){
            cout<< temp->fact.Parent <<"\t"<< temp->fact.child<<endl;
            temp = temp->next;
        }
    }

    void question(string q){

        Fact question = parse(q);

        Node * temp = *&head;
        while(temp != nullptr){
            
            if(temp->fact == question){
                cout<<"TRUE"<<endl;
                return;
            }

                
            

            temp = temp->next;
        }

        cout<<"FALSE"<<endl;

      

    }


};


int main(){

DB dataBase;

string query="";

/* string fact1 = "parent(maria,juan)";
string question = "ischild(maria,juan)";

dataBase.addFact(fact1);
dataBase.question(question); */



dataBase.printDataBase();



while(query != "quit"){

    cin>>query;

    if(query.find("is") != -1){
        
        dataBase.question(query);
        //cout<<"yes"<<endl;
        
    }else{
        dataBase.addFact(query);
         //cout<<"no"<<endl;
    }

    if(query.find("print")!= -1){
        dataBase.printDataBase();
    }


    

}



}