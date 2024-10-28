/* Miguel Salvador Calata Rodríguez
Práctica 16 - Hoario Militar*/
#include <iostream>
using namespace std;

main(){
	int hora;
	
	cout<<"Favor de introducir una hora en horario Militar (formato 24h): "; cin>>hora;
	
	if(hora<=23 && hora>=0){
		
		if(hora>= 1 && hora < 12){
			cout<<"La hora en formato militar es: "<<hora<<"hrs"<<endl;
			cout<<"La hora en formato 12h es: "<<hora<<" a. m.";
		}	
		else if(hora > 12 ){
			cout<<"La hora en formato militar es: "<<hora<<"hrs"<<endl;
			cout<<"La hora en formato 12h es: "<<hora-12<<" p. m.";
		}
		else if(hora == 12){
			cout<<"La hora en formato militar es: "<<hora<<"hrs"<<endl;
			cout<<"La hora en formato 12h es: "<<hora<<" p. m.";
		}
		else{
			cout<<"La hora en formato militar es: "<<"00 hrs"<<endl;
			cout<<"La hora en formato 12h es: "<<12<<" a. m.";
		}
	}
	else{
		cout<<"La hora dada es invalida, recuerde que es de las 00hrs - 23hrs.";
	}
}
