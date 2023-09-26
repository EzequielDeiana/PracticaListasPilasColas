#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

struct NodoPila{

    NodoPilaPtr proximo;
    void* data;

};

struct Pila{

    NodoPilaPtr primero;
    int tamanio;

};

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data){

    NodoPilaPtr nuevoNodo = malloc(sizeof(struct NodoPila));

    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

PilaPtr crearPila(){

    PilaPtr nuevaPila = malloc(sizeof(struct Pila));

    nuevaPila->primero = NULL;
    nuevaPila->tamanio = 0;

    return nuevaPila;
}

int apilar(PilaPtr pila, void* data){

    NodoPilaPtr nuevoNodo = crearNodoPila(pila, data);

    nuevoNodo->proximo = pila->primero;

    pila->primero = nuevoNodo;

    return 1;
}

void* desapilar(PilaPtr pila){

    NodoPilaPtr nodoEliminar = pila->primero;

    pila->primero = pila->primero->proximo;

    void* dato = nodoEliminar->data;

    free(nodoEliminar);

    pila->tamanio--;

    return dato;

}

int getTamanioPila(PilaPtr pila){
    return pila->tamanio;
}
