#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main() {
    string texto;
    stack<char> lifo;
    string estadoActual = "S1";
    map<string, map<char, string>> transiciones = {
        {"S1", {{'a', "S2"}}},
        {"S2", {{'a', "S2"}, {'c', "S4"}, {'b', "S1"}}},
        {"S3", {{'b', "S4"}, {'a', "S1"}}},
        {"S4", {{'d', "S3"}, {'a', "S5"}}}
    };

    cout << "Ingresa el texto: ";
    cin >> texto;

    // Agregar caracteres al stack
    for (char c : texto) {
        lifo.push(c);
    }

    // Procesar el texto
    while (!lifo.empty()) {
        char simbolo = lifo.top();
        lifo.pop();

        if (transiciones[estadoActual].count(simbolo)) {
            string estadoSiguiente = transiciones[estadoActual][simbolo];
            cout << simbolo << " avanzó a: " << estadoSiguiente << endl;
            estadoActual = estadoSiguiente;
        } else {
            cout << simbolo << " no puede avanzar." << endl;
            cout << "El texto se queda en: " << estadoActual << endl;
            break;
        }
    }

    return 0;
}
