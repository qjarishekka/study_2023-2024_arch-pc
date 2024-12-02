#include<iostream>

using namespace std;

struct node{
    int val;
    node * next;
};

int main(){

node * head = nullptr;

node * temp = head;

cout<<temp->next<<endl;

while(temp->next != nullptr){

    temp = temp->next;
    cout<<"xd" <<endl;

}



}