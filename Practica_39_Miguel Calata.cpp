/*Miguel Salvador Calata Rodríguez
Práctica 39  -  Tabla de Multiplicar*/

#include <iostream>
using namespace std;

main(){
    int num, band;
    do{
        cout<<"Introducir un numero: ";
        cin>>num;

        for (int i = 1; i<=12; i++) {
            cout<<i<<" x "<<"= "<<num*i<<endl;
        }
        cout<<"Quiere continuar 1.-SI  0.-NO\n";
        cin>>band;
    }while(band>0);
}