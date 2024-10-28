/*Miguel Salvador Calata Rodríguez
Práctica 6 
Cambio de cantidad a billetas y monedas */
#include <iostream>

using namespace std;

main(){
    int inicial, resto;
    int mon_10,mon_5,mon_2,mon_1;
    int bill_1000,bill_500,bill_200,bill_100,bill_50,bill_20;

    cout<<"Introduzca la cantidad a desglosar: "; cin>>inicial;

    bill_1000 = inicial/1000;
    resto = inicial%1000;

    bill_500 = resto/500;
    resto = resto%500;

    bill_200 = resto/200;
    resto = resto%200;

    bill_100 = resto/100;
    resto = resto%100;

    bill_50 = resto/50;
    resto = resto%50;

    bill_20 = resto/20;
    resto = resto%20;

    mon_10 = resto/10;
    resto = resto%10;

    mon_5 = resto/5;
    resto = resto%5;

    mon_2 = resto/2;
    resto = resto%2;

    mon_1 = resto/1;

    cout<<bill_1000<<" Billetes de $1000\n";
    cout<<bill_500<<" Billetes de $500\n";
    cout<<bill_200<<" Billetes de $200\n";
    cout<<bill_100<<" Billetes de $100\n";
    cout<<bill_50<<" Billetes de $50\n";
    cout<<bill_20<<" Billetes de $20\n";
    cout<<mon_10<<" Monedas de $10\n";
    cout<<mon_5<<" Monedas de $5\n";
    cout<<mon_2<<" Monedas de $2\n";
    cout<<mon_1<<" Monedas de $1";

}

