/* Miguel Salvador Calata Rodr�guez
Pr�ctica 14 Calificaciones y Mensajes del d�a 13/02/2024 */	
#include<iostream>
using namespace std;

main(){
	setlocale(LC_ALL,"spanish");
	int calif;
	
	cout<<"Favor de incertar una calificaci�n: ";cin>>calif;
	
	if(calif==100){
		cout<<"Excelente";
	}
	else if(calif>=80){
		cout<<"Muy bien";
	}
	else if(calif>=60){
		cout<<"Bien";
	}
	else if(calif>=40){
		cout<<"Mal";
	}
	else if(calif>=0){
		cout<<"P�simo";
	}
	
}	
