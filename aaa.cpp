//Arbol genealogico.
#include <iostream>
#include <string>
using namespace std;

//Estructura "persona" 
struct Persona {
    string nombre;
    Persona* izquierda;
    Persona* derecha

    Persona(string nom) {
        nombre = nom;
        izquierda = NULL;
        derecha = NULL;
    }};


        }
        return nodo;
    }

    // Recorrido inorden
    void inorden(Persona* nodo) {
        if (nodo) {
            inorden(nodo->izquierda);
            cout << nodo->nombre << " ";
            inorden(nodo->derecha);
        }
    }

    // Recorrido preorden
    void preorden(Persona* nodo) {
        if (nodo) {
            cout << nodo->nombre << " ";
            preorden(nodo->izquierda);
            preorden(nodo->derecha);
        }
    }

    // Recorrido postorden
    void postorden(Persona* nodo) {
        if (nodo) {
            postorden(nodo->izquierda);
            postorden(nodo->derecha);
            cout << nodo->nombre << " ";
        }
    }

    // Buscar un miembro en el árbol
    bool pertenece(Persona* nodo, string nombre) {
        if (nodo == NULL) return false;
        if (nodo->nombre == nombre) return true;
        return (nombre < nodo->nombre) ? pertenece(nodo->izquierda, nombre)
                                       : pertenece(nodo->derecha, nombre);
    }
public:
