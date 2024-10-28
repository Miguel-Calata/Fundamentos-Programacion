/*  Miguel Salvador Calata Rodríguez
 *  Practica 63 - Ejercicio programacion modular */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int n;
void capturador(int[], int);
void impresor(int[], int);
void randomizador_v0 (int [], int);
void cambiador(int, int,int[]);
void arreglador(int[], int[], int[], int, int);
int buscador(int[]);
float operador(int, int, int);

int main(){
    int arre1[10], arre2[5];
    int escoger, arr;
    cout << "Introducir el tamanio del arreglo 3: "; cin >> n;
    int arre3[n];

    randomizador_v0(arre1, 10);
    randomizador_v0(arre2, 5);
    randomizador_v0(arre3, n);

    cout << "Que arreglo quires modificar?\n1.- Primero (10 elementos)\n 2.- Segundo (5 elementos)\n 3.- Tercero (variable)\n";
    cin >> arr;

    cout << "Seleccione la accion a realizar: \n1.- Llenar un arreglo \n"
            "2.- Mostrar arreglo \n3.- Extraer un dato \n4.-Realizar operacion con dato\n"
            "5.- Cambiar dato \n"; cin >> escoger;
    arreglador(arre1,arre2,arre3, arr, escoger);
}

void cambiador(int escoger, int t, int arrEsc []){
    int op1, op2, op;

    switch (escoger) {
        case 1:
            capturador(arrEsc, t);
            impresor(arrEsc, t);
            break;
        case 2:
            impresor(arrEsc, t);
            break;
        case 3:
            cout << buscador(arrEsc);
            break;
        case 4:
            op1 = buscador(arrEsc);
            op2 = buscador(arrEsc);
            cout << "Que oparacion desea realizar:\n1.- Sumas\n2.- Resta\n3.-Division\n4.-Multiplicacion";
            cin >> op;
            cout << "El resultado es: " << operador(op1, op2, op);
            break;
        default:
            cout << "Error Fatal";
    }
}

void arreglador(int arr1 [], int arr2 [], int arr3[], int seleccion, int accion){
    if(seleccion == 1) {
        cambiador(accion, 10, arr1);
    }
    else if (seleccion == 2){
        cambiador(accion, 5, arr2);
    }
    else if (seleccion == 3){
        cambiador(accion,n, arr3);
    }
}

void capturador(int arrCam[], int tam){
    for (int i = 0; i < tam; ++i) {
        cin >> arrCam[i];
    }
}

void impresor(int arrCam[], int tam){
    for (int i = 0; i < tam; ++i) {
        cout << arrCam[i] << " ";
    }
}

int buscador(int arr[]){
    int busPos;
    cout << "En que posición quieres buscar? "; cin >> busPos;

    return arr[busPos];
}

float operador(int a, int b, int op){
    if (op == 1){
        return a + b;
    }
    else if (op == 2){
        return a - b;
    }
    else if (op == 3){
        return a / b;
    }
    else if (op == 4){
        return a * b;
    }
    else{
        return 3.141592;
    }
}

void randomizador_v0 (int arreglo[], int tamal){
    srand(time(nullptr));
    for (int i = 0; i < tamal; ++i) {
        arreglo[i] = rand() % 1 + 42;
    }
}
