#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "cliente.h"

struct NodoArbol;

typedef struct NodoArbol* NodoArbolPtr;

NodoArbolPtr crearArbol();

NodoArbolPtr insertarCliente(NodoArbolPtr raiz, ClientePtr cliente);

ClientePtr buscarCliente(NodoArbolPtr raiz, int hora);

void destruirArbol(NodoArbolPtr raiz);

#endif // ARBOL_H_INCLUDED
