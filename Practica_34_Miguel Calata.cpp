/*Miguel Salvador Calata Rodríguez
Práctica 34  - Pares e impares */

#include <iostream>
using namespace std;

int main() {
    int numero, sumatoria = 0, producto = 1;

    while( sumatoria < 50 || producto < 150){
        cout<<"Favor de ingresar un numero: "; cin>>numero;

        if(numero % 2 == 0){
            sumatoria += numero;
        }
        else{
            producto *= numero;
        }
        cout<<"La suma es:  "<<sumatoria<<endl;
        cout<<"El producto es:  "<<producto<<endl;
    }
    cout<<"La suma de pares es mayor a 50 y el producto de los pares mayor a 150";
}