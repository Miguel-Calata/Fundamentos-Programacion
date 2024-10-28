/*Miguel Salvador Calata Rodríguez
Práctica 43  */

#include <iostream>
using namespace std;

main(){
    int num, resp;
    double long a, b, c;
    do {
        a=0;
        b=1;
        cout << "Favor de ingresar n: "; cin >> num;

        for (int i = 0; i < num; i++) {
            cout << a << " ";
            c = a+b;
            a = b;
            b = c;
        }
        cout<<"\nQuiere continuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}