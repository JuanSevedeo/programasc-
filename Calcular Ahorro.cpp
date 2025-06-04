#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nombreArchivo = "archivo.txt";
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        cout << "Archivo '" << nombreArchivo << "' abierto correctamente.\nContenido:\n";
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
        cout << "Archivo '" << nombreArchivo << "' cerrado correctamente." << endl;
    } else {
        cerr << "Error: No se pudo abrir el archivo '" << nombreArchivo << "'" << endl;
    }

    return 0;
}
