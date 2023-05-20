#include <iostream>
#include <stdlib.h>

using namespace std;

struct corredor {
    int numero;
    string nombre;
    int vueltas;
    corredor* sig;
};

corredor* cab = NULL;
corredor* aux = NULL;
corredor* aux2 = NULL;

void registrar() {
    aux = new corredor;
    aux->sig = NULL;
    cout << "Proporcione el nombre del corredor: ";
    cin >> aux->nombre;
    cout << "Proporcione el número del corredor: ";
    cin >> aux->numero;
    cout << "Proporcione la cantidad de vueltas realizadas por el corredor: ";
    cin >> aux->vueltas;

    if (aux->vueltas >= 2) {
        if (cab == NULL) {
            cab = aux;
        } else {
            aux2 = cab;
            while (aux2->sig != NULL) {
                aux2 = aux2->sig;
            }
            aux2->sig = aux;
        }
    } else {
        delete aux;
        cout << "El corredor no ha realizado al menos dos vueltas. No se registra." << endl;
    }
}

void mostrar() {
    cout << "Lista de corredores registrados con dos o más vueltas:" << endl;
    aux = cab;
    bool corredoresEncontrados = false; // Variable para verificar si se encontraron corredores con 2 o más vueltas

    while (aux != NULL) {
        if (aux->vueltas >= 2) {
            cout << "Número: " << aux->numero << " - Nombre: " << aux->nombre << " - Vueltas: " << aux->vueltas << endl;
            corredoresEncontrados = true;
        }
        aux = aux->sig;
    }

    if (!corredoresEncontrados) {
        cout << "No se encontraron corredores con dos o más vueltas registradas." << endl;
    }
}

int main() {
    int opcion = 0;
    do {
        cout << endl << "1. Registrar corredor" << endl;
        cout << "2. Mostrar corredores" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

    // Liberar la memoria de los corredores registrados
    aux = cab;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }

    return 0;
}