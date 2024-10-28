#include <iostream>

using namespace std;

const int n = 15, p = 3;
int arreglo[n][p] ={{1,15,15},
                    {2,15,15},
                    {3,15,15},
                    {4,15,15},
                    {15,5,15},
                    {15,6,15},
                    {15,7,15},
                    {15,8,15},
                    {15,9,15},
                    {15,10,15},
                    {11,11,15},
                    {12,12,15},
                    {13,13,15},
                    {15,15,14},
                    {15,15,14}};

int trans ( int estadoActual, int entrada){
    if (entrada >= 48 && entrada <= 57){
        return arreglo[estadoActual][entrada -48];
    }
    else if ( entrada == 0){
        return arreglo[estadoActual][2];
    }
    else{
        return 6;
    }
}

int main(){
    char palabra[128];
    int estado = 0;

    cout << "Palabra: ";
    cin >> palabra;

    for (int i = 0; estado < 5; i++)
        estado = trans(estado, palabra[i]);

    if (estado == 5)
        cout << "ACEPTABLE";
    else
        cout << "RECHAZADO";

    cout << arreglo[2][2];

}
