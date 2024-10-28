//
// Created by Migue on 30/04/2024.
//
#include "iostream"

using namespace std;

main() {
    int col, fil;
    char filcha;
    cout << "Donde quieres poner tu ficha?\n Fila: ";
    do {
        cin >> filcha;
    } while (filcha != 'A' && filcha != 'a' && filcha != 'B' && filcha != 'b' && filcha != 'C'&& filcha != 'c');
    cout << "Columna: "; cin >> col;

    if (filcha == 'a' || filcha == 'A'){
        fil = 0;
    }
    else if(filcha == 'b' || filcha == 'B'){
        fil = 1;
    }
    else{
        fil =2;
    }

    if
}