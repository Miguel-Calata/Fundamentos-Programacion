/*Miguel Salvador Calata Rodr�guez 29/02/2024
Pr�ctica  27 - Signo zodiacal */
#include<iostream>
using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int dia, mes;
	
	cout<<"Favor de introducir tu d�a de nacimiento : "; cin>>dia;
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
				}
			break;
			case 5:
				if(dia>0 && dia<=20){
					cout<<"Tu signo sodicacal es Tauro";
				}
				else if(dia>21 && dia<=31){
					cout<<"Tu signo sodiacal es G�minis";
				}
				else{
					cout<<"D�a no v�lido";
				}
			break;
			case 6:
				if(dia>0 && dia<=20){
					cout<<"Tu signo sodicacal es G�minis";
				}
				else if(dia>20 && dia<=30){
					cout<<"Tu signo sodiacal es C�ncer";
				}
				else{
					cout<<"D�a no v�lido";
				}
			break;
			case 7:
				if(dia>0 && dia<=22){
					cout<<"Tu signo sodicacal es C�ncer";
				}
				else if(dia>22 && dia<=31){
					cout<<"Tu signo sodiacal es Leo";
				}
				else{
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
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
					cout<<"D�a no v�lido";
				}
		}
	}
	else{
		cout<<"Favor de introducir una mes v�lido";
	}

}
