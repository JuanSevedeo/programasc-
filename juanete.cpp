#include <iostream>
#include <thread>
#include <chrono>
#include <string>

enum class Plan {
    REGULAR,
    DELICADO,
    SUPER_DELICADO,
    NO_SELECCIONADO
};

class Lavadora {
public:
    Lavadora() : plan_(Plan::NO_SELECCIONADO) {}

    void seleccionarModo() {
        int opcion = 0;
        std::cout << "\nSeleccione el modo de lavado:\n";
        std::cout << "1. Regular\n";
        std::cout << "2. Delicado\n";
        std::cout << "3. Súper Delicado\n";
        std::cout << "Ingrese el número de su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                plan_ = Plan::REGULAR;
                break;
            case 2:
                plan_ = Plan::DELICADO;
                break;
            case 3:
                plan_ = Plan::SUPER_DELICADO;
                break;
            default:
                std::cout << "Opción no válida. Seleccionando modo Regular por defecto.\n";
                plan_ = Plan::REGULAR;
                break;
        }
        std::cout << "Modo seleccionado: " << obtenerNombrePlan() << "\n";
    }

    void iniciar() {
        if (plan_ == Plan::NO_SELECCIONADO) {
            std::cout << "Seleccione un modo de lavado antes de iniciar.\n";
            return;
        }

        std::cout << "\nIniciando ciclo de lavado: " << obtenerNombrePlan() << "\n";
        remojo();
        enjuague();
        drenado();
        secado();
        std::cout << "Ciclo de lavado completado.\n";
    }

private:
    Plan plan_;

    std::string obtenerNombrePlan() {
        switch (plan_) {
            case Plan::REGULAR: return "Regular";
            case Plan::DELICADO: return "Delicado";
            case Plan::SUPER_DELICADO: return "Súper Delicado";
            default: return "No Seleccionado";
        }
    }

    void remojo() {
        std::cout << "Etapa: Remojo\n";
        encenderLuz("Remojo");
        activarBombaEntrada();
        esperarMinutos(30);
        apagarLuz("Remojo");
    }

    void enjuague() {
        std::cout << "Etapa: Enjuague\n";
        encenderLuz("Enjuague");
        agitar();
        esperarMinutos(30);
        if (plan_ == Plan::SUPER_DELICADO) {
            esperarMinutos(5);
        }
        apagarLuz("Enjuague");
    }

    void drenado() {
        std::cout << "Etapa: Drenado\n";
        encenderLuz("Drenado");
        activarBombaSalida();
        esperarMinutos(5);
        apagarLuz("Drenado");
    }

    void secado() {
        if (plan_ != Plan::SUPER_DELICADO) {
            std::cout << "Etapa: Secado\n";
            encenderLuz("Secado");
            agitar();
            apagarLuz("Secado");
        } else {
            std::cout << "Secado omitido para el plan Súper Delicado.\n";
        }
    }

    void encenderLuz(const std::string& etapa) {
        std::cout << "Luz encendida: " << etapa << "\n";
    }

    void apagarLuz(const std::string& etapa) {
        std::cout << "Luz apagada: " << etapa << "\n";
    }

    void activarBombaEntrada() {
        std::cout << "Bomba de entrada activada.\n";
    }

    void activarBombaSalida() {
        std::cout << "Bomba de salida activada.\n";
    }

    void agitar() {
        std::cout << "Agitación en proceso.\n";
    }

    void esperarMinutos(int minutos) {
        std::cout << "Esperando " << minutos << " minutos...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simula el tiempo
    }
};

int main() {
    Lavadora lavadora;
    int opcion = 0;

    do {
        std::cout << "\n=== MENÚ LAVADORA ===\n";
        std::cout << "1. Seleccionar modo de lavado\n";
        std::cout << "2. Iniciar lavado\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                lavadora.seleccionarModo();
                break;
            case 2:
                lavadora.iniciar();
                break;
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
