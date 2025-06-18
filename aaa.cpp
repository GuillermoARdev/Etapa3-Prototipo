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
    
public:
