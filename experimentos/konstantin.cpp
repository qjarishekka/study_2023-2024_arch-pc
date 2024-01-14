#include <iostream>



bool esBisiesto(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}





int calcularDiasDesdeInicioDelAnio(int dia, int mes, int tipoDeAnio) {
    int diasPorMes[] = { 0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (tipoDeAnio == 1) {
        diasPorMes[2] = 29;  // Ajusta febrero a 29 días en años bisiestos
    }

    int dias = dia;
    for (int i = 1; i < mes; ++i) {
        dias += diasPorMes[i];
    }

    return dias;
}





int main() {
    int dia = 60; 
    int mes = 60;
    int tipoDeAnio = 60;
    int counter = 0;
    int diasPorMes[] = { 0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
do{

    if(counter == 1 || dia > 31 || dia < 1){

        std::cout << "ingrese texto de error y repetir el ingreso de datos\n"; //////// el mensaje de error de tu gusto y que sea universal
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
    if(dia > diasPorMes[mes]){

        dia = 32;

    }

}while(dia > 28 && mes==2 && tipoDeAnio == 0 || dia >31 || dia <1);




    // Validar los datos de entrada
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || tipoDeAnio < 0 || tipoDeAnio > 1) {
        std::cout << "Datos de entrada invalidos." << std::endl;
        return 1;  // Código de error
    }

    // Calcular y mostrar el resultado
    int diasDesdeInicioDelAnio = calcularDiasDesdeInicioDelAnio(dia, mes, tipoDeAnio);
    std::cout << "El numero del dia desde el inicio del anio es: " << diasDesdeInicioDelAnio << std::endl;

    return 0;  // Código de éxito
}