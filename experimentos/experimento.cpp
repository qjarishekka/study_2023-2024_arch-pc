// crea un tablero de ajedres

#include <iostream>

using namespace std;

int main()
{

string a = "12345";

cout<< a.length()<<endl;
cout<< a.substr(1,2)<<endl;
cout<< a.find('9')<<endl;
bool b = a.rfind("1");

cout<<b<<endl;


return 0;

}