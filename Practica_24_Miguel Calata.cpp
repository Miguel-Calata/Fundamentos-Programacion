/* Miguel Salvador Calata Rodríguez
Práctica 24 - Calculadora con el uso de switch */
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int n1, n2;
	char ope;
	cout<<"Favor de introducir el primer valor: "; cin>>n1;
	cout<<"Favor de introducir el segundo valor: "; cin>>n2;
	
	cout<<"Seleccione que operación va a realizar:"<<endl<<"S ---> Suma"<<endl<<"R ---> Resta"
	<<endl<<"D ---> División"<<endl<<"M ---> Multiplicación"<<endl; 
	
	cout<<endl<<"Operación: "; cin>>ope;
	
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
			cout<<"Favor de introducir una operación válida";
	}
}
