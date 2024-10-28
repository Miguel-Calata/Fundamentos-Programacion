/*Miguel Salvador Calata Rodríguez
Practica 56 - Acomodo de Pares*/
#include <iostream>
using namespace std;

main(){
    int resp;
    do {
        int n, par = 0, impar = 0, cont = 0, cont_ = 0, sumatoria = 0, producto = 1;

        cout<<"Inserte longitud del arreglo?"; cin>>n;

        int arreglo[n];

        for(int i = 0; i < n; i++){
            cout<<"Ingrese el dato n."<< i + 1<<": ";
            cin>>arreglo[i];
            if (arreglo[i] % 2 == 0){
                par++;
            }
            else{
                impar++;
            }
        }

        int pares[par], impares[impar];

        for(int j = 0; j < n; j++){
            if (arreglo[j] % 2 == 0){
                pares[cont] = arreglo[j];
                cont++;
            }
            else{
                impares[cont_] = arreglo[j];
                cont_++;
            }

        }

        cout <<"El arreglo par es: ";
        for (int l = 0; l < par; ++l) {
            cout<< pares[l]<<" ";
            sumatoria += pares[l];
        }
        cout << "\nLa sumatoria de los pares es: "<< sumatoria;

        cout<<"\nEl arreglo par es: ";
        for (int t = 0; t < impar; ++t) {
            cout<< impares[t]<<" ";
            producto *= impares[t];
        }
        cout<< "\nEl producto de los pares es: " << producto;

        cout<<"\nQuiere continuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}
