//PROYECTO FINAL FUNDAMENTOS DE PROGRAMACIÓN
//OLIVARES GASPAR JUAN ANTONIO
//Juego de Yahtzee

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int dados[5];
int jugador1[15];
int jugador2[15];
void tirar_dados(int);
void revisar_dados();
void sumar_puntos();
int asignar_puntos(int);
main(){
    setlocale(LC_ALL,"spanish");
    int numero_jug, dados_apartados = -1, repetir = 13, almacenar_puntos;
    cout<<"ingresa el numero de jugadores 1 o 2: ";
    cin>>numero_jug;
    if (numero_jug==2){
        repetir=26;
    }
    for (int ronda=0; ronda<repetir;ronda++) {
        for (int tirada = 0; tirada < 2; ++tirada) {
            tirar_dados(dados_apartados);
            cout<<"Tus dados son:\n";
            for (int i=0; i<5; i++) {
                cout << "Dado "<<i+1<<": "<<dados[i]<<"  ";
            }
            cout<<"cual valor desea guardar?";
            cin >> dados_apartados;
        }
        for (int i=0; i<5; i++) {
            cout << "Dado "<<i+1<<": "<<dados[i]<<"  ";
        }
        revisar_dados();
        cout<<"\nDonde quieres acomodar tus dados?";
        cin >>almacenar_puntos;
        if (numero_jug==2){
            if(ronda%2==0){
                jugador1[almacenar_puntos-1]=asignar_puntos(almacenar_puntos);
            }            // a la posición del arreglo se le asigna el valor que regresea de la funcion asignar_puntos
            else{
                jugador2[almacenar_puntos-1]=asignar_puntos(almacenar_puntos);
            }
        }
        else{
            jugador1[almacenar_puntos-1]= asignar_puntos(almacenar_puntos);
        }
    }
    sumar_puntos();
    if(jugador1[14]>jugador2[14]){
        cout<<"Gana el jugador 1";
    }
    else{
        cout<<"Gana el jugador 1";
    }
}

void tirar_dados(int apartados){
    srand(time(0));     //llena los dados con un numero aleatorio solo si son distintos al numero
    for (int i=0; i<5; i++) {       //indicado por el usuario   (si el usuario pone un 6, solo los 6 se guardan)
        if (dados[i] != apartados){
            dados[i]=1+rand() %6;
        }
    }
}

void revisar_dados(){
    int unos=0, doses=0, treses=0, cuatros=0, cincos=0, seises=0;
    for (int i=0; i<5; i++) {
        if(dados[i]==1){          //Evalua cuantos de cada dado hay en una tirada de dados
            unos+=1;
        }
        if(dados[i]==2){
            doses+=1;
        }
        if(dados[i]==3){
            treses+=1;
        }
        if(dados[i]==4){
            cuatros+=1;
        }
        if(dados[i]==5){
            cincos+=1;
        }
        if(dados[i]==6){
            seises+=1;
        }
    }
    if(unos != 0){                 //imprime donde el usuario puedo poner su jugada (primera seccion)
        cout<<"1- poner en unos\n";
    }
    if(doses != 0){
        cout<<"2- poner en los dos\n";
    }
    if(treses != 0){
        cout<<"3- poner en los tres\n";
    }
    if(cuatros != 0){
        cout<<"4- poner en cuatros\n";
    }
    if(cincos != 0){
        cout<<"5- poner en cincos\n";
    }
    if(seises != 0){
        cout<<"6- poner en seis\n";
    }                               //----------------------------------------------------------------
    if(unos==3||doses==3||treses==3||cuatros==3||cincos==3||seises==3){//revisa si hay 3 iguales
        cout<<"7- tiene 3 iguales\n";
    }
    if(unos==4||doses==4||treses==4||cuatros==4||cincos==4||seises==4){//revisa si hay 4 iguales
        cout<<"8- tiene 4 iguales\n";
    }
    if(unos==2&&doses==3||doses==3&&treses==2||cuatros==2&&cincos==3||cincos==3&&seises==2){//revisa si tienes un full house creo que no esta completo
        cout<<"9- tienes un full house\n";
    }
    else if(doses==2&&unos==3||doses==2&&treses==3||cuatros==3&&cincos==2||cincos==2&&seises==3){
        cout<<"9- tienes un full house\n";
    }
    else if(cuatros==2&&treses==3||treses==2&&cuatros==3||cincos==2&&seises==3||doses==3&&cuatros==2){//-------------------------------
        cout<<"9- tienes un full house\n";
    }
    if(unos==1&&doses==1&&treses==1&&cuatros==1){//revisa si hay una secuencia de 4
        cout<<"10- tienes 4 en secuencia\n";
    }
    else if(doses==1&&treses==1&&cuatros==1&&cincos==1){
        cout<<"10- tienes 4 en secuencia\n";
    }
    else if(treses==1&&cuatros==1&&cincos==1&&seises==1){
        cout<<"10- tienes 4 en secuencia\n";
    }//----------------------------------------------------------------------------------------------
    if(unos==1&&doses==1&&treses==1&&cuatros==1&&cincos==1){//revisa si hay una secuencia de 5
        cout<<"11- tienes 5 en secuencia\n";
    }
    else if(doses==1&&treses==1&&cuatros==1&&cincos==1&&seises==1){
        cout<<"12- tienes 5 en secuencia\n";
    }//----------------------------------------------------------------------------------------------
    if(unos==5||doses==5||treses==5||cuatros==5||cincos==5||seises==5){//revisa si hay un yahtzee, osea todos iguales
        cout<<"12- tienes un Yahtzee!!\n";
    }
    cout<<"13- Puedes usar oportunidad\n";
}

int asignar_puntos(int eleccion){//Esta funcion cuenta cuantos puntos tiene la jugada que el usuario seleccionó en l
    int unos=0, doses=0, treses=0, cuatros=0, cincos=0, seises=0, suma=0;
    for (int i=0; i<5; i++) {
        if(dados[i]==1){          //Evalua cuantos de cada dado hay en una tirada de dados y va haciendo una sumatoria de total
            unos+=1;
            suma+=1;
        }
        if(dados[i]==2){
            doses+=1;
            suma+=2;
        }
        if(dados[i]==3){
            treses+=1;
            suma+=3;
        }
        if(dados[i]==4){
            cuatros+=1;
            suma+=4;
        }
        if(dados[i]==5){
            cincos+=1;
            suma+=5;
        }
        if(dados[i]==6){
            seises+=1;
            suma+=6;
        }
    }//------------------------------------------------------------------------------------------------------------------

    if (eleccion==1){//En esta parte se regresa el conteo de los puntos para el arreglo de puntos finales  jugador1 y jugador2
        return 1*unos;
    }
    else if(eleccion==2){
        return  2*doses;//dependiendo de los dados de cada tipo se multiplican por su valor  - ej. si hay 3 dos se evalua 2*3 = 6
    }
    else if(eleccion==3){
        return 3*treses;
    }
    else if(eleccion==4){
        return  4*cuatros;
    }
    else if(eleccion==5){
        return 5*cincos;
    }
    else if(eleccion==6){
        return  6*seises;
    }
    else if(eleccion==7||eleccion==8||eleccion==13){//si la eleccion es 7 8 o 13 se regresa la suma
        return suma;
    }
    else if(eleccion==9){//para las demas elecciones se regresa un valor fijo
        return 25;
    }
    else if(eleccion==10){
        return 30;
    }
    else if(eleccion==11){
        return 40;
    }
    else if(eleccion==12){
        return 50;
    }
    else{
        return 0;
    }
}

void sumar_puntos(){
    int total_de_jugador1, total_de_jugador2;
    for (int i = 0; i < 13; ++i) {
        total_de_jugador1+=jugador1[i];
        total_de_jugador2+=jugador2[i];
    }
    jugador1[14]=total_de_jugador1;
    jugador2[14]=total_de_jugador2;
}
