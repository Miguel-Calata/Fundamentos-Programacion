/* Miguel Salvador Calata Rodríguez
    Proyecto Final de Programación  juego de Yahtzee*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int totales[13];
char pos[5];
int nR = 1;

void ronda(int[], int, int);
void iniciador_dados(int[], int, int );
void randomizador(int [], int);
void mostrador_puntos(int[], int );
void capturador(int[], int, int );
void reservador (int[], int, int );
void imp_dados(int[]);
void cerador();
void puntador(int, int , int , int, int, int );


int preguntador();
void revisor(int[]);
void contar_sumar(int[]);

void dado1(int);
void dado2(int);
void dado3(int);


int main(){
    int dados[5], tirada = 0, reser = 0;
    cerador();



    ronda(dados, tirada, reser);
}

void ronda (int da_dos[], int t, int reservados){
    t +=1;
    iniciador_dados(da_dos, t, reservados);
}

void iniciador_dados(int dados0[], int ti, int res){
    for (int i = res; i < 5; ++i) {
        dados0[i] = -1;
    }
    randomizador(dados0, ti);
}

void randomizador (int dadosg[], int tir) {
    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        if (dadosg[i] == - 1){
            dadosg[i] = rand() % 6 + 1;
        }
    }
    if (tir >= 3){
        imp_dados(dadosg);
        contar_sumar(dadosg);
        preguntador();
    }
    else{
        mostrador_puntos(dadosg, tir);
    }

}

void mostrador_puntos (int dados[], int tira) {
    int cuantos_guard ;
    char resp;
    cout << "Tus puntajes obtenidos en los dados fueron:\n";

    imp_dados(dados);

    cout << "Te quieres quedar con toda tu jugada? S-.Si  N-.No";
    do {
        cin >> resp;
    } while (resp != 's' && resp != 'S' && resp != 'N' && resp != 'n');

    if (resp == 's' || resp == 'S') {
        reservador(dados, 5, tira);
    } else {
        cout << "Cuantos dados quieres guardar?  (si quieres tirar todos de nuevo escribe 0)\n";
        do {
            cin >> cuantos_guard;
        } while (cuantos_guard < 0 || cuantos_guard > 5);
        capturador(dados, cuantos_guard, tira);
    }
}

void capturador(int para_capturar[], int tama, int ti){
    int x, y[tama], ac = 0;
    for (int i = 0; i < tama; ++i) {
        cout << i+1 << " Dado a guardar:"; cin >> x;
        y[ac] = para_capturar[x-1];
        ac += 1;
    }
    reservador(y, tama, ti);
}

void reservador(int por_reservar[], int tam, int tirada){
    int temp[tam], ac = 0;

    for (int i = 0; i < tam; ++i) {
        temp[i] = por_reservar[i];
    }
    cout << endl;
    ronda(temp, tirada, tam);
}

void cerador(){
    for (int i = 0; i < 13; ++i) {
        totales[i] = 0;
    }
}

//======================================================================================================================
int preguntador(){
    cout << "\nEn que seccion quieres poner tus putos? \n";

    for (int i = 0; i < 6; ++i) {
        if (totales[i] != 0){
            cout << "Sumar solo " << i+1 << "'s\n";
        }
    }


    if(totales[6] != 0){
        cout << "Tienes 3 Iguales!!  (Suma todos los dados)\n";
    }
    if(totales[7] != 0){
        cout << "Tienes 4 Iguales!!  (Suma todos los dados)\n";
    }
    if(totales[8] != 0){
        cout << "Tines un Full House!!   (25 Puntos)\n";
    }
    if(totales[9] != 0){
        cout << "Tienes 4 En secuencia!!   (30 puntos)\n";
    }
    if(totales[10] != 0){
        cout << "Tienes 5 En secuencia!!   (40 puntos)\n";
    }
    if (totales[11] !=0){
        cout << "Tienes un YAHTZEE!!!     (50 Puntos\n)";
    }
    if (totales[12] == 0){
        cout << "Puedes usar tu Oportunidad    (Suma de todos los dados)";
    }


    return 0;
}

void contar_sumar(int arreglo[]){
    int inter, auxiliar, igual3 = 0, igual4 = 0, FH = 0, sec = 1, YA = 0, tot = 0;
    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (arreglo[j] == i){
                totales[i-1] += arreglo[j];
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

    puntador(igual3, igual4, YA, FH, sec, tot);


    cout << "\n1:  2:  3:  4:  5:  6: 3i: 4i: FH:  S4: S5: YH: Op:";
    cout << endl;
    for (int i = 0; i < 13; ++i) {
        cout << totales[i] << "   ";
    }
}

void puntador(int i3, int i4, int i5, int full, int se, int total){
    if (i3 == 1){
        totales[6]=total;
    }
    if (i4 == 1){
        totales[7]=total;
    }
    if (i5 == 1){
        totales[11] = 50;
    }
    if (full == 1){
        totales[8] = 25;
    }
    if (se == 4){
        totales[9] = 30;
    }
    if (se == 5){
        totales[10] = 40;
    }
}

//=======================================================================================================================


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
}







/*for (int i = 0; i < 5; ++i) {
    if (dados[i] == 1){
        cout << "      _______.\n"
                "     |       |\\\n"
                "     |   o   |.\\\n"
                "     |       |.'|\n"
                "     |_______|.'|\n"
                "      \\ '  '  \\'|\n"
                "       \\_'__'__\\|\n";
    }
    else if (dados [i] == 2){
        cout << "      _______.\n"
                "     | o     |\\\n"
                "     |       |.\\\n"
                "     |     o |.'|\n"
                "     |_______|.'|\n"
                "      \\ ' .   \\'|\n"
                "       \\____'__\\|\n";
    }
    else if (dados [i] ==3){
        cout << "      _______.\n"
                "     | o     |\\\n"
                "     |   o   |.\\\n"
                "     |     o |.'|\n"
                "     |_______|.'|\n"
                "      \\   .   \\'|\n"
                "       \\_______\\|\n";
    }
    else if (dados [i] == 4){
        cout << "      _______.\n"
                "     | o   o |\\\n"
                "     |       |.\\\n"
                "     | o   o |.'|\n"
                "     |_______|.'|\n"
                "      \\ '     \\'|\n"
                "       \\____'__\\|\n";
    }
    else if (dados [i] == 5){
        cout << "      _______.\n"
                "     | o   o |\\\n"
                "     |   o   | \\\n"
                "     | o   o | ' |\n"
                "     |_______| ' |\n"
                "      \\ '   ' \\'|\n"
                "       \\_'__'__\\|\n";
    }
    else{
        cout << "      _______.\n"
                "     | o   o |\\\n"
                "     | o   o | \\\n"
                "     | o   o | '|\n"
                "     |_______| '|\n"
                "      \\ ' .   \\'|\n"
                "       \\____'__\\|\n";
    }

}


 cout << "      _______.";
    dado1(dados[i]);
    dado2(dados[i]);
    dado3(dados[i]);
    cout << "     |_______|.'|";
    cout << "     \\ '  '  \\'|";
    cout << "     \\_'__'__\\|";

    *dado5(dados[i]);
    dado6(dados[i]);




    cout << "   ___________________________________________________\n"
            "   |   Uno   |   Dos   |   Tres  |  Cuatro |  Cinco  |\n"
            "   +-------------------------------------------------+\n   ";
    for (int i = 0; i < 5; ++i) {
        cout << "|    " <<dados[i]<< "    ";
    }
    cout << "|\n   +-------------------------------------------------+";


    void posicion_valor (int posoval){
    int reservado;
    switch (posoval) {
        case 1:
            cout << "Cuales son los dados que quires guardar? (Ejemplo de Formato: 034)";
            cin >> pos;
        break;
        case 2:
            cout << "Cual es el valor a guardar? (Ejemplo de Formato: 4)";
            cin >> reservado;
            reservador(reservado);
        break;
        case 3:
            cout << "La razon de estos dos metodos de guardados es para poder jugar de forma mas estrategica:\n";
            cout << "Al guardar los Dados puedes introducir los dados que quires guardar y asi ir en busca de un Full house:\n";
            cout << "Al guardar el valor solo se guarda un numero, por ejemplo los 4's o 6's, util si buscas un Yahtzee.\n";
        break;
        default:
            cout << "Favor de introducir una opcion valida";
    }
}


 if (tam == 5){
        for (int i = 0; i < 5; ++i) {
            temp[i] = por_reservar[i];
        }
    }
    else{
        for (int i = 0; i < tam; ++i) {
            cout << por_reservar[i] << "  ";
        }
        cout << endl;
        for (int i = 0; i < tam; ++i) {
            if (i == por_reservar[i]){
                temp[ac] = por_reservar[i];
                ac +=1;
            }
        }
    }



     */
