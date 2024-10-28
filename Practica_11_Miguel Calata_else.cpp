/* Miguel Salvador Calata Rodríguez
Práctica  cuota del congreso con if y else
06/02/2024 */

#include <iostream>

using namespace std;

main (){
	int est, precio_con, precio_ins;

	cout<<"Es estudiante? escriba 1 para si 0 para no: "; cin>>est;
	
	if(est==1){
		precio_con = 100;
		precio_ins = 50;
	}
	else{
		precio_con = 200;
		precio_ins = 100;
	}
	cout<<"Precio de inscripcion: "<<precio_ins;
	cout<<"\nPrecio del congreso es: "<<precio_con;
}
