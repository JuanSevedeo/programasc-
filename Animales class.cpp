#include <iostream>
#include <string>
using namespace std;

// Clase base Animal
class Animal {
protected:
    string nombre;
    string color;
    int ojos;
    int colas;
    int patas;

public:
    // Constructor
    Animal(string nombre, string color, int ojos, int colas, int patas)
        : nombre(nombre), color(color), ojos(ojos), colas(colas), patas(patas) {}

    // Método para imprimir datos del animal
    void ImprimirDatos() {
        cout << "El " << nombre << " es de color " << color << endl;
        cout << "El " << nombre << " tiene " << ojos << " ojos" << endl;
        cout << "El " << nombre << " tiene " << colas << " cola" << endl;
        cout << "El " << nombre << " tiene " << patas << " patas" << endl;
    }

    // Método virtual para imprimir métodos específicos
    virtual void ImprimirMetodosEspecificos() = 0;
};

// Clase Mamifero que hereda de Animal
class Mamifero : public Animal {
public:
    // Constructor
    Mamifero(string nombre, string color, int ojos, int colas, int patas)
        : Animal(nombre, color, ojos, colas, patas) {}

    // Método para imprimir características de mamífero
    void Crianza() {
        cout << "El " << nombre << " nace de su madre" << endl;
    }

    void AlimentacionCrias() {
        cout << "El " << nombre << " alimenta a sus crías con leche materna" << endl;
    }

    void Pelaje() {
        cout << "El " << nombre << " tiene pelaje" << endl;
    }

    // Implementación del método virtual
    void ImprimirMetodosEspecificos() override {
        Crianza();
        AlimentacionCrias();
        Pelaje();
    }
};

// Clase Oviparo que hereda de Animal
class Oviparo : public Animal {
public:
    // Constructor
    Oviparo(string nombre, string color, int ojos, int colas, int patas)
        : Animal(nombre, color, ojos, colas, patas) {}

    // Método para imprimir características de ovíparo
    void Crianza() {
        cout << "El " << nombre << " nace de un huevo" << endl;
    }

    void AlimentacionCrias() {
        cout << "El " << nombre << " se alimenta por su cuenta al nacer" << endl;
    }

    void Pelaje() {
        cout << "El " << nombre << " no tiene pelaje" << endl;
    }

    // Implementación del método virtual
    void ImprimirMetodosEspecificos() override {
        Crianza();
        AlimentacionCrias();
        Pelaje();
    }
};

int main() {
    // Crear objetos de las clases Mamifero y Oviparo
    Mamifero perro("perro", "Café", 2, 1, 4);
    Oviparo pinguino("pingüino", "Blanco y Negro", 2, 1, 2);

    // Imprimir datos y métodos específicos de cada animal
    perro.ImprimirDatos();
    perro.ImprimirMetodosEspecificos();
    cout << endl;
    pinguino.ImprimirDatos();
    pinguino.ImprimirMetodosEspecificos();

    return 0;
}
