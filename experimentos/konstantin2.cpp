#include <iostream>

int main(){

int dia, mes, tipoDeAnio;
int counter = 0;
do{

    if(counter == 1){

        std::cout << "ingrese texto de error y repetir el ingreso de datos\n";
        counter = 0;
    }
    // Solicitar datos de entrada al usuario
    std::cout << "Ingrese el numero del dia desde el inicio del mes: ";
    std::cin >> dia;

    std::cout << "Ingrese el numero del mes: ";
    std::cin >> mes;

    std::cout << "Ingrese el tipo de anio (0 - no bisiesto, 1 - bisiesto): ";
    std::cin >> tipoDeAnio;

    counter++;


}while(dia > 28 && mes==2 && tipoDeAnio == 0 || dia >31);





    return 0;
}