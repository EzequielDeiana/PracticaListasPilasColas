#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

struct NodoArbol {
    ClientePtr data;
    struct NodoArbol* izq;
    struct NodoArbol* der;
};

NodoArbolPtr crearArbol() {
    return NULL;
}

NodoArbolPtr insertarCliente(NodoArbolPtr raiz, ClientePtr cliente) {
    if (raiz == NULL) {
        NodoArbolPtr nuevoNodo = (NodoArbolPtr)malloc(sizeof(struct NodoArbol));
        nuevoNodo->data = cliente;
        nuevoNodo->izq = nuevoNodo->der = NULL;
        return nuevoNodo;
    }
    if (getHora(cliente) < getHora(raiz->data)) {
        raiz->izq = insertarCliente(raiz->izq, cliente);
    } else if (getHora(cliente) > getHora(raiz->data)) {
        raiz->der = insertarCliente(raiz->der, cliente);
    }
    return raiz;
}

ClientePtr buscarCliente(NodoArbolPtr raiz, int hora) {
    if (raiz == NULL || getHora(raiz->data) == hora) {
        return raiz->data;
    }
    if (hora < getHora(raiz->data)) {
        return buscarCliente(raiz->izq, hora);
    }
    return buscarCliente(raiz->der, hora);
}

void destruirArbol(NodoArbolPtr raiz) {
    if (raiz != NULL) {
        destruirArbol(raiz->izq);
        destruirArbol(raiz->der);
        free(raiz);
    }
}
