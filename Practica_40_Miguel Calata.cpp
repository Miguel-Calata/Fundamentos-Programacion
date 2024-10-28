/*Miguel Salvador Calata Rodríguez
Práctica 40  -  Alfabeto en orde ascendente  y descendente con for*/

#include <iostream>
using namespace std;

main(){
    int band;

    do{
        for (char as = 'A'; as <='Z'; as++) {
            cout<<as<<endl;
        }
        cout<<"En orden descendente\n";
        for (char des = 'z'; des >='a'; des--) {
            cout<<des<<endl;
        }
        cout<<"Quiere continuar 1.-SI  0.-NO\n"; cin>>band;
    }while(band>0);
}
