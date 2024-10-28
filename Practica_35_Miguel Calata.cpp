/*Miguel Salvador Calata Rodríguez
Práctica 35  - Conjetura de ULAM */

#include <iostream>
using namespace std;

main(){
    int n,resp;

    do {
        cout << "Favor de introducir un numero: ";
        cin >> n;

        cout << n << " ";
        do {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = (n * 3 + 1);
            }
            cout << n << " ";
        } while (n != 1);

        cout << "\nQuieres continuar?  1-Si   0-NO\n"; cin>>resp;
    }while(resp > 0);
}
