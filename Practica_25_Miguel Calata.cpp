/* Miguel Salvador Calata Rodr�guez
Pr�ctica 25 - Men� de figuras con funci�n switch */
#include <iostream>
#include <math.h>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	float h, r, b;
	int ope;
	
	cout<<"Seleccione que operaci�n va a realizar:"<<endl<<"1) ---> �rea del tri�ngulo "<<endl<<"2) ---> �rea del circulo"
	<<endl<<"3) ---> Vol�men de una esfera"<<endl<<"4) ---> Vol�men de un cilindro"<<endl; 
	
	cout<<endl<<"Acci�n a realizar: "; cin>>ope;
	
	switch(ope){
		case 1:
			cout<<"Favor de introducir la base: "; cin>>b;
			cout<<"Favor de introducir la altura: "; cin>>h;
			cout<<"El �rea del triagulo es: "<<(b*h)/2;
		break;
		case 2:
			cout<<"Favor de introducir el radio: "; cin>>r;
		
			cout<<"El �rea del circulo es: "<<M_PI*pow(r,2);
		break;	
		case 3:
			cout<<"Favor de introducir el radio: "; cin>>r;
		
			cout<<"El vol�men de la esfera es: "<< (4 * M_PI * pow(r,3))/3;
		break;	
		case 4:
			cout<<"Favor de introducir el radio: "; cin>>r;
			cout<<"Favor de introducir la altura: "; cin>>h;
			cout<<"El vol�men de la esfera es: "<<h* M_PI*pow(r,2);
		break;
		default:
			cout<<"Favor de introducir una operaci�n v�lida";
	}
}
