#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int size = 10;
    int arreglo[size];

    cout << "Ingresa los " << size << " datos del arreglo:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arreglo[i];
    }

    // Ordenar el arreglo
    sort(arreglo, arreglo + size);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}
