/*Miguel Salvador Calata Rodríguez
Actividad del día 20/02/2024 - Práctica 19 Triangulos de distintos tipos */
#include <iostream>
using namespace std;

main (){
	setlocale(LC_ALL, "spanish");
	float lad1, lad2, lad3;
	
	cout<<"Incerte el primer lado: "; cin>>lad1;
	cout<<"Incerte el segundo lado: "; cin>>lad2;	
	cout<<"Incerte el tercer lado: "; cin>>lad3;
	
	if(lad1 == lad2  && lad2 == lad3 ){
		cout<<"El tríangulo es equilatero";
		
	}
	else if (lad1 == lad2 || lad2 == lad3 || lad3 == lad1){
		cout<<"El tríagunlo es isoceles";
	}
	else {
		cout<<"El tríagulo es escaleno";
	}
}
