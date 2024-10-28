#include <iostream>
using namespace std;

main(){
    int f= 1, cont;
    int a[3] = {0,0,0};
    for(cont = 1; cont <= 3; cont++ ){
        a[cont] +=f;
        f = a[cont];
    }
    cout << f;
}
