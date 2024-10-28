/*Miguel Salvador Calata Rodríguez
Practica 54 - Edades de niños*/
#include <iostream>
using namespace std;

main(){
    int resp;
    do {
        int ninos, selec;

        cout<<"Cuantos ninos tienes?"; cin>>ninos;

        int edad[ninos];

        for(int i = 0; i < ninos; i++){
            cout<<"Cuantos anios tiene el ninio "<< i + 1<<"?";
            cin>>edad[i];
        }

        cout<<"De que ninio quieres saber la edad? "; cin>>selec;
        cout<<"El ninio "<< selec << " tiene :"<<edad[selec-1];

        cout<<"\nQuiere continuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}