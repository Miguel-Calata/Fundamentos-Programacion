/*Miguel Salvador Calata Rodríguez
Práctica 30  - Múltiplos de 7 entre rangos*/

#include <iostream>
using namespace std;


main() {
    int a, b;
    cout<<"Favor de ingresar el rango inferior: "; cin>>a;
    cout<<"Favor de ingresar el rango superior: "; cin>>b;

    while(a <= b){
        if( a % 7 == 0 ){
            cout << a <<endl;
        }
        a++;
    }
}
