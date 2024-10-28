/* Miguel Salvador Calata Rodríguez
    Proyecto Final de Programación  juego de Yahtzee*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void iniciador(int[3][14]);
void iniciador_dados(int[], int);
void cerador(int[3][14], bool);
void randomizador(int[]);
void mostrador_puntos (int[], int);
void capturador(int[], int);

int preguntador(int[3][14], char[], int);
void contar_sumar(int[], int[3][14]);
void puntador(int[3][14],int, int, int, int, int, int);

int contador_final(int[3][14], int, int);

void pantalla_bien();
void pantalla_salida();
void imp_UI(char[], int, int);
void imp_tabla(int[3][14], int, char[3], char[3], bool);
void imp_dados(int[]);
void imp_reng(int);
void dado1(int);
void dado2(int);
void dado3(int);

main(){
    int dados[5], puntajes[3][14];
    char J1[10], J2[10] = "N/A", resp;
    char aka1[4], aka2[4];
    int cjug, ronda = 0, r = 1,reserva, cuantos_guard, YH1 = 0, YH2 = 0, c;
    iniciador(puntajes);

    pantalla_bien();
    system("cls");

    cout << "Para fines practicos supondremos que eres todo un profecional de Yahtzee, asi que empecemos directamente\n";
    cout << "\nCuantos jugadores van a jugar?    1.-Un jugador     2.-Dos jugadores :";

    do{
        cin >> cjug;
    }while (cjug != 1 && cjug != 2);

    if (cjug > 1){
        cout << "\nJugador 1, introduce tu nombre: "; cin >> J1;
        cout << "\nJugador 2, introduce tu nombre: "; cin >> J2;
    }
    else{
        cout << "\nIntroduce tu nombre: "; cin >> J1;
    }

    for (int i = 0; i < 3; ++i) {
        aka1[i] = J1[i];
        aka2[i] = J2[i];
    }
    aka1[3] = '\0';
    aka2[3] = '\0';

    do{
        reserva = 0;
        system("cls");
        for (int i = 0; i < 3; ++i) {
            iniciador_dados(dados, reserva);
            randomizador(dados);

            if(cjug > 1 && ronda % 2 != 0){
                imp_UI(J2,r,i);
                cout << J2;
            }
            else{
                imp_UI(J1, r, i);
                cout << J1;
            }

            cout << " tus puntajes obtenidos en los dados fueron:\n \n";

            imp_dados(dados);

            if (i < 2){
                cout << "\nTe quieres quedar con toda tu jugada? S-.Si  N-.No:  ";
                do {
                    cin >> resp;
                } while (resp != 's' && resp != 'S' && resp != 'N' && resp != 'n');

                if (resp == 's' || resp == 'S') {
                    i = 3;
                }
                else {
                    cout << "\nCuantos dados quieres guardar?  (si quieres tirar todos de nuevo escribe 0): ";
                    do {
                        cin >> cuantos_guard;
                    } while (cuantos_guard < 0 || cuantos_guard > 5);
                    reserva = cuantos_guard;
                    capturador(dados, cuantos_guard);
                    system("cls");
                }
            }
        }

        contar_sumar(dados,puntajes);

        if (cjug > 1){
            if (ronda % 2 == 0){
                YH1 += preguntador(puntajes,J1, 1);
            }
            else{
                YH2 += preguntador(puntajes,J2,2);
            }
        }
        else{
            YH1 += preguntador(puntajes,J1,1);
        }

        cerador(puntajes, true);

        ronda += 1;

        if(cjug == 2 && ronda % 2 == 0){
            r += 1;
            while ((c = getchar()) != '\n') {}
            system("cls");
            cout << "Los puntajes actuales son: ";
            imp_tabla(puntajes, cjug, aka1, aka2, false);
            cout << "\nPara continuar presiona enter...";
            cin.get();
        }
        else if(cjug == 1){
            r += 1;
            if (ronda % 2 == 0){
                while ((c = getchar()) != '\n') {}
                system("cls");
                cout << "Los puntajes actuales son: ";
                imp_tabla(puntajes, cjug, aka1, aka2, false);
                cout << "\nPara continuar presiona enter...";
                cin.get();
            }
        }
    }while(r < 13);

    system("cls");
    pantalla_salida();

    cerador(puntajes, false);

    puntajes[1][13] = contador_final(puntajes, YH1, 1);
    puntajes[2][13] = contador_final(puntajes, YH2, 2);

    if (cjug == 1){
        cout << "Bien hecho," << J1 <<"tu puntaje fue de: " << puntajes[1][13];
        imp_tabla(puntajes, cjug, aka1, aka2, true);
    }
    else{
        if (puntajes[1][12] > puntajes[2][12]){
            cout << "Felicidades "<< J1 << ", eres el ganador con " << puntajes[1][13] << " puntos";
            imp_tabla(puntajes, cjug, aka1, aka2, true);
        }
        else if(puntajes[1][12] == puntajes[2][12]){
            cout << "Tenemos un Empate!!";
            imp_tabla(puntajes, cjug, aka1, aka2, true);
        }
        else{
            cout << "Felicidades "<< J2 << ", eres el ganador con " << puntajes[2][13] << " puntos";
            imp_tabla(puntajes, cjug, aka1, aka2, true);
        }
    }
}
//================================================= [   RONDAS  ] =======================================================

void iniciador(int tablero [3][14]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (i != 0){
                tablero[i][j] = -1;
            }
            else{
                tablero[i][j] = 0;
            }
        }
    }
}

void iniciador_dados(int dados0[], int res){
    for (int i = res; i < 5; ++i) {
        dados0[i] = -1;
    }
}

void cerador(int puntos[3][14], bool partida){
    if (partida == true){
        for (int i = 0; i < 14; ++i) {
            puntos[0][i] = 0;
        }
    }
    else{
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 14; ++j) {
                if (puntos[i][j] == -1){
                    puntos[i][j] = 0;
                }
            }
        }
    }
}

void randomizador (int dadosg[]) {
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        if (dadosg[i] == - 1){
            dadosg[i] = rand() % 6 + 1;
        }
    }
}

void capturador(int para_capturar[], int tama) {
    int x, aux[tama], ac = 0;
    bool revisor;

    for (int i = 0; i < tama; ++i) {
        aux[i] = -1;
    }

    for (int i = 0; i < tama; ++i) {
        do {
            revisor = true;
            cout << i + 1 << " Dado a guardar:";
            do {
                cin >> x;
            } while (x < 0 || x > 5);

            for (int j = 0; j < tama; ++j) {
                if (x-1 == aux[j]) {
                    revisor = false;
                    break;
                }
            }
            if (revisor == true) {
                aux[ac] = x - 1;
                ac += 1;
            }
            else {
                cout << "No haga trampa, cabron, vuelva a introducir su dado a guardar\n";
            }
        } while (revisor == false);
    }
    for (int i = 0; i < tama; ++i) {
        para_capturar[i] = para_capturar[aux[i]];
    }
}

//============================================ [   COMPROBAR JUGADA   ] =================================================

int preguntador(int totales[3][14],char nombre[], int id){
    int resp;
    bool band = false;
    cout << "\nPuedes poner tus puntos en las siguientes secciones, "<< nombre << ": \n";

    for (int i = 0; i < 6; ++i) {
        if (totales[0][i] != 0 && totales[id][i] == -1){
            cout << i+1 << ".-" <<"Sumar solo " << i+1 << "'s\n";
            band = true;
        }
    }

    if(totales[0][6] != 0 && totales[id][6] == -1){
        cout << "7.- Tienes 3 Iguales!!  (Suma todos los dados)\n";
        band = true;
    }
    if(totales[0][7] != 0 && totales[id][7] == -1){
        cout << "8.- Tienes 4 Iguales!!  (Suma todos los dados)\n";
        band = true;
    }
    if(totales[0][8] != 0 && totales[id][8] == -1){
        cout << "9.- Tines un Full House!!   (25 Puntos)\n";
        band = true;
    }
    if(totales[0][9] != 0 && totales[id][9] == -1){
        cout << "10.- Tienes 4 En secuencia!!   (30 puntos)\n";
        band = true;
    }
    if(totales[0][10] != 0 && totales[id][10] == -1){
        cout << "11.- Tienes 5 En secuencia!!   (40 puntos)\n";
        band = true;
    }
    if (totales[0][11] !=0 && totales[id][11] == -1){
        cout << "12.- Tienes un YAHTZEE!!!     (50 Puntos)\n";
        band = true;
    }
    if (totales[0][12] != 0 && totales[id][12] == -1){
        cout << "13.- Puedes usar tu Oportunidad    (Suma de todos los dados)\n";
        band = true;
    }

    if (band == true){
        cout << "\nEn que seccion quieres poner tus puntos "<< nombre << "? ";

        do{
            cin >> resp;
        } while (totales[0][resp-1] == 0 || totales[id][resp-1] != -1);

        if (resp == 12){
            return 1;
        }
        totales[id][resp-1] = totales[0][resp-1];
    }
    else{
        cout << "\nTus dados no parecen ser utiles, en que seccion quieres poner un 0, "<< nombre << "? :(\n";
        for (int i = 0; i < 6; ++i) {
            if (totales[id][i] == -1){
                cout << i+1 << ".-" <<"Solo " << i+1 << "'s (0 puntos) \n";
            }
        }
        if(totales[id][6] == -1){
            cout << "7.- 3 Iguales  (0 puntos)\n";
        }
        if(totales[id][7] == -1){
            cout << "8.- 4 Iguales  (0 puntos)\n";
        }
        if(totales[id][8] == -1){
            cout << "9.- En Full House   (0 puntos)\n";
        }
        if(totales[id][9] == -1){
            cout << "10.- 4 En secuencia   (0 puntos)\n";
        }
        if(totales[id][10] == -1){
            cout << "11.- 5 En secuencia   (0 puntos)\n";
        }
        if (totales[id][11] == -1){
            cout << "12.- En Yahtzee     (0 puntos)\n";
        }
        if (totales[id][12] == -1){
            cout << "13.- Usarlo en Oportunidad    (0 puntos)\n";
        }

        cout << "\nSelecciona una de la lista: ";

        do{
            cin >> resp;
        } while (resp < 1 || resp > 13 || totales[id][resp-1] != -1);
        totales[id][resp-1] = totales[0][resp-1];
    }
    return 0;
}

void contar_sumar(int arreglo[], int totales[3][14]){
    int inter, auxiliar, igual3 = 0, igual4 = 0, FH = 0, sec = 1, YA = 0, tot = 0;

    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (arreglo[j] == i){
                totales[0][i-1] += arreglo[j];
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        tot += arreglo[i];
    }

    do {
        inter = 0;
        for (int i = 0; i < 4; i++){
            if (arreglo[i+1] < arreglo[i]) {
                auxiliar = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = auxiliar;
                inter = 1;
            }
        }
    } while (inter > 0);

    for (int i = 0; i < 3; ++i) {
        if (arreglo [i] == arreglo[i+1] && arreglo [i] == arreglo[i+2]){
            igual3 = 1;
        }
    }

    for (int i = 0; i < 2; ++i) {
        if (arreglo [i] == arreglo[i+1] && arreglo [i] == arreglo[i+2] && arreglo[i+1] == arreglo[i+3]){
            igual4 = 1;
        }
    }

    if (arreglo[0] == arreglo[1] && arreglo[2] == arreglo[4] && arreglo[0]!= arreglo[4]){
        FH = 1;
    }
    if (arreglo[0] == arreglo[2] && arreglo[3] == arreglo[4] && arreglo[0] != arreglo[4]){
        FH = 1;
    }

    for (int i = 0; i < 5; ++i) {
        if (arreglo[i] + 1 == arreglo[i+1]){
            sec += 1;
        }
    }

    if (arreglo[0] == arreglo[1] && arreglo[1] == arreglo[3] && arreglo[3] == arreglo[4]){
        YA = 1;
    }

    totales[0][12] = tot;
    puntador(totales, igual3, igual4, YA, FH, sec, tot);
}

void puntador(int total[3][14],int i3, int i4, int i5, int full, int se, int totale){
    if (i3 == 1){
        total[0][6]=totale;
    }
    if (i4 == 1){
        total[0][7]=totale;
    }
    if (full == 1){
        total[0][8] = 25;
    }
    if (se == 4){
        total[0][9] = 30;
    }
    if (se == 5){
        total[0][10] = 40;
    }
    if (i5 == 1){
        total[0][11] = 50;
    }
}
//================================================ [   GANADOR   ] ======================================================

int contador_final(int totales[3][14], int yaht, int id){
    int total = 0;
    for (int i = 0; i < 6; ++i) {
        total += totales[id][i];
    }

    if (total >= 63){
        total += 35;
    }

    for (int i = 6; i < 13; ++i) {
        total += totales[id][i];
    }

    if (yaht > 0){
        if(yaht == 1){
            totales += 50;
        }
        else{
            yaht -= 1;
            total = total + 50 + yaht * 100;
        }
    }

    return total;
}

//============================================== [   IMPRIMIBLES   ] ====================================================

void pantalla_bien(){
    cout << "Bienvenido a\n \n";
    cout << "  ___    ___ ________  ___  ___  _________  ________  _______   _______          \n"
            " |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\|\\___   ___\\\\_____  \\|\\  ___ \\ |\\  ___ \\         \n"
            " \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\\\  \\|___ \\  \\_|\\|___/  /\\ \\   __/|\\ \\   __/|        \n"
            "  \\ \\    / / \\ \\   __  \\ \\   __  \\   \\ \\  \\     /  / /\\ \\  \\_|/_\\ \\  \\_|/__      \n"
            "   \\/  /  /   \\ \\  \\ \\  \\ \\  \\ \\  \\   \\ \\  \\   /  /_/__\\ \\  \\_|\\ \\ \\  \\_|\\ \\     \n"
            " __/  / /      \\ \\__\\ \\__\\ \\__\\ \\__\\   \\ \\__\\ |\\________\\ \\_______\\ \\_______\\    \n"
            "|\\___/ /        \\|__|\\|__|\\|__|\\|__|    \\|__|  \\|_______|\\|_______|\\|_______|    \n"
            "\\|___|/                                                                          \n"
            "                                                                                 \n";
    cout << "     Por Miguel Calata                                                   Presiona enter para continuar..."; cin.get();
}

void pantalla_salida(){
    int c;
    cout << "La partida ha terminado\n \n";
    cout << " ________  ________  _____ ______   _______           ________  ___      ___ _______   ________     \n"
            "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\    \n"
            "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\   \n"
            " \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\  \n"
            "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\| \n"
            "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\ \n"
            "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|__|/       \\|_______|\\|__|\\|__|\n"
            "                                                                                                    ";
    while ((c = getchar()) != '\n') {}
    cout << "Presiona enter para conocer al ganador..."; cin.get();
}

void imp_tabla(int tabla[3][14], int jugadores, char apodo1[3], char apodo2[3], bool band){
    int aiudaaaa;
    if (band == false){
        aiudaaaa = 13;
    }
    else{
        aiudaaaa = 14;
    }
    cout << endl <<"+---------+-------+";
    if(jugadores == 2){
        cout << "-------+";
    }
    cout << endl;
    cout << "| Jugadas |  "<<apodo1<<"  |";
    if (jugadores == 2){
        cout << "  "<<apodo2<<"  |";
    }
    cout << endl <<"+---------+-------+";
    if(jugadores == 2){
        cout << "-------+";
    }
    cout << endl;
    for (int i = 0; i < aiudaaaa; ++i) {
        imp_reng(i);
        for (int j = 1; j < jugadores + 1; ++j){
            if (tabla[j][i] < 10 && tabla[j][i] >= 0){
                cout << " ";
            }
            if (tabla[j][i] == -1){
                cout << "    |   ";
            }
            else if(tabla[j][i] < 10 ){
                cout << tabla[j][i] << "  |   ";
            }
            else{
                cout << tabla[j][i] << "  |   ";
            }
        }
        cout << endl;
    }
    cout <<"+---------+-------+";
    if(jugadores == 2){
        cout << "-------+";
    }
}

void imp_reng(int dato) {
    switch (dato) {
        case 0:
            cout << "|   1's   |   ";
            break;
        case 1:
            cout << "|   2's   |   ";
            break;
        case 2:
            cout << "|   3's   |   ";
            break;
        case 3:
            cout << "|   4's   |   ";
            break;
        case 4:
            cout << "|   5's   |   ";
            break;
        case 5:
            cout << "|   6's   |   ";
            break;
        case 6:
            cout << "|3 Iguales|   ";
            break;
        case 7:
            cout << "|4 Iguales|   ";
            break;
        case 8:
            cout << "|   Full  |   ";
            break;
        case 9:
            cout << "|  Sec 4  |   ";
            break;
        case 10:
            cout << "|  Sec 5  |   ";
            break;
        case 11:
            cout << "| YAHTZEE |   ";
            break;
        case 12:
            cout << "|  Oport  |   ";
            break;
        case 13:
            cout << "|  TOTAL  |   ";
            break;
        default:
            cout << "Error total   ";
    }
}

void imp_UI(char nombres[], int ronda_ac, int tir){
    cout << "\n[ Ronda: "<< ronda_ac <<" ]         [ Jugando: "<< nombres <<"]      [ Tirada: "<< tir+1 <<"]\n" << endl;
}

void imp_dados (int dados[]){
    cout << "      Dado 1:          Dado 2:          Dado 3:          Dado 4:          Dado 5:\n";
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 5; ++j) {
            switch (i) {
                case 0:
                    cout << "      _______.   ";
                    break;
                case 1:
                    dado1(dados[j]);
                    break;
                case 2:
                    dado2(dados[j]);
                    break;
                case 3:
                    dado3(dados[j]);
                    break;
                case 4:
                    cout << "     |_______|.'|";
                    break;
                case 5:
                    cout << "      \\ '  '  \\'|";
                    break;
                case 6:
                    cout << "       \\_'__'__\\|";
                    break;
                default:
                    cout << "Error Fatal";
            }
        }
        cout << endl;
    }
}

void dado1(int da){
    if (da == 1){
        cout << "     |       |\\  ";
    }
    else if (da == 2 || da == 3){
        cout << "     | o     |\\  ";
    }
    else if (da == 4 || da == 5 || da == 6){
        cout << "     | o   o |\\  ";
    }
    else{
        cout << "     |       |\\  ";
    }
}
void dado2(int da){
    if (da == 1 || da == 3 || da == 5){
        cout << "     |   o   |.\\ ";
    }
    else if (da == 2 || da == 4){
        cout << "     |       | \\ ";
    }

    else if (da == 6){
        cout << "     | o   o | \\ ";
    }
    else{
        cout << "     |       | \\ ";
    }
}
void dado3(int da){
    if (da == 4 || da == 5 || da == 6){
        cout << "     | o   o |. \\";
    }
    else if (da == 2 || da == 3){
        cout << "     |     o |  \\";
    }

    else if (da == 1){
        cout << "     |       |  \\";
    }
    else{
        cout << "     |       |  \\";
    }
}// :)