#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

struct NodoColaE{

    NodoColaPtr proximo;
    void* data;

};

struct ColaE{

    NodoColaPtr primero;
    NodoColaPtr ultimo;
    int tam;

};

NodoColaPtr crearNodoCola (ColaPtr cola, void* data){

    NodoColaPtr nuevoNodo = malloc(sizeof(struct NodoColaE));

    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

ColaPtr crearCola(){

    ColaPtr nuevaCola = malloc(sizeof(struct ColaE));

    nuevaCola->primero = NULL;
    nuevaCola->ultimo = NULL;
    nuevaCola->tam = 0;

    return nuevaCola;
}

int getTamanioCola(ColaPtr cola){
    return cola->tam;
}

NodoColaPtr getPrimerNodoCola(ColaPtr cola){
    return cola->primero;
}

NodoColaPtr getUltimoNodoCola(ColaPtr cola){
    return cola->ultimo;
}

NodoColaPtr getSiguienteNodoCola(NodoColaPtr actual){
    return actual->proximo;
}

void* getDatoNodoCola(NodoColaPtr actual){
    return actual->data;
}

int encolar(ColaPtr cola, void* data){

    int tam = getTamanioCola(cola);
    NodoColaPtr nuevoNodo = crearNodoCola(cola, data);

    if(tam == 0){
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tam++;
        return 1;
    } else {
        cola->ultimo->proximo = nuevoNodo;
        cola->ultimo = nuevoNodo;
        cola->tam++;
        return 1;
    }

}

void* desencolar(ColaPtr cola){

    int tam = getTamanioCola(cola);
    if(tam == 1){
        NodoColaPtr nodoEliminar = cola->primero;
        void* dato = getDatoNodoCola(nodoEliminar);
        free(nodoEliminar);
        cola->tam--;
        return dato;
    } else {
        NodoColaPtr nodoEliminar = cola->primero;
        cola->primero = nodoEliminar->proximo;
        void* dato = getDatoNodoCola(nodoEliminar);
        free(nodoEliminar);
        cola->tam--;
        return dato;
    }

}
