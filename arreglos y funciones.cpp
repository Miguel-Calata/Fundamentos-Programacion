//
// Created by Migue on 25/04/2024.
//

#include "iostream"

using namespace std;

void cap(int [], int);
void mues(int [], int);

main(){
    int alumno[3], prof[5];
    cap(alumno, 3);
    mues(alumno, 5);
}

void cap(int arr[], int size){
    for (int i = 0; i < size; ++i) {
        cout <<"Dame arreglo en pos" << i+1 << ": ";
        cin >> arr[i];
    }
}

void mues(int arr[], int size){
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ", "
    }
}