/*Miguel Salvador Calata Rodríguez
22/02/2024 - Práctica 21 - División de la herencia entre cónyuge e hijos*/
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int herencia, hijo;
	char resp;
	
	cout<<"Cuánto es el monto total de la herancia? "; cin>>herencia;
	cout<<"Tine hijos? (s o n) "; cin>>resp;
	
	if(resp == 'S'|| resp == 's'){
		herencia=herencia-(herencia*0.03);
		
		cout<<"Cúantos hijos tiene? "; cin>>hijo;
		
		cout<<"Cada hijo recibirá: "<<(herencia*0.5)/hijo<<endl;
		cout<<"El cónyuge recibirá: "<<herencia*0.5;
	}
	else if(resp == 'N' || resp == 'n' ){
		cout<<"El cónyuge recibirá: "<<herencia-(herencia*0.05);
	}
	
}
