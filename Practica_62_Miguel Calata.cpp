/*Miguel Salvador Calata Rodríguez
Practica 62 - Manejo de arreglos */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

main() {
    srand(time(NULL));
    int arreglo[20], par = 0, impar = 0, sumap = 0, sumaim = 0, posp, posi;
    cout << "Generando arreglo de 20 unidades...";

    for(int i = 0; i < 20; i++){
        arreglo[i] = rand() % 42;
        cout << arreglo[i] << " ";
    }
    cout << endl;

    for(int l = 0; l < 20; l++){
        if(arreglo[l] % 2 == 0){
            if(l == 0){
                posp = l;
            }
            if (arreglo[l] >= arreglo[posp] ){
                posp = l;
            }
            par += 1;
            sumap += arreglo[l];
        }
        else{
            if(l == 0){
                posi = l;
            }
            if (arreglo[l] <= arreglo[posi] ){
                posi = l;
            }
            impar += 1;
            sumaim += arreglo[l];
        }
    }

    cout << endl;
    cout << "Pares: " << par << endl;
    cout << "Impares: " << impar << endl;
    cout << "Suma de Pares: " << sumap << endl;
    cout << "Suma de Impares: " << sumaim << endl;
    cout << "La posicion del mayor numero par fue: " << posp << endl;
    cout << "La posicion del menor numero impar fue: " << posi;
}