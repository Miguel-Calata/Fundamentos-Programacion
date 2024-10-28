/*Miguel Salvador Calata Rodríguez
Practica 58 - Acomodo de Pares*/
#include <iostream>
#include <ctime>
using namespace std;

main() {
    int resp;
    srand(time(NULL));
    do {

        int n;

        cout << "Inserte longitud del arreglo?";
        cin >> n;

        int arreglo[n], array[n], suma[n];

        for (int i = 0; i < n; i++) {
            arreglo[i]=rand() % 42;
            array[i]=rand() % 42;
            suma[i]= arreglo[i] + array[i];
        }
        cout<<"El primer arreglo fue:";
        for (int j = 0; j < n; ++j) {
            cout<<arreglo[j]<<" ";
        }
        cout<<endl;
        cout<<"El segundo arreglo fue: ";
        for (int t = 0; t < n; ++t) {
            cout<<array[t]<<" ";
        }
        cout<<endl;
        cout<<"La suma de estos dos arreglos es: ";
        for (int l = 0; l < n; ++l) {
            cout<<suma[l]<<" ";
        }


        cout << "\nQuiere continuar 1.-SI  0.-NO\n";
        cin >> resp;
    } while (resp > 0);
}