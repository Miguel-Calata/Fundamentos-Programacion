/* Miguel Salvador Calata Rodr�guez
Pr�ctica 24 - Calculadora con el uso de switch */
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int n1, n2;
	char ope;
	cout<<"Favor de introducir el primer valor: "; cin>>n1;
	cout<<"Favor de introducir el segundo valor: "; cin>>n2;
	
	cout<<"Seleccione que operaci�n va a realizar:"<<endl<<"S ---> Suma"<<endl<<"R ---> Resta"
	<<endl<<"D ---> Divisi�n"<<endl<<"M ---> Multiplicaci�n"<<endl; 
	
	cout<<endl<<"Operaci�n: "; cin>>ope;
	
	switch(ope){
		case 'S': case 's':
			cout<<n1<<" + "<< n2 <<" = " <<n2+n1;
		break;
		case 'R': case 'r':
			cout<<n1<<" - "<< n2 <<" = " <<n2-n1;
		break;	
		case 'D': case 'd':
			cout<<n1<<" / "<< n2 <<" = " <<n2/n1;
		break;	
		case 'M': case 'm':
			cout<<n1<<" x "<< n2 <<" = " <<n2*n1;
		break;
		default:
			cout<<"Favor de introducir una operaci�n v�lida";
	}
}
