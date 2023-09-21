#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct ListaE{

    NodoPtr cabecera;
    NodoPtr ultimo;
    int tamanio;
    int tamDelDatoEnBytes;

};

struct NodoE{

    NodoPtr proximo;
    void* data;

};

NodoPtr crearNodo(ListaPtr lista, void* data){

    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));

    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
}

ListaPtr crearLista(int tamDelDatoEnBytes){

    ListaPtr nuevaLista = malloc(sizeof(struct ListaE));

    nuevaLista->cabecera = NULL;
    nuevaLista->ultimo = NULL;
    nuevaLista->tamanio = 0;
    nuevaLista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return nuevaLista;
}

int estaVacia(ListaPtr lista){
    if(lista->tamanio == 0){
        return TRUE;
    }
    return FALSE;
}

int getTamanioLista(ListaPtr lista){
    return lista->tamanio;
}

void* obtenerPrimerDato(ListaPtr lista){
    return lista->cabecera->data;
}

void* obtenerDato(ListaPtr lista, int pos){
    NodoPtr actual = lista->cabecera;
    int i = 0;
    while(actual != NULL && i < pos){
        actual = actual->proximo;
        i++;
    }
    return actual->data;
}

void* obtenerUltimoDato(ListaPtr lista){
    return lista->ultimo->data;
}

int insertarInicio(ListaPtr lista, void* data){
    NodoPtr nuevoNodo = crearNodo(lista, data);

    if(estaVacia(lista)){
        lista->cabecera = nuevoNodo;
        lista->ultimo = nuevoNodo;
        lista->cabecera->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }else{
        nuevoNodo->proximo = lista->cabecera;
        lista->cabecera = nuevoNodo;
        lista->tamanio++;
        return TRUE;
    }
}

int insertarFinal(ListaPtr lista, void* data){
    NodoPtr nuevoNodo = crearNodo(lista, data);
    if(estaVacia(lista)){
        lista->cabecera = nuevoNodo;
        lista->ultimo = nuevoNodo;
        lista->cabecera->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }else{
        lista->ultimo->proximo = nuevoNodo;
        nuevoNodo->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }
}

int insertar(ListaPtr lista, void* data, int pos){
    NodoPtr nuevoNodo = crearNodo(lista, data);
    if(estaVacia(lista)){
        lista->cabecera = nuevoNodo;
        lista->ultimo = nuevoNodo;
        lista->cabecera->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }else{
        /*
        NodoPtr actual = lista->cabecera;
        int i = 0;
        while(actual != NULL && i < pos){
            actual = actual->proximo;
            i++;
        }
        ///TODO o NO? Nodo anterior en vez de actual
        nuevoNodo->proximo = actual;
        actual = nuevoNodo;
        i++;
        */
        NodoPtr anterior = lista->cabecera;
        int i = 0;
        while(anterior != NULL && i < pos-1){
            anterior = anterior->proximo;
            i++;
        }
        nuevoNodo->proximo = anterior->proximo;
        anterior->proximo = nuevoNodo;
        lista->tamanio++;
        return TRUE;
    }
}

void* remover(ListaPtr lista, void* backup, int pos){
    if(pos == 0){
        NodoPtr nodoDestruir = lista->cabecera;
        lista->cabecera = nodoDestruir->proximo;
        void* dataRetorno = nodoDestruir->data;
        free(nodoDestruir);
        lista->tamanio--;
        return dataRetorno;
    }else{
        ///TODO o NO? Nodo anterior en vez de actual
        NodoPtr actual = lista->cabecera;
        int i = 0;
        while(actual != NULL && actual < pos){
            actual = actual->proximo;
            i++;
        }
        NodoPtr nodoDestruir = actual;
        actual = nodoDestruir->proximo;
        void* dataRetorno = nodoDestruir->data;
        free(nodoDestruir);
        lista->tamanio--;
        return dataRetorno;
    }
}

NodoPtr getPrimerNodo(ListaPtr listaActual){
    return listaActual->cabecera;
}

NodoPtr getSiguienteNodo(NodoPtr nodoActual){
    return nodoActual->proximo;
}

void* getDatoNodo(NodoPtr nodoActual){
    return nodoActual->data;
}

void setDatoEnLista(ListaPtr listaActual, void* dato, int pos){
    if(getTamanioLista(listaActual) == 1){
        return listaActual->cabecera->data;
    } else {
        NodoPtr actual = listaActual->cabecera;
        for(int i = 0; i < pos; i++){
            actual = actual->proximo;
        }
        actual = actual->proximo;

        return actual->data = dato;
    }
}
