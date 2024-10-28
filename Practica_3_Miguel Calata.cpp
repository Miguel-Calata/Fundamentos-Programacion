/* Miguel Salvador Calata Rodríguez
Práctica en laboratorio calcular el area y volumen de un cono
30/01/2024 */

#include <iostream>
#include <cmath>

using namespace std;

main (){
    float A, V;
    float h, r, g;

    cout<<"introduce la altura del cono: "; cin>>h;
    cout<<"introduce el radio de la base del cono: "; cin>>r;


    g= sqrt (h*h + r*r);

    A = M_PI*r*(r+g);
    V = (M_PI*pow(r,2)*h)/3;

    cout<<"El area del cono es: "<<A<<endl<<"El volumen del cono es: "<<V;
}
