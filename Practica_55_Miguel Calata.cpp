/*Miguel Salvador Calata Rodríguez
Practica 55 - Arreglo invertido*/
#include <iostream>
using namespace std;

main(){
    int resp;
    do {
        int n, selec;

        cout<<"Inserte longitud del arreglo?"; cin>>n;

        int Arreglo[n], Olgerra[n];

        for(int i = 0, j = n - 1; i < n; i++, j--){
            cout<<"Ingrese el dato n."<< i + 1<<": ";
            cin>>Arreglo[i];
            Olgerra[j] = Arreglo[i];
        }

        for(int l = 0; l < n; l++){
            cout<<Olgerra[l]<<" ";
        }

        cout<<"\nQuiere continuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}