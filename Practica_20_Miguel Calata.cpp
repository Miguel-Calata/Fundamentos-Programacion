/*Miguel Salvador Calata Rodr�guez
Pr�ctica 20 - Determinar cual es valor mayor y menor*/
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int n, n_mayor, n_menor;
	
	cout<<"Favor de introducir el primer n�mero: "; cin>>n;
	n_mayor = n;
	n_menor = n;
	
	cout<<"Favor de introducir el segundo n�mero: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el tercer n�mero: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el cuarto n�mero: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"Favor de introducir el quinto n�mero: "; cin>>n;
	if (n > n_mayor){
		n_mayor = n;
	}
	else if(n < n_menor){
		n_menor = n;
	}
	
	cout<<"El valor m�s grande fue: "<<n_mayor<<", el valor menor introducido fue: "<<n_menor;
}
