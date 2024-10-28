/*Miguel Salvador Calata Rodríguez
Práctica 32  - Sumatoria de Números enteros hasta 100 */

#include <iostream>
using namespace std;

main() {
    int cuenta = 0, vuelta;

    while(cuenta < 100){
        cout<<"Favor de ingresar un numero entero: "; cin>>vuelta;
        cuenta += vuelta;
        cout<<"La suma va en "<<cuenta<<endl;
    }
    cout<<"La sumatoria es 100 o mas que 100";
}