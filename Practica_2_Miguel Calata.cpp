/*Miguel Salvador Calata Rodr�guez
Pr�ctica 2
Manejo b�sico de Entrada y Salida (Pastel de cumplea�os personalizado) */
#include <iostream>

using namespace std;

main() {
    char Nombre[10];
    int Anio, Edad;

    cout<<"Hola, bienvenido, cual es tu nombre? "; cin>>Nombre;
    cout<<"Que a�o nacieste "<<Nombre<<"? "; cin>>Anio;
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
