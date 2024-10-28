/* Miguel Salvador Calata Rodríguez
Práctica en laboratorio calcular la calificación de los alumnos
01/02/2024 */

#include <iostream>

using namespace std;

main (){
	int tar1, tar2, tar3, tar4, tar5, prac1, prac2, prac3, ex1, ex2, proy;
	int val_tar, val_prac, val_ex, val_proy;
	float por_tar, por_prac, por_ex, por_proy;
	float calificacion;
	
	cout<<"Digite la calificacion de la primera tarea: "; cin>>tar1;
	cout<<"Digite la calificacion de la segunda tarea: "; cin>>tar2;
	cout<<"Digite la calificacion de la tercera tarea: "; cin>>tar3;
	cout<<"Digite la calificacion de la cuarta tarea: "; cin>>tar4;
	cout<<"Digite la calificacion de la quinta tarea: "; cin>>tar5;
	
	cout<<"Muchas gracias, ahora digite la calificacion de la primera practica: "; cin>>prac1;
	cout<<"Ahora digite la calificacion de la primera practica: "; cin>>prac2;
	cout<<"Ahora digite la calificacion de la primera practica: "; cin>>prac3;
	
	cout<<"Muchas gracias, ahora digite la calificacion del primer examen: "; cin>>ex1;
	cout<<"Ahora digite la calificacion del segundo  examen: "; cin>>ex2;
	
	cout<<"Por ultimo digite la calificacion del proyexto: "; cin>>proy;
	
	
	val_tar = tar1+tar2+tar3+tar4+tar5;
	val_prac = prac1+prac2+prac3;
	val_ex = ex1+ex2;
	val_proy = proy;
	
	por_tar = (val_tar*0.25)/5;
	por_prac = (val_prac*0.35)/3;
	por_ex =(val_ex*0.20)/2;
	por_proy = (val_proy*0.20)/1;
	
	calificacion = por_tar + por_prac + por_ex + por_proy;
	
	cout<<" la calificación final es: "<<calificacion;
}
