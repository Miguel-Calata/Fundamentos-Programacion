/* Miguel Salvador Calata Rodr�guez

Pr�ct�ca 13 - Captura de n�mero par o impar*/

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
