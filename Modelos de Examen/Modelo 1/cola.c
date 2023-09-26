#include "cola.h"
#include <stdlib.h>
#include <string.h>

struct NodoCola{

    NodoColaPtr proximo;
    void* data;

};

struct Cola{

    NodoColaPtr primero;
    NodoColaPtr ultimo;
    int tam;

};

NodoColaPtr crearNodoCola(ColaPtr cola, void* dato){

    NodoColaPtr nuevo = malloc(sizeof(struct NodoCola));

    nuevo->data = dato;
    nuevo->proximo = NULL;

    return nuevo;
}

ColaPtr crearCola(){

    ColaPtr nuevaCola = malloc(sizeof(struct Cola));

    nuevaCola->primero = NULL;
    nuevaCola->ultimo = NULL;
    nuevaCola->tam = 0;

    return nuevaCola;
}

int encolar(ColaPtr cola, void* dato){
    NodoColaPtr nuevoNodo = crearNodoCola(cola, dato);
    if(cola->tam == 0){
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tam++;
        return 1;
    }else{
        cola->ultimo->proximo = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tam++;
        return 1;
    }
}

void* desencolar(ColaPtr cola){
    NodoColaPtr nodoEliminar = cola->primero;
    void* dato = getDatoNodoCola(nodoEliminar);
    cola->primero = nodoEliminar->proximo;
    free(nodoEliminar);
    cola->tam--;
    return dato;
}

void* getDatoNodoCola(NodoColaPtr nodo){
    return nodo->data;
}
