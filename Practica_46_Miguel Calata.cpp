/*Miguel Salvador Calata Rodríguez
Práctica 46  -  Numero mayor, Numero menor, con for */

#include <iostream>
using namespace std;

main(){
    int resp, cantidad, num, M=0, m=0;
    do {
        cout<<"Cuantos numeros desea ingresar? "; cin>>cantidad;

        for(int i = 0; i < cantidad; i++ ){
            cout<<"Favor de ingresar un numero: "; cin>>num;
            if(i==0){
                M=num;
                m=num;
            }

            if(num>=M){
                M = num;
            }
            if(num<=m){
                m = num;
            }
        }
        cout<<"\nEl mayor numero introducido fue: "<<M;
        cout<<"\nEl menor numero intoducido fue: "<<m;

        cout<<"\nQuiere volver a ejecutar? 1.-SI  0.-NO\n"; cin>>resp;

    }while(resp>0);
}
