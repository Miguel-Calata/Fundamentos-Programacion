/* Miguel Salvador Calata Rodríguez
Práctica 4 Algoritmo de intercambio de variables
01/02/2024 */
#include <iostream>

using namespace std;

main (){
	int A, B, C;
	
	cout<<"Favor de introducir el valor de A: "; cin>>A;
	cout<<"Favor de introducir el valor de B: "; cin>>B;
	
	C=A;
	A=B;
	B=C;
	
	cout<<"El valor de A es: "<<A<<"\nEl valor de B es: "<<B;
	
	
}
