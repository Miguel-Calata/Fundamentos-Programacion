//Yahtzee Game/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void inicio(); //breve pantalla de inicio sin uso (anuncio)
void select(); //selecciona cuantos jugadores pueden jugar en la partida
void dados(int jugador, int puntajes[]); //funcion que muestra los dados y los accióna 
void landados();
void tabla(int puntajes1[], int puntajes2[]); //funcion que muestra la tabla de puntos
void muestra(int puntajes1[],int puntajes2[],int ronda); //funcion para sumar los numeros de cada dado e ingresarlos a la tabla 
void resultado(); //funcion que muestra el resultado de la partida
int j1, j2; //variables de cuantos jugadores pueden jugar y los puntos que se les asigna a cada uno



int main() {
  inicio();
  select();
  int puntajes_jugador1[6]= {0}; // Arreglo para almacenar los puntajes del jugador 1
  int puntajes_jugador2[6]= {0}; // Arreglo para almacenar los puntajes del jugador 2

  for(int ronda= 0; ronda<13;++ronda){
    cout<<"Ronda "<<ronda + 1 <<endl;
    cout << "\n del jugador 1:" << endl;
      dados(1, puntajes_jugador1); // Jugador 1 lanza los dados y actualiza sus puntajes
      tabla(puntajes_jugador1, puntajes_jugador2);
      muestra(puntajes_jugador1, puntajes_jugador2, ronda); // Mostrar los resultados de la ronda
      cout << "\nTurno del jugador 2:"<<endl;
      dados(2, puntajes_jugador2); // Jugador 2 lanza los dados y actualiza sus puntajes
      tabla(puntajes_jugador1, puntajes_jugador2);
      muestra(puntajes_jugador1, puntajes_jugador2, ronda); // Mostrar los resultados de la ronda
  }
  tabla(puntajes_jugador1, puntajes_jugador2); // Mostrar la tabla de puntuaciones final
 
}

void inicio() {
  cout<<"{----------------------------------------------}"<<endl;
  cout<<"| Bienvenido a Yahtzee, el juego de dados más  |"<<endl;
  cout<<"| divertido que hayas visto.                   |"<<endl;
  cout<<"|                                              |"<<endl;
  cout<<"|                                              |"<<endl;
  cout<<"{----------------------------------------------}"<<endl;
  cout<<"|                    INICIO                    |"<<endl;
  cout<<"|                                              |"<<endl;
  cout<<"{----------------------------------------------}"<<endl;
  
}
void select(){
  cout<<"| Cuantos jugadores pueden jugar? (1-2):        |"<<endl;
  cin>>j1; //Asignar el número de jugadores a j1
  if(j1 == 2){
      cout<<"Jugador dos se uni a la partida..." << endl;
      //Si hay dos jugadores, solicitar el nombre del segundo jugador u otras opciones.
  } else if (j1 == 1) {
      cout << "Solo un jugador puede jugar." << endl;
  } else {
      cout << "solo pueden jugar 2 o 1 jugador, seleccione 1 o 2." << endl;
      // Manejar el caso donde el número de jugadores es inválido.
  }

  
}

void dados(int jugador, int puntajes[]) {
	srand(time(NULL));
  int nD;
  int val;
  int punt= 0;
  val = rand() % 6 + 1;
  cout<<"\nSeleccione cuántos dados desea lanzar (1-5): ";
  cin>>nD;

  for(int i=0; i<nD; i++){
    val = rand() % 6 + 1;
    cout<<"+---+";
    cout<<"\n| "<<val<<" |";
    cout<<"\n+---+";
    punt += val;
  }
  cout<<"\nLa suma de los dados es: "<<punt;
}

void tabla(int puntajes1[], int puntajes2[]){
  cout<<"\nTabla de puntuaciones:"<<endl;
  cout<<"Jugador 1:"<<endl;
  for(int i=0; i<6;++i){
    cout<<"Puntuación para el número "<<i + 1<<": "<<endl;
    cin>>puntajes2[i];
  }
}

void muestra(int puntajes1[],int puntajes2[],int ronda){
  cout<<"\nResultados de la ronda "<<ronda+1<<":"<<endl;
   cout<<"Jugador 1:"<<endl;
    for(int i = 0; i < 6; ++i){
      cout<<"Cantidad de "<<i + 1<<"'s: "<<puntajes1[i]<<endl;
  }
  
  cout << "Jugador 2:" << endl;
    for (int i = 0; i < 6; ++i){
      cout<< "Cantidad de "<<i + 1<<"'s: " <<puntajes2[i]<<endl;
    }
}

void resultado(int puntajes_jugador1[],int puntajes_jugador2[]){
  bool yahtzee_jugador1 = false;
  bool yahtzee_jugador2 = false;

// Verificamos si el jugador 1 tiene Yahtzee
    for (int i = 0; i < 6; ++i){
      if (puntajes_jugador1[i] >= 5){
        yahtzee_jugador1 = true;
        break;
      }
    }
// Verificamos si el jugador 2 tiene Yahtzee
	for (int i = 0; i < 6; ++i) {
	    if (puntajes_jugador2[i] >= 5) {
	        yahtzee_jugador2 = true;
	        break;
	    }
	}
	// Mostramos el resultado
	if (yahtzee_jugador1) {
	    cout << "¡Yahtzee para el Jugador 1!" << endl;
	} 
	else if (yahtzee_jugador2) {
	    cout << "¡Yahtzee para el Jugador 2!" << endl;
	}
	else {
		cout << "Ninguno de los jugadores alcanzó el Yahtzee";
	}
}
