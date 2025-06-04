#include <iostream>
#include <string>
using namespace std;

// Clase base Deporte
class Deporte {
protected:
    string nombre;
    string tipoPelota;
    int jugadores;
    int duracion;

public:
    // Constructor
    Deporte(string nombre, string tipoPelota, int jugadores, int duracion)
        : nombre(nombre), tipoPelota(tipoPelota), jugadores(jugadores), duracion(duracion) {}

    // Método para imprimir datos del deporte
    void ImprimirDatos() {
        cout << "Deporte: " << nombre << endl;
        cout << "Tipo de pelota: " << tipoPelota << endl;
        cout << "Cantidad de jugadores: " << jugadores << endl;
        cout << "Duración del juego: " << duracion << " minutos" << endl;
    }

    // Método virtual para imprimir métodos específicos
    virtual void ImprimirMetodosEspecificos() = 0;
};

// Clase Pierna que hereda de Deporte
class Pierna : public Deporte {
public:
    // Constructor
    Pierna(string nombre, string tipoPelota, int jugadores, int duracion)
        : Deporte(nombre, tipoPelota, jugadores, duracion) {}

    // Método para imprimir parte del cuerpo utilizada
    void ParteDelCuerpo() {
        cout << nombre << " se juega principalmente con los pies." << endl;
    }

    // Método para imprimir equipamiento necesario
    void Equipamiento() {
        cout << "Equipamiento necesario: zapatillas deportivas, canilleras." << endl;
    }

    // Método para imprimir superficie de juego
    void Superficie() {
        cout << "Se juega generalmente en superficies como césped artificial o madera." << endl;
    }

    // Implementación del método virtual
    void ImprimirMetodosEspecificos() override {
        ParteDelCuerpo();
        Equipamiento();
        Superficie();
    }
};

// Clase Brazo que hereda de Deporte
class Brazo : public Deporte {
public:
    // Constructor
    Brazo(string nombre, string tipoPelota, int jugadores, int duracion)
        : Deporte(nombre, tipoPelota, jugadores, duracion) {}

    // Método para imprimir parte del cuerpo utilizada
    void ParteDelCuerpo() {
        cout << nombre << " se juega principalmente con los brazos." << endl;
    }

    // Método para imprimir equipamiento necesario
    void Equipamiento() {
        cout << "Equipamiento necesario: rodilleras, camiseta deportiva." << endl;
    }

    // Método para imprimir superficie de juego
    void Superficie() {
        cout << "Se juega comúnmente en canchas de madera o arena." << endl;
    }

    // Implementación del método virtual
    void ImprimirMetodosEspecificos() override {
        ParteDelCuerpo();
        Equipamiento();
        Superficie();
    }
};

int main() {
    // Crear objetos de las clases Pierna y Brazo
    Pierna futbolSala("Fútbol Sala", "Pelota de fútbol tamaño reducido", 5, 40);
    Brazo voleibol("Voleibol", "Balón de voleibol", 6, 60);

    // Imprimir datos y métodos específicos de cada deporte
    futbolSala.ImprimirDatos();
    futbolSala.ImprimirMetodosEspecificos();
    cout << endl;
    voleibol.ImprimirDatos();
    voleibol.ImprimirMetodosEspecificos();

    return 0;
}
