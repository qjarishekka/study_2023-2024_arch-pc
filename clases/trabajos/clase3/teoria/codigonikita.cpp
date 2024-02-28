#include <iostream>

using namespace std;

struct tovar {
    string name;
    float price;
    int amount;
    tovar* next;
};

void addfirst (tovar *&bufet, string n, float p, int am) {
    tovar *tmp = new tovar;
    tmp -> name = n;
    tmp -> price = p;
    tmp -> amount = am;
    tmp -> next = bufet;
    bufet = tmp;
}

int addafter (tovar *bufet, string n, float p, int am, string nameafter) {
    if (bufet == NULL) {
        return 1;
    }
    tovar *tmp = bufet;
    while (tmp != NULL && tmp -> name != nameafter) {
        tmp = tmp -> next;
    }
    if (tmp == NULL) {
        return 1;
    }
    
    tovar *newtovar = new tovar;
    newtovar -> name = n;
    newtovar -> price = p;
    newtovar -> amount = am;
    newtovar -> next = tmp -> next;
    tmp -> next = newtovar;
    return 0;
}

int printlist (tovar *bufet) {
    if (bufet == NULL) {
        std::cout << "Список пуст!" << "\n";
        return 1;
    }
    tovar *tmp = bufet;
    while (tmp != NULL) {
        std::cout << tmp -> name << "\n";
        std::cout << tmp -> price << "\n";
        std::cout << tmp -> amount << "\n";
        tmp = tmp -> next;
    }
    return 0;
}

int main() {
    tovar *bufet = NULL;
    printlist(bufet);
    addfirst(bufet, "puncake", 25.0, 2);
    addafter(bufet, "cake", 55.0, 20, "puncake");
    printlist(bufet);
    return 0;
}