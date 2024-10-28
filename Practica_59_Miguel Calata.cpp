/*Miguel Salvador Calata Rodríguez
Practica 58 - Acomodo de Pares*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

main() {
    int resp;
    srand(time(NULL));
    do {

        int n, valor, cuenta = 0, acomodador = 0, busqueda;

        cout << "Inserte longitud del arreglo: "; cin >> n;

        int arreglo[n];

        for (int i = 0; i < n; i++) {
            arreglo[i]=rand() % 100;
        }

        do{
            cout << "Buscar el valor: "; cin >> valor;

            for (int l = 0; l < n; ++l) {
                if(arreglo[l] == valor){
                    cuenta += 1;
                }
            }

            if(cuenta >= 1){
                int posiciones[cuenta];

                for (int j = 0; j < n; ++j){
                    if (arreglo[j] == valor){
                        posiciones[acomodador] = j;
                        acomodador += 1;
                    }
                }

                cout << "La posicion del primer valor es: " << posiciones[0] << endl;
                cout << "La ultima posicion encontrada fue: " << posiciones [cuenta-1] << endl;
                cout << " Se encuentra en las siguientes posiciones: ";
                for (int s = 0; s < cuenta ; ++s) {
                    cout << posiciones[s] << " ";
                }
            }
            else{
                cout << "El numero no fue encontrado en el arreglo, desea buscar otro numero? 1.-SI  0.-NO\n";
                cin >> busqueda;
            }
        }while(busqueda != 0);

        cout << "\nQuiere continuar 1.-SI  0.-NO\n";
        cin >> resp;
    } while (resp > 0);
}
