/*Miguel Salvador Calata Rodr�guez
Pr�ctica 32  - Sumatoria de N�meros enteros hasta 100 */

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