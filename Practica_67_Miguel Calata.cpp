//
// Miguel Calata Practica 67
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void bienvenida();
void movimiento(int[3][3], int, char[], bool);
int ganador(int[3][3]);

void botero(int[3][3]);

void imp_gato();
void imp_tablero(int[3][3]);
void p1(int);
void p2(int);
void p3(int);
void p4(int);

main(){
    int tablero[3][3];
    int jugando = 1, jugadores, par = 0;
    char J1[10], J2[10];
    bool bot = false;

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = 0;
        }
    }

    bienvenida();
    system("cls");

    cout << "\nRecuerda, este es tu tablero: \n";
    imp_gato();
    cout << "\nPresione enter para comtinuar..."; getchar();
    system("cls");

    cout << "\nCuantos Jugadores van a jugar?     1.- J1 vs bot (Funciona regular)       2.- J1 vs J2\n";
    do {
        cin >> jugadores;
    } while (jugadores != 1 && jugadores != 2);

    if (jugadores == 1){
        cout << "Cual es tu nombre? "; cin >>  J1;
        bot = true;
    }
    else{
        cout << "Jugador 1, Cual es tu nombre?"; cin >> J1;
        cout << "Jugador 2, Cual es tu nombre?"; cin >> J2;
    }
    system("cls");

    do {
        par += 1;

        if (par % 2 == 1){
            movimiento(tablero, par, J1, bot);
        }
        else{
            if (bot == true){
                movimiento(tablero, par, J1, bot);
            }
            else{
                movimiento(tablero, par, J2, bot);
            }
        }
        system("cls");
        ganador(tablero);
        imp_tablero(tablero);
        jugando = ganador(tablero);
    } while (jugando == 1);

    system("cls");

    cout << jugando << endl;

    if (par % 2 == 1){
        cout << "Felicidades " << J1 << " Ganaste!!!!";
    }
    else{
        if (bot == true){
            cout << "El bot gano, lo siento humano";
        }
        else {
            cout << "Felicidades " << J2 << " Ganaste!!!!";

        }
    }
    cout << endl;
    imp_tablero(tablero);
}

//================================================= [  ZONA LÓGICA  ]==================================================



void movimiento(int tab[3][3], int pares, char jug[], bool aut){
    int col, fil;
    char filcha;

    do{
        cout << jug <<" donde quieres poner tu ficha?";
        cout << "Columna (A, B o C) : ";
        do {
            cin >> filcha;
        } while (filcha != 'A' && filcha != 'a' && filcha != 'B' && filcha != 'b' && filcha != 'C'&& filcha != 'c');
        cout << "Fila: ";
        do {
            cin >> col;
        } while (col != 1 && col != 2 && col != 3);

        if (filcha == 'a' || filcha == 'A'){
            fil = 0;
        }
        else if(filcha == 'b' || filcha == 'B'){
            fil = 1;
        }
        else{
            fil =2;
        }
    }while (tab[col -1][fil] != 0);

    if(pares % 2 == 1 || aut == true){
        tab[col -1][fil] = -1;
    }
    else{
        tab[col -1][fil] = -2;
    }

    if (aut == true){
        botero(tab);
    }
}

int ganador(int comp[3][3]) {
    int cont = 0;
    for (int i = 0; i < 3; ++i) {
        cont = 0;
        for (int j = 0; j < 2; ++j) {
            if (comp[i][j] == comp[i][j + 1] && comp [i][j] != 0) {
                cont += 1;
            }
            if (cont == 2) {
                cout << "El contador de iguales fue: " << cont<< endl;
                return 2;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        cont = 0;
        for (int j = 0; j < 2; ++j) {
            if (comp[j][i] == comp[j + 1][i] && comp[j][i] != 0) {
                cont += 1;
            }
            if (cont == 2) {
                return 3;
            }
        }
    }
    cont =0;
    for (int i = 0, j = 0; i < 2; ++i, ++j) {
        if (comp[i][j] == comp[i + 1][j + 1] && comp[i][j] != 0) {
            cont += 1;
        }
        if (cont == 2){
            return 5;
        }
    }
    cont =0;
    for (int f = 2, c = 0; c < 2; --f, ++c) {
        if (comp[f][c] == comp[f - 1][c + 1] && comp[f][c] != 0) {
            cont += 1;
        }
        if (cont == 2){
            return 6;
        }
    }

    return 1;
}

//======================================================[    BOT    ]==================================================

void botero(int tab[3][3]){
    int fil, col, band = 0;
    srand(time(NULL));

    do {

        fil = rand() % 3 ;
        col = rand() % 3 ;

        if (tab[fil][col] == 0){
            tab[fil][col] = -2;
            band = 1;
        }
    } while (band == 0);
}

//================================================= [   IMPRIMIBLES    ]==================================================

void bienvenida(){
    int band;
    cout << "                                     /\\_/\\\n"
            " _______         __                  >^.^<.---.\n"
            "|     __|.---.-.|  |_.-----.        _'-`-'     )\\\n"
            "|    |  ||  _  ||   _|  _  |       (6--\\ |--\\ (`.`-.\n"
            "|_______||___._||____|_____|           --'  --'  ``-'\n"
            "Presione enter para comtinuar..."; getchar();
}

void imp_gato(){
    cout << "             |             |\n"
            "             |             |\n"
            "      A1     |      B1     |      C1\n"
            "             |             |\n"
            "------------------------------------------\n"
            "             |             |\n"
            "             |             |\n"
            "      A2     |      B2     |      C2\n"
            "             |             |\n"
            "------------------------------------------\n"
            "             |             |\n"
            "             |             |\n"
            "      A3     |     B3      |      C3\n"
            "             |             |\n";
}

void imp_tablero(int tab_us[3][3]){
    cout << endl;

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                switch (i) {
                    case 0:
                        p1(tab_us[k][j]);
                        if (j < 2){
                            cout << "|";
                        }
                        break;
                    case 1:
                        p2(tab_us[k][j]);
                        if (j < 2){
                            cout << "|";
                        }
                        break;
                    case 2:
                        p3(tab_us[k][j]);
                        if (j < 2){
                            cout << "|";
                        }
                        break;
                    case 3:
                        p4(tab_us[k][j]);
                        if (j < 2){
                            cout << "|";
                        }
                        break;
                    case 4:
                        if (k == 2){
                            break;
                        }
                        cout << "--------------";
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
        cout << "     ___     ";
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
        cout << "    / _ \\    ";
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
        cout << "   ( (_) )   ";
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
        cout << "    \\___/    ";
    }
    else{
        cout << "             ";
    }
}
