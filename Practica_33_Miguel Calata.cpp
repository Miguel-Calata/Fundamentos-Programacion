/*Miguel Salvador Calata Rodríguez
Práctica 33  - hata que el producto sea 0 */

#include <iostream>
using namespace std;

main() {
    float numero1, numero2;

    cout<<"Favor de ingresar un numero: "; cin>>numero1;

    while( numero1 != 0){
        cout<<"Favor de ingresar otro numero: "; cin>>numero2;
        numero1 *= numero2;
        cout<<"El producto es:  "<<numero1<<endl;
    }
    cout<<"El producto del numero es 0";
}