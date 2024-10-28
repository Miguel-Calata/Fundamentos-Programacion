/* Miguel Salvador Calata Rodríguez
Práctica  Cuota del congreso con if
06/02/2024 */

#include <iostream>

using namespace std;

main (){
	int res, precio_ins = 100, precio_con =200;
	cout<<"El precio de inscripción es de $100, el del taller 200 \n";
	cout<< endl << "Los estudianates tienen 50% de descuento"<< endl;
	cout<<"\nEs estudiante? escriba 1 para si 0 para no: "; cin>>res;
	
	if(res==1){
		precio_con =precio_con*0.5;
		precio_ins = precio_ins*0.5;
	}
	cout<<"Precio de inscpripcion: "<< precio_ins;
	cout<<"precio del congreso es: "<< precio_con;
	cout<<"\nSu total es: "<<precio_ins+precio_con;
}

