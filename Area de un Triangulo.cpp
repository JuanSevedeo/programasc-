#include <iostream>
using namespace std;

int main() {
    float base, altura, area;
    char opcion = 'y'; // Inicializar la variable opcion

    while (opcion == 'y' || opcion == 'Y') {
        cout << "Ingresa la base del triangulo: ";
        cin >> base;

        // Validar entrada para base
        while (base <= 0) {
            cout << "La base debe ser un número positivo. Ingresa la base del triangulo: ";
            cin >> base;
        }

        cout << "Ingresa la altura del triangulo: ";
        cin >> altura;

        // Validar entrada para altura
        while (altura <= 0) {
            cout << "La altura debe ser un número positivo. Ingresa la altura del triangulo: ";
            cin >> altura;
        }

        area = (base * altura) / 2.2.0f; // Asegurar cálculo en punto flotante

        cout << "El área del triangulo es: " << area << endl;

        cout << "¿Quieres volver a calcular el área de un triangulo? (y/n): ";
        cin >> opcion;

        // Validar entrada para opcion
        while (opcion != 'y' && opcion != 'Y' && opcion != 'n' && opcion != 'N') {
            cout << "Opción inválida. Por favor, ingresa 'y' para sí o 'n' para no: ";
            cin >> opcion;
        }
    }

    return 0;
}
