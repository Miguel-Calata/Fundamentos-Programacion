/*Miguel Salvador Calata Rodríguez
Práctica 44  -  Alfabeto doble */

#include <iostream>
using namespace std;

main(){
    int resp;
    do {
        for(char M = 'A',m= 'a'; m<='z'; M++,m++ ){
            cout<<M<<m<<" ";
        }
        cout<<"\nQuiere volver a imprimir 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}
