/*Miguel Salvador Calata Rodr�guez
Actividad del d�a 20/02/2024 -  Pr�ctica 17 - Conteo de cantidad de cifras*/
#include <iostream>
using namespace std;

main (){
	setlocale(LC_ALL, "spanish");
	float num, cant;
	
	cout<<"Incerte un n�mero: "; cin>>num;

	if(num >= 0 && num <= 32700){
		
		if (num < 10){
			cout<<"El n�mero tiene una cifra";
		}
		else if (num < 100){
			cout<<"El n�mero tiene 2 cifras";
		}
		else if (num < 1000){
			cout<<"El n�mero tiene 3 cifras";
		}
		else if (num < 10000){
			cout<<"El n�mero tiene 4 cifras";
		}
		else {
			cout<<"El n�mero tiene 5 cifras";
		}
	}
	
	
}
