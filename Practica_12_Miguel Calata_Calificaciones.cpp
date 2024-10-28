/* Miguel Salvador Calata Rodríguez

Práctíca 12 - Solo con IF - Captura de calificaciones y redondeo a 100*/

#include <iostream>

using namespace std;

main(){
	int cal_1, cal_2, cal_3, prom;
	
	cout<<"Introduzca la primera calificacion: "; cin>>cal_1;
	cout<<"Introduzca la segunda calificacion: "; cin>>cal_2;
	cout<<"Introduzca la tercera calificacion: "; cin>>cal_3;
	
	prom = (cal_1 + cal_2 + cal_3)/3;
	
	if(prom>=95){
		prom = 100;
	}
	
	cout<<"Su promedio es: "<<prom;
}
