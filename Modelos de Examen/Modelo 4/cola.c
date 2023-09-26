#include <stdio.h>
#include <stdlib.h>

#include "cola.h"
#include "cancion.h"

struct NodoCola{

    NodoColaPtr proximo;
    void* dato;

};

struct Cola{

    NodoColaPtr primero;
    NodoColaPtr ultimo;
    int tamanio;

};

NodoColaPtr crearNodoCola(ColaPtr cola, void* data){

    NodoColaPtr nuevoNodo = malloc(sizeof(struct NodoCola));

    nuevoNodo->dato = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

ColaPtr crearCola(){

    ColaPtr nuevaCola = malloc(sizeof(struct Cola));

    nuevaCola->primero = NULL;
    nuevaCola->ultimo = NULL;
    nuevaCola->tamanio = 0;

    return nuevaCola;
}

int encolar(ColaPtr cola, void* data){
    NodoColaPtr nuevoNodo = crearNodoCola(cola, data);
    if(cola->tamanio == 0){
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tamanio++;
        return 1;
    } else {
        cola->ultimo->proximo = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tamanio++;
        return 1;
    }

}

void* desencolar(ColaPtr cola){
    NodoColaPtr nodoEliminar = cola->primero;

    void* retorno = getDatoNodoCola(nodoEliminar);

    cola->primero = nodoEliminar->proximo;

    free(nodoEliminar);

    cola->tamanio--;

    return retorno;
}

int getTamanioCola(ColaPtr cola){
    return cola->tamanio;
}

void* getDatoNodoCola(NodoColaPtr actual){
    return actual->dato;
}
