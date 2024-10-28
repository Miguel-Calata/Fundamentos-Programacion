/*Miguel Salvador Calata Rodríguez 29/02/2024
Práctica  26 - Convertidor de medidas */
#include<iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int resp2, resp3;
	float unidad;
	char resp1;	
	
	cout<<"¿Qué quieres convertir?"<<endl<<"L)--->longitud \nP)--->peso"<<endl; cin>>resp1;
	
	switch(resp1){
		case 'P':
		case 'p':
			cout<<"¿Cuál es la unidad inicial a convertir? \n1)Gramos \n2)Libras \n3)Onzas \n4)Piedras"<<endl;
			cout<<"Inserte respuesta: "; cin>>resp2;
			cout<<"Favor inserte la cantidad a convertir: "; cin>>unidad;
			switch(resp2){
				case 1:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Libras \n2)Onzas \n3)Piedras"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Gramos en Libras = "<<unidad*0.002205;
						break;
						case 2:
							cout<<unidad<<" Gramos en Onzas = "<<unidad*0.03527;
						break;
						case 3:
							cout<<unidad<<" Gramos en Libras = "<<unidad*0.0001575;
					break;
					}
				break;
				case 2:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Gramos \n2)Onzas \n3)Piedras"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Libras en Gramos = "<<unidad*453.592;
						break;
						case 2:
							cout<<unidad<<" Libras en Onzas = "<<unidad*16;
						break;
						case 3:
							cout<<unidad<<" Libras en piedras = "<<unidad*0.07143;
					break;
					}
				break;
				case 3:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Gramos \n2)Libras \n3)Piedras"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Onzas en Gramos = "<<unidad*28.3495;
						break;
						case 2:
							cout<<unidad<<" Onzas en Libras = "<<unidad*0.0625;
						break;
						case 3:
							cout<<unidad<<" Onzas en Piedras = "<<unidad*0.004464;
					break;
					}
				break;
				case 4:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Gramos \n2)Libras \n3)Onzas"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Piedras en Gramos = "<<unidad*6350.29;
						break;
						case 2:
							cout<<unidad<<" Piedras en Libras = "<<unidad*14;
						break;
						case 3:
							cout<<unidad<<" Piedras en Onzas = "<<unidad*224;
					}
			}	
		break;
		case 'l':
		case 'L':
			cout<<"¿Cuál es la unidad inicial a convertir? \n1)Milla \n2)Yarda \n3)Pie \n4)Pulgada"<<endl;
			cout<<"Inserte respuesta: "; cin>>resp2;
			cout<<"Favor inserte la cantidad a convertir: "; cin>>unidad;
			switch(resp2){
				case 1:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Yarda \n2)Pie \n3)Pulgada"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Millas en Yardas = "<<unidad*1760;
						break;
						case 2:
							cout<<unidad<<" Millas en Pies = "<<unidad*5280;
						break;
						case 3:
							cout<<unidad<<" Millas en Pulgadas = "<<unidad*63360;
					break;
					}
				break;
				case 2:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Milla \n2)Pie \n3)Pulgada"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Yardas en Millas = "<<unidad*0.0005682;
						break;
						case 2:
							cout<<unidad<<" Yardas en Pies = "<<unidad*3;
						break;
						case 3:
							cout<<unidad<<" Yardas en Pulgadas = "<<unidad*36;
					break;
					}
				break;
				case 3:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Milla \n2)Yarda \n3)Pulgada"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Pies en Millas = "<<unidad*0.0001894;
						break;
						case 2:
							cout<<unidad<<" Pies en Yardas = "<<unidad*0.333344;
						break;
						case 3:
							cout<<unidad<<" Pies en Pulgadas = "<<unidad*12;
					break;
					}
				break;
				case 4:
					cout<<"¿Cuál es la unidad final a convertir? \n1)Milla \n2)Yarda \n3)Pie"<<endl;
					cout<<"Inserte respuesta: "; cin>>resp3;
					switch(resp3){
						case 1:
							cout<<unidad<<" Pulgadas en Millas = "<<unidad*1.578e-5;
						break;
						case 2:
							cout<<unidad<<" Pulgadas en Yardas = "<<unidad*0.02778;
						break;
						case 3:
							cout<<unidad<<" Pulgadas en Pies = "<<unidad*0.08333;
					}
			}	
			
	}	
}
