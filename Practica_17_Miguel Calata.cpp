/*Miguel Salvador Calata Rodríguez
Actividad del día 20/02/2024 -  Práctica 17 - Conteo de cantidad de cifras*/
#include <iostream>
using namespace std;

main (){
	setlocale(LC_ALL, "spanish");
	float num, cant;
	
	cout<<"Incerte un número: "; cin>>num;

	if(num >= 0 && num <= 32700){
		
		if (num < 10){
			cout<<"El número tiene una cifra";
		}
		else if (num < 100){
			cout<<"El número tiene 2 cifras";
		}
		else if (num < 1000){
			cout<<"El número tiene 3 cifras";
		}
		else if (num < 10000){
			cout<<"El número tiene 4 cifras";
		}
		else {
			cout<<"El número tiene 5 cifras";
		}
	}
	
	
}
