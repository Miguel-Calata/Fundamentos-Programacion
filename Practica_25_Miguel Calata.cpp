/* Miguel Salvador Calata Rodríguez
Práctica 25 - Menú de figuras con función switch */
#include <iostream>
#include <math.h>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	float h, r, b;
	int ope;
	
	cout<<"Seleccione que operación va a realizar:"<<endl<<"1) ---> Área del triángulo "<<endl<<"2) ---> Área del circulo"
	<<endl<<"3) ---> Volúmen de una esfera"<<endl<<"4) ---> Volúmen de un cilindro"<<endl; 
	
	cout<<endl<<"Acción a realizar: "; cin>>ope;
	
	switch(ope){
		case 1:
			cout<<"Favor de introducir la base: "; cin>>b;
			cout<<"Favor de introducir la altura: "; cin>>h;
			cout<<"El área del triagulo es: "<<(b*h)/2;
		break;
		case 2:
			cout<<"Favor de introducir el radio: "; cin>>r;
		
			cout<<"El área del circulo es: "<<M_PI*pow(r,2);
		break;	
		case 3:
			cout<<"Favor de introducir el radio: "; cin>>r;
		
			cout<<"El volúmen de la esfera es: "<< (4 * M_PI * pow(r,3))/3;
		break;	
		case 4:
			cout<<"Favor de introducir el radio: "; cin>>r;
			cout<<"Favor de introducir la altura: "; cin>>h;
			cout<<"El volúmen de la esfera es: "<<h* M_PI*pow(r,2);
		break;
		default:
			cout<<"Favor de introducir una operación válida";
	}
}
