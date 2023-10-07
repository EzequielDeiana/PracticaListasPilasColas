#include "pila.h"
#include <stdlib.h>
#include <string.h>

struct NodoPila{

    NodoPilaPtr proximo;
    void* dato;

};

struct Pila{

    NodoPilaPtr primero;
    int tam;

};

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data){

    NodoPilaPtr nuevoNodo = malloc(sizeof(struct NodoPila));
    nuevoNodo->dato = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

PilaPtr crearPila(){

    PilaPtr nuevaPila = malloc(sizeof(struct Pila));

    nuevaPila->primero = NULL;
    nuevaPila->tam = 0;

    return nuevaPila;
}

NodoPilaPtr getPrimerNodoPila(PilaPtr pila){
    return pila->primero;
}

NodoPilaPtr getSiguienteNodoPila(NodoPilaPtr actual){
    return actual->proximo;
}

void* getDatoNodoPila(NodoPilaPtr actual){
    actual->dato;
}

int apilar(PilaPtr pila, void* data){

    NodoPilaPtr nuevoNodo = crearNodoPila(pila, data);
    nuevoNodo->proximo = pila->primero;
    pila->primero = nuevoNodo;
    pila->tam++;
    return 1;
}

void* desapilar(PilaPtr pila){

    NodoPilaPtr nodoEliminar = pila->primero;

    pila->primero = nodoEliminar->proximo;

    void* retorno = nodoEliminar->dato;

    free(nodoEliminar);

    pila->tam--;

    return retorno;
}

int getTamanioPila(PilaPtr pila){
    return pila->tam;
}
