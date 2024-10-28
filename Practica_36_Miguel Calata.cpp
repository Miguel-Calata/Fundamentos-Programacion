/*Miguel Salvador Calata Rodríguez
Práctica 36  -  Decimal a Binario */

#include <iostream>
#include <string>
using namespace std;

main(){
    int num, resp;
    string bin;
    do {
        cout << "Favor de introducir un numero: ";
        cin >> num;
        do {
            if (num % 2 == 0) {
                bin = "0" + bin;
            } else {
                bin = "1" + bin;
            }
            num = num / 2;

        } while (num >= 1);

        cout << bin <<endl<<"Quieres continuar? 1-Si  0-NO: \n";
        bin = "";
        cin >> resp;

    }while(resp > 0);
}
