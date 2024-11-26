#include <iostream>

int main(){

#ifdef _WIN32

#else
    std::cout<<"esto es mac"<<std::endl;

#endif

}