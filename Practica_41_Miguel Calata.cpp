/*Miguel Salvador Calata Rodríguez
Práctica 41  -  Numero primos con for */

#include <iostream>
using namespace std;

main(){
    int num, cont, resp;
    do{
        cout<<"Favor de introducir un numero: "; cin>>num;
        cont = 0;

        for(int i = 1; i<=num; i++){
            if( num % i == 0){
                cont++;
            }
            if( cont > 2){
                break;
            }
        }
        if(cont <= 2){
            cout<<"El "<<num<<" Es primo\n";
        }
        else{
            cout<<"El "<<num<<" No es primo\n";
        }
        cout<<"Quiere continuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);








}