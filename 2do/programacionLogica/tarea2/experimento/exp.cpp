#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

int main(){

string a = "123456789";

bool B = true;

cout<< (int)a.length()<<endl;

cout<< typeid(B).name() <<endl;

cout<<9%2<<endl;

if(1){
    cout<<false<<endl;
}


}