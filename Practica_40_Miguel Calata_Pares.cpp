/*Miguel Salvador Calata Rodríguez
Práctica 40  -  Cuantos pares? */

#include <iostream>
using namespace std;

main(){
    int band, num, pares, cont = 0;
    do{
        cout<<"Cuantos numeros desea ingresar: "; cin>>num;
        for (int i = 1 ;  i <=num ; i++) {
            cout<<"Favor de introducir un numero: "; cin>>pares;

            if (pares % 2 == 0){
                cont++;
            }
        }
        cout<<"Fueron introducidos "<< cont <<" numeros pares\n";
        cout<<"Quiere continuar 1.-SI  0.-NO\n"; cin>>band;
    }while(band>0);
}