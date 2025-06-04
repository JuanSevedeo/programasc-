#include <iostream>
#include <string>
using namespace std;

class Circulo {
private:
    const float PI = 3.1416;
    float radio;

public:
    // Constructor
    Circulo(float radio = 0) : radio(radio) {}

    // Getter y Setter para radio
    float getRadio() const {
        return radio;
    }

    void setRadio(float radio) {
        this->radio = radio;
    }

    // Función para calcular el área
    float calcularArea() const {
        return PI * (radio * radio);
    }

    // Función para calcular el perímetro
    float calcularPerimetro() const {
        return 2 * PI * radio;
    }
};

int main() {
    Circulo circulo;
    string opcion;
    float radio;

    cout << "Ingresa el radio del círculo: ";
    cin >> radio;
    circulo.setRadio(radio);

    while (true) {
        cout << endl << "Selecciona qué deseas calcular: " << endl;
        cout << "(A) Área" << endl;
        cout << "(P) Perímetro" << endl;
        cout << "(S) Salir" << endl;
        cin >> opcion;

        if (opcion == "a" || opcion == "A") {
            cout << "El área del círculo es: " << circulo.calcularArea() << endl;
        } else if (opcion == "p" || opcion == "P") {
            cout << "El perímetro del círculo es: " << circulo.calcularPerimetro() << endl;
        } else if (opcion == "s" || opcion == "S") {
            cout << "Saliendo del programa..." << endl;
            break;
        } else {
            cout << "Opción inválida. Por favor, selecciona una opción válida." << endl;
        }
    }

    return 0;
}
