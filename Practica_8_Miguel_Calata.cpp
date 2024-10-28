/* Miguel Salvador Calata Rodríguez
Práctica 8 convertir unidades
01/02/2024 */
#include <iostream>

using namespace std;

main(){
	const float eq_yard = 1.09361, eq_mill = 0.000621371, eq_pie = 3.28084;
	float mt;
	float mt_yard, mt_mill, mt_pie;
	
	cout<<"Introduzca la cantidad en metros: "; cin>>mt;
	
	mt_yard = mt*eq_yard;
	mt_mill = mt*eq_mill;
	mt_pie = mt*eq_pie;
	
	cout<<"La equivalencia en yardas de "<<mt<<" es igual a:"<<mt_yard;
	cout<<"\nLa equivalencia en millas es:"<<mt_mill;
	cout<<"\nLa equivalencia en pies es:"<<mt_pie;
	
	
}
