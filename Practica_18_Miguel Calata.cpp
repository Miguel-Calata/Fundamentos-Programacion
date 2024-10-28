/* Miguel Salvador Calata Rodríguez
Práctica 18 - Datos numéricos */
#include <iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int num, par, m7;
	
	cout<<"Favor de introducir un número cualquiera: "; cin>>num;
	
	par = num % 2;
	m7 = num % 7;
	
	if (num == 0){
		cout<<num<<" ---> Es positivo"<<endl;
		cout<<num<<" ---> Es par"<<endl;
	}
	else if(num > 0 ){
		
		cout<<num<<" ---> Es positivo"<<endl;
		if(par == 0){
			cout<<num<<" ---> Es par"<<endl;
		}
		else{
			cout<<num<<" ---> Es impar"<<endl;
		}
		if(par != 0){
			if(m7 == 0){
				cout<<num<<" ---> Es multiplo de 7"<<endl;	
			}
			else{
				cout<<num<<" ---> NO es multiplo de 7"<<endl;	
			}
		}
	}
	else if(num < 0){
		
		cout<<num<<" ---> Es Negativo"<<endl;
		if(par != 0){
			if(m7 == 0){
				cout<<num<<" ---> Es multiplo de 7"<<endl;	
			}
			else{
				cout<<num<<" ---> NO es multiplo de 7"<<endl;	
			}
		}
	}
}
