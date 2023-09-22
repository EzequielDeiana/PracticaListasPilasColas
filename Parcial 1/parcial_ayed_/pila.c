#include <stdlib.h>
#include <string.h>
#include "pila.h"

struct NodoPilaE{

    NodoPilaPtr proximo;
    void* data;

};

struct PilaE{

    NodoPilaPtr cabecera;
    int tamanio;

};

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data){

    NodoPilaPtr nuevoNodo = malloc(sizeof(struct NodoPilaE));

    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

PilaPtr crearPila(){

    PilaPtr nuevaPila = malloc(sizeof(struct PilaE));

    nuevaPila->cabecera = NULL;
    nuevaPila->tamanio = 0;

    return nuevaPila;
}

int apilar(PilaPtr pila, void* data){

        NodoPilaPtr nuevoNodo = crearNodoPila(pila, data);

        nuevoNodo->proximo = pila->cabecera;

        pila->cabecera = nuevoNodo;


        return TRUE;

}

void* desapilar(PilaPtr pila){


    NodoPilaPtr nodoEliminar = pila->cabecera;

    pila->cabecera = nodoEliminar->proximo;

    void* dataRetorno = nodoEliminar->data;

    free(nodoEliminar);


    return dataRetorno;
}

int getTamanioPila(PilaPtr pila){

    return pila->tamanio;

}
