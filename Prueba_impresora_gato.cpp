//
// Created by Migue on 30/04/2024.
//
#include <iostream>
using namespace std;


void imp_tablero(int[3][3]);


void p1(int);
void p2(int);
void p3(int);
void p4(int);

main(){
    int tablero[3][3]={{-2,-1, -2},{-2,-1,-1}, {-2,-1,-2}};
    int jugando = 1;


    do {
        imp_tablero(tablero);


        cout << "estado de jugando: "<< jugando << endl;

        cout << "Continuar: "; cin >> jugando;

    } while (jugando == 1);


    imp_tablero(tablero);
}


void imp_tablero(int tab_us[3][3]){

    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                switch (i) {
                    case 0:
                        p1(tab_us[k][j]);
                    break;
                    case 1:
                        p2(tab_us[k][j]);
                    break;
                    case 2:
                        p3(tab_us[k][j]);
                    break;
                    case 3:
                        p4(tab_us[k][j]);
                    break;
                    case 4:
                        cout << "             ";
                }
            }
            cout << endl;
        }
    }

}

void p1(int cont){

    if (cont == -1){
        cout << "     _  _    ";
    }
    else if(cont == -2){
        cout << "      ___    ";
    }
    else{
        cout << "             ";
    }

}

void p2(int cont){
    if (cont == -1){
        cout << "    ( \\/ )   ";
    }
    else if(cont == -2){
        cout << "     / _ \\   ";
    }
    else{
        cout << "             ";
    }
}

void p3(int cont){
    if (cont == -1){
        cout << "     )  (    ";
    }
    else if(cont == -2){
        cout << "    ( (_) )  ";
    }
    else{
        cout << "             ";
    }
}

void p4(int cont){
    if (cont == -1){
        cout << "    (_/\\_)   ";
    }
    else if(cont == -2){
        cout << "     \\___/   ";
    }
    else{
        cout << "             ";
    }
}
