#include <iostream>
using namespace std;

const float PI = 3.1416;

// Función para calcular el área de un círculo
float calcularArea(float radio) {
    return PI * (radio * radio);
}

// Función para calcular el perímetro de un círculo
float calcularPerimetro(float radio) {
    return 2 * PI * radio;
}

int main() {
    float radio;
    char opcion;

    cout << "Ingresa el radio del círculo: ";
    cin >> radio;

    while (true) {
        cout << endl << "Selecciona qué deseas calcular: " << endl;
        cout << "(A) Área" << endl;
        cout << "(P) Perímetro" << endl;
        cout << "(S) Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 'a':
            case 'A':
                cout << "El área del círculo es: " << calcularArea(radio) << endl;
                break;
            case 'p':
            case 'P':
                cout << "El perímetro del círculo es: " << calcularPerimetro(radio) << endl;
                break;
            case 's':
            case 'S':
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción inválida. Por favor, selecciona una opción válida." << endl;
        }
    }

    return 0;
}
