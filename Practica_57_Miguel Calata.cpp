/*Miguel Salvador Calata Rodríguez
Practica 57 - Manejo de arreglos Pt1*/
#include <iostream>
#include <random>


using namespace std;

main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 42);

        int n, borrar, pos, opc, nuevo, disp = 0;

        cout << "Inserte longitud del arreglo: ";
        cin >> n;

        int arreglo[n];

        for (int i = 0; i < n; i++) {
            arreglo[i] = dis(gen);
            cout << arreglo[i] << " ";
        }
        cout << endl;

    do {
        cout <<"Desea borrar un numero o introducir uno nuevo?     |    Hay " << disp << " espacios disponibles\n";
        cout << "1.- Borrar dato    2.- Agregar dato   3.- Mostrar arreglo   4.-Cerrar programa: ";
        cin>>opc;

        switch(opc) {
            case 1:
                cout << "\nQue numero desea  borrar?"; cin >> borrar;
                pos = -1;

                for (int i = 0; i < n; ++i) {
                    if (borrar == arreglo[i]){
                        pos = i;
                        disp += 1;
                        break;
                    }
                }

                if(pos != -1){
                    for (int l = pos; l < n - 1; ++l) {
                        arreglo[l] = arreglo[l+1];
                    }
                    arreglo[n-disp] = -1;

                    for (int j = 0; j < n; ++j) {
                        cout << arreglo[j] << " ";
                    }
                    cout << endl;
                }
                else{
                    cout << "El numero no esta en el arreglo, vuelvalo a intentar" << endl;
                }
                cout << endl;
            break;
            case 2:
                if (disp >= 1){
                    cout << "\nQue numero desea introducir? "; cin >> nuevo;
                    for (int i = 0; i < n; ++i) {
                        if (arreglo[i] == -1){
                            arreglo[i] = nuevo;
                            disp -= 1;
                            break;
                        }
                    }
                }
                else{
                    cout << "\nEl arreglo esta lleno, no es posible agregar mas datos\n";
                }
                for (int j = 0; j < n; ++j) {
                    cout << arreglo[j] << " ";
                }
                cout << endl;
            break;
            case 3:
                for (int j = 0; j < n; ++j) {
                    cout << arreglo[j] << " ";
                }
                cout << endl;
            break;
            case 4:
            break;
            default:
                cout << "\nError";
        }

    } while (opc != 4);
}