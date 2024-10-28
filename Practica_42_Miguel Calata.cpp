/*Miguel Salvador Calata Rodríguez
Práctica 42  -  Calcular factorial con for */

#include <iostream>
using namespace std;

main(){
    int num, resp;
    double factorial, mul;
    do {
        cout << "Favor de ingresar numero a calcular factorial: "; cin >> num;
        mul = num;

        for (int i = num; i > 1; i--) {
            cout << i << " x ";
            factorial = mul * (i - 1);
            mul = factorial;
        }
        cout << "1 = "<<factorial<<endl;
        cout<<"Quiere cont1inuar 1.-SI  0.-NO\n"; cin>>resp;
    }while(resp>0);
}