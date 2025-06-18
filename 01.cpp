// Arbol Genealogico 
#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    Persona* izquierda;
    Persona* derecha;

    Persona(string nom) {
        nombre = nom;
        izquierda = NULL;
        derecha = NULL;
    }
};

class ArbolGenealogico {
private:
    Persona* raiz;

    // Funcion auxiliar para insertar un miembro
    Persona* insertar(Persona* nodo, string nombre) {
        if (nodo == NULL) {
            return new Persona(nombre);
        }
        if (nombre < nodo->nombre) {
            nodo->izquierda = insertar(nodo->izquierda, nombre);
        } else if (nombre > nodo->nombre) {
            nodo->derecha = insertar(nodo->derecha, nombre);
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
    ArbolGenealogico() {
        raiz = NULL;
    }

    // Funcion publica para agregar un miembro
    void agregarMiembro(string nombre) {
        raiz = insertar(raiz, nombre);
    }

    // Funcion publica para verificar si un miembro pertenece
    bool pertenece(string nombre) {
        return pertenece(raiz, nombre);
    }

    // Mostrar arbol en inorden
    void mostrarInorden() {
        cout << "Recorrido Inorden (por orden alfabetico): ";
        inorden(raiz);
        cout << endl;
    }

    // Mostrar arbol en preorden
    void mostrarPreorden() {
        cout << "Recorrido Preorden (raiz-izquierda-derecha): ";
        preorden(raiz);
        cout << endl;
    }

    // Mostrar arbol en postorden
    void mostrarPostorden() {
        cout << "Recorrido Postorden (izquierda-derecha-raiz): ";
        postorden(raiz);
        cout << endl;
    }
};

int main() {
    ArbolGenealogico arbol;

    // Insertar miembros al arbol genealogico
    arbol.agregarMiembro("Guillermo");
    arbol.agregarMiembro("Angel");
    arbol.agregarMiembro("Dayana");
    arbol.agregarMiembro("Carlos");
    arbol.agregarMiembro("Jose");

    // Mostrar los recorridos del arbol
    arbol.mostrarInorden();
    arbol.mostrarPreorden();
    arbol.mostrarPostorden();

    // Verificar si un miembro pertenece al arbol
    cout << "\n¿Guillermo pertenece al arbol? " << (arbol.pertenece("Guillermo") ? "Si" : "No") << endl;
    cout << "¿Dayana pertenece al arbol? " << (arbol.pertenece("Dayana") ? "Si" : "No") << endl;

    return 0;
}
