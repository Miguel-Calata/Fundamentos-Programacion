/*Miguel Salvador Calata Rodríguez
Práctica 20 - Determinar cual es valor mayor y menor*/
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int n, n_mayor, n_menor;
	
	cout<<"Favor de introducir el primer número: "; cin>>n;
	n_mayor = n;
	n_menor = n;
	
	cout<<"Favor de introducir el segundo número: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el tercer número: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el cuarto número: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el quinto número: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"El valor más grande fue: "<<n_mayor<<", el valor menor introducido fue: "<<n_menor;
}
