/* Miguel Salvador Calata Rodr�guez
Pr�ctica 15 Edades del d�a 13/02/2024*/	
#include<iostream>
using namespace std;

main(){
	setlocale(LC_ALL,"spanish");
	int edad;
	
	cout<<"Favor de incertar una edad: ";cin>>edad;
	
	if(edad>=60){
		cout<<"Viejito";
	}
	else if(edad>=36){
		cout<<"Adulto";
	}
	else if(edad>=18){
		cout<<"Adulto joven";
	}
	else if(edad>=14){
		cout<<"Adoolescente";
	}
	else if(edad>=0){
		cout<<"Ni�o";
	}
	
}
