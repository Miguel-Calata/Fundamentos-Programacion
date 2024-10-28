#include <iostream>
using namespace std;


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

int main() {
    const int tama = 5;
    int para_capturar[tama] = {1, 2, 3, 4, 5};
    imp_dados(para_capturar);
    cout << endl;
    capturador(para_capturar, tama);

    cout << "Los dados capturados son: ";
    for (int i = 0; i < tama; ++i) {
        cout << para_capturar[i] << " ";
    }
    cout << endl;

    return 0;
}


