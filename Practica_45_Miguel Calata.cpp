/*Miguel Salvador Calata Rodríguez
Práctica 45  -  Positivos y Negativos */

#include <iostream>
using namespace std;

main(){
    int resp, num, suma, prom, cont;
    do {
        suma = 0, prom = 0, cont = 0;

        for(int i = 0; i<6; i++ ){
            cout<<"Favor de introducir un numero: "; cin>>num;
            if(num<0){
                suma += num;
            }
            else{
                prom += num;
                cont ++;
            }
        }

        cout<<endl<<"La sumatoria de los numeros negativos es: "<<suma;
        if( cont != 0){
            cout<<endl<<"El promedio de los numeros positivos es: "<<prom/cont;
        }
        else{
            cout<<endl<<"No se inserto ningun numero positivo";
        }

        cout<<"\nQuiere continuar? 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}
