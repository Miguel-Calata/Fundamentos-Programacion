/*Miguel Salvador Calata Rodr�guez
22/02/2024 - Pr�ctica 21 - Divisi�n de la herencia entre c�nyuge e hijos*/
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int herencia, hijo;
	char resp;
	
	cout<<"Cu�nto es el monto total de la herancia? "; cin>>herencia;
	cout<<"Tine hijos? (s o n) "; cin>>resp;
	
	if(resp == 'S'|| resp == 's'){
		herencia=herencia-(herencia*0.03);
		
		cout<<"C�antos hijos tiene? "; cin>>hijo;
		
		cout<<"Cada hijo recibir�: "<<(herencia*0.5)/hijo<<endl;
		cout<<"El c�nyuge recibir�: "<<herencia*0.5;
	}
	else if(resp == 'N' || resp == 'n' ){
		cout<<"El c�nyuge recibir�: "<<herencia-(herencia*0.05);
	}
	
}
