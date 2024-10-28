/* Miguel Salvador Calata Rodríguez

Práctíca 13 - Captura de número par o impar*/

#include <iostream>

using namespace std;

main(){
	int numero, resto;
	
	cout<<"Favor de introducir un numero: "; cin>>numero;
	
	resto = numero%2;
	
	if(resto==0){
		cout<<numero<<" es par";
	}
	else{
		cout<<numero<<" es impar";
	}
	
	
}
