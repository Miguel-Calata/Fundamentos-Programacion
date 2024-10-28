//
// Created by Miguel on 14/03/2024.
//

#include <iostream>
using namespace std;

float convert (float ent, float conv){
    return ent * conv;
}

int main (){
    float entrada;
    int resp;
    cout<<"Favor de darme una entrada en metros";
    cin>>entrada;
    cout<<"A que valor le gustaria convertir?\n";
    cout<<"1)Millas\n2)Yardas\n"; cin>>resp;

    switch (resp) {
        case 1:
            cout<<convert(entrada, 0.000621);
        break;
        case 2:
            cout<<convert(entrada, 1.09361);
        break;
    default:
        cout<<"Algo salio mal";
    }
}