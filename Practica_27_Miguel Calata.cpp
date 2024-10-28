/*Miguel Salvador Calata Rodríguez 29/02/2024
Práctica  27 - Signo zodiacal */
#include<iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int dia, mes;
	
	cout<<"Favor de introducir tu día de nacimiento : "; cin>>dia;
	cout<<"Favor de introducir tu mes de nacimiento : "; cin>>mes;
	
	if(mes > 0 && mes<=12){
		switch (mes){
			case 1:
				if(dia>0 && dia<=19){
					cout<<"Tu signo sodicacal es Capricornio";
				}
				else if(dia>19 && dia<=31){
					cout<<"Tu signo sodiacal es Acuario";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 2:
				if(dia>0 && dia<=19){
					cout<<"Tu signo sodicacal es Acuario";
				}
				else if(dia>19 && dia<=29){
					cout<<"Tu signo sodiacal es Piscis";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 3:
				if(dia>0 && dia<=20){
					cout<<"Tu signo sodicacal es Piscis";
				}
				else if(dia>19 && dia<=30){
					cout<<"Tu signo sodiacal es Aries";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 4:
				if(dia>0 && dia<=19){
					cout<<"Tu signo sodicacal es Capricornio";
				}
				else if(dia>20 && dia<=30){
					cout<<"Tu signo sodiacal es Tauro";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 5:
				if(dia>0 && dia<=20){
					cout<<"Tu signo sodicacal es Tauro";
				}
				else if(dia>21 && dia<=31){
					cout<<"Tu signo sodiacal es Géminis";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 6:
				if(dia>0 && dia<=20){
					cout<<"Tu signo sodicacal es Géminis";
				}
				else if(dia>20 && dia<=30){
					cout<<"Tu signo sodiacal es Cáncer";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 7:
				if(dia>0 && dia<=22){
					cout<<"Tu signo sodicacal es Cáncer";
				}
				else if(dia>22 && dia<=31){
					cout<<"Tu signo sodiacal es Leo";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 8:
				if(dia>0 && dia<=23){
					cout<<"Tu signo sodicacal es Leo";
				}
				else if(dia>23 && dia<=31){
					cout<<"Tu signo es Virgo";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 9:
				if(dia>0 && dia<=22){
					cout<<"Tu signo sodicacal es Virgo";
				}
				else if(dia>22 && dia<=30){
					cout<<"Tu signo sodiacal es Libra";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 10:
				if(dia>0 && dia<=22){
					cout<<"Tu signo sodicacal es Libra";
				}
				else if(dia>22 && dia<=31){
					cout<<"Tu signo sodiacal es Escorpio";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 11:
				if(dia>0 && dia<=21){
					cout<<"Tu signo sodicacal es Escorpio";
				}
				else if(dia>21 && dia<=30){
					cout<<"Tu signo sodiacal es Sagitario";
				}
				else{
					cout<<"Día no válido";
				}
			break;
			case 12:
				if(dia>0 && dia<=21){
					cout<<"Tu signo sodicacal es Sagitorio";
				}
				else if(dia>21 && dia<=31){
					cout<<"Tu signo es sodiacal es Capricornio";
				}
				else{
					cout<<"Día no válido";
				}
		}
	}
	else{
		cout<<"Favor de introducir una mes válido";
	}

}
