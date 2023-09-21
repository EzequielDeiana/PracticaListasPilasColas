#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

struct NodoE{

    NodoPtr proximo;
    void* data;

};

struct ColaE{

    NodoPtr cabecera;
    NodoPtr ultimo;
    int tamanio;

};

NodoPtr crearNodo(ColaPtr cola, void* data){

    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));

    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

ColaPtr crearCola(){

    ColaPtr nuevaCola = malloc(sizeof(struct ColaE));

    nuevaCola->cabecera = NULL;
    nuevaCola->ultimo = NULL;
    nuevaCola->tamanio = 0;

    return nuevaCola;
}

int estaVacia(ColaPtr cola){

    if(cola->tamanio == 0){
        return TRUE;
    }
    return FALSE;
}

int getTamanio(ColaPtr cola){
    return cola->tamanio;
}

void encolar(ColaPtr cola, void* data){

    NodoPtr nuevoNodo = crearNodo(cola, data);

    if(estaVacia(cola) == TRUE){
        cola->cabecera = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tamanio++;
    } else {
        cola->ultimo->proximo = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tamanio++;
    }
}

void* desencolar(ColaPtr cola){

    NodoPtr nodoEliminar = cola->cabecera;
    cola->cabecera = nodoEliminar->proximo;
    void* dato = nodoEliminar->data;
    free(nodoEliminar);
    cola->tamanio--;
    return dato;
}

NodoPtr getNodoCabecera(ColaPtr cola){
    return cola->cabecera;
}

NodoPtr getNodoUltimo(ColaPtr cola){
    return cola->ultimo;
}

void* getDato(NodoPtr nodo){

    return nodo->data;

}
