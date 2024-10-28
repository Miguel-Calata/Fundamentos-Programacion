/* Miguel Salvador Calata Rodríguez
Práctica 28 - Signo zodiacal Chino */
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int anio, rest;
	
	cout<<"¿En que año naciste? "; cin>>anio;
	rest = anio % 12;
	
	switch (rest){
			case 0:
				cout<<"Tu signo es el Mono";
			break;
			case 1:
				cout<<"Tu signo es el Gallo";
			break;
			case 2:
				cout<<"Tu signo es el Perro";
			break;
			case 3:
				cout<<"Tu signo es el Cerdo";
			break;
			case 4:
				cout<<"Tu signo es la Rata";
			break;
			case 5:
				cout<<"Tu signo es el Buey";
			break;
			case 6:
				cout<<"Tu signo es el Tigre";
			break;
			case 7:
				cout<<"Tu signo es el Conejo";
			break;
			case 8:
				cout<<"Tu signo es el Dragón";
			break;
			case 9:
				cout<<"Tu signo es la Serpiente";
			break;
			case 10:
				cout<<"Tu signo es el caballo";
			break;
			case 11:
				cout<<"Tu signo es la Cabra";
		}	
}
