#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

struct NodoE{

    NodoPtr proximo;
    void* data;

};

struct PilaE{

    NodoPtr cabecera;


};
NodoPtr crearNodo(PilaPtr pila, void* dato){

    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));

    nuevoNodo->data = dato;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

PilaPtr crearPila(){

    PilaPtr nuevaPila = malloc(sizeof(struct PilaE));

    nuevaPila->cabecera = NULL;

    return nuevaPila;
}

NodoPtr getCabecera(PilaPtr pila){
    return pila->cabecera;
}

void apilar(PilaPtr pila, void* dato){
    NodoPtr nuevoNodo = crearNodo(pila,dato);
    nuevoNodo->proximo = pila->cabecera;
    pila->cabecera = nuevoNodo;
}

void* desapilar(PilaPtr pila)
    {
    if(pila->cabecera == NULL){
        return NULL;
    }
    else
    {
        NodoPtr nodoDesapilar = pila->cabecera;
        pila->cabecera = nodoDesapilar->proximo;
        void* dato = nodoDesapilar->data;
        free(nodoDesapilar);
        return dato;
    }
}

void destruirPila(PilaPtr pila){
    while(pila->cabecera != NULL){
        desapilar(pila);
    }
    free(pila);
    pila = NULL;
}

