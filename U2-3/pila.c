#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

struct NodoE{

    NodoPtr proximo;
    void* data;

};

struct PilaE{

    NodoPtr cabecera;
    int tamanio;

};

NodoPtr crearNodo(PilaPtr pila, void* data){

    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));

    nuevoNodo->proximo = NULL;
    nuevoNodo->data = data;

    return nuevoNodo;
}

PilaPtr crearPila(){

    PilaPtr nuevaPila = malloc(sizeof(struct PilaE));

    nuevaPila->cabecera = NULL;
    nuevaPila->tamanio = 0;

    return nuevaPila;
}


NodoPtr getCabecera(PilaPtr pila){

    return pila->cabecera;

}

void apilar(PilaPtr pila, void* data){

    NodoPtr nuevoNodo = crearNodo(pila,data);

    if(estaVacia(pila)){
        pila->cabecera = nuevoNodo;
        nuevoNodo->proximo = NULL;
        pila->tamanio++;
    } else {

        nuevoNodo->proximo = pila->cabecera;
        pila->cabecera = nuevoNodo;
        pila->tamanio++;
    }
}

void* desapilar(PilaPtr pila){

    NodoPtr nodoEliminar = pila->cabecera;

    pila->cabecera = pila->cabecera->proximo;

    void* dataDesapilada = nodoEliminar->data;

    free(nodoEliminar);

    pila->tamanio--;

    return dataDesapilada;
}


int estaVacia(PilaPtr pila){

    if(pila->tamanio==0){
        return TRUE;
    }
    return FALSE;
}

void destruirPila(PilaPtr pila){

    while(pila->cabecera != NULL){
        desapilar(pila);
    }
    free(pila);
    pila = NULL;
}
