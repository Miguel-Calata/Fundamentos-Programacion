/*Miguel Salvador Calata Rodríguez
Práctica 2
Manejo básico de Entrada y Salida (Pastel de cumpleaños personalizado) */
#include <iostream>

using namespace std;

main() {
    char Nombre[10];
    int Anio, Edad;

    cout<<"Hola, bienvenido, cual es tu nombre? "; cin>>Nombre;
    cout<<"Que año nacieste "<<Nombre<<"? "; cin>>Anio;
    Edad = 2024 - Anio;


    cout << "       ,,,,,,\n";
    cout << "       ||||||\n";
    cout << "   @@@@@@@@@@@@@@\n";
    cout << "   {~@~@~@~@~@~@~}\n";
    cout << "@@@@@@@@@@@@@@@@@@@@\n";
    cout << "{    Felices "<<Edad<<"    }\n";
    cout << "{      "<<Nombre<<"      }\n";
    cout << "@@@@@@@@@@@@@@@@@@@@\n";
    cout << "        _) (_\n";
    cout << "       /_____\\";
}
