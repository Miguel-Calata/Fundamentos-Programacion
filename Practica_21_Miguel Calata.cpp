/*Miguel Salvador Calata Rodríguez
22/02/2024 - Práctica 21 - Ordenamiento de números*/
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int A, B, C, mayor, menor, medio;
	
	cout<<"Favor de ingresar el valor de A: "; cin>>A; 
	mayor = A;
	menor = A;
	cout<<"Favor de ingresar el valor de B: "; cin>>B; 
	if(B>= mayor){
		mayor = B;
	}
	else if(B<= menor){
		menor = B;
	}
	cout<<"Favor de ingresar el valor de C: "; cin>>C; 
		if(C>= mayor){
		mayor = C;
	}
	else if(C<= menor){
		menor = C;
	}

	cout<<"Los numeros capturados fueron A:"<<A<<"  B:"<<B<<"  C:"<<C<<endl;
	
	medio = A + B + C - menor - mayor;
	
	A = menor;
	B = medio;
	C = mayor;
	
	cout<<"Los valores han sido reordenados"<<"\nA:"<<A<<"\nB:"<<B<<"\nC:"<<C;

}
