//  Matemáticas Discretas 07  --  Tarea 03
//  Miguel Salvador Calata Rodríguez 06/03/2024
//
#include <iostream>
using namespace std;

main(){
    int n;
    cout<<"Favor de introducir el tamanio del arreglo: ";
    cin>>n; //Se introduce el tamaño del arreglo

    int x[n];//Se crea un arreglo con el numero introducido "n"

    for(int i = 0; i < n; i++){// Se usa este for para pedir los n números y almacenarlos
        cout<<"Favor de introducir el elemento "<< i+1 << ": ";
        cin>> x[i];
    }

    if(n>3){ //Se crea una condicional, en caso de que el arreglo sea mayor que tres
        cout <<"Los ultimos 3 valores introducidos son:\n";
        for(int i = n-1; i >= n-3 ; i--){ // i se le asigna el valor de n-1 para que empiece con el valor mayor del arreglo. i >=3 , para que el algoritmo se detenga cuando se le hayan restado 3 a i
            cout <<x[i]<<endl; // Se imprime el valor de n-1, o lo que es lo mismo, el último valor guardado en arreglo. Despues se resta a i uno
        }
    }
}
