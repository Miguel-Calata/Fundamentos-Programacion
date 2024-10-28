/*Miguel Salvador Calata Rodríguez
Practica 61 - Palindromos */
#include <iostream>
using namespace std;

main() {
    int resp;
    do {
        int n, cont = 0;
        cout << "Inserte longitud del arreglo:"; cin >> n;
        char palindromo[n];
        cin >> palindromo;

        for (int i = 0, I = n-1; i < n; ++i, --I) {
            if (palindromo[i] == palindromo[I]){
                cont += 1;
            }
        }

        if(cont == n){
            cout << "Es palindromo!!";
        }
        else{
            cout << "No es palindromo  :(";
        }

        cout << "\nQuiere continuar 1.-SI  0.-NO\n";
        cin >> resp;
    } while (resp > 0);
}
