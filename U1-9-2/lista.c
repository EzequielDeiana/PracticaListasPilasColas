#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "alumno.h"

struct NodoE{

    void* data;
    NodoPtr proximo;

};

struct ListaE{

    NodoPtr cabecera;
    NodoPtr ultimo;
    int tamanio;
    int tamDelDatoEnBytes;

};

NodoPtr crearNodo(ListaPtr lista, void* data){

    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));


    nuevoNodo->data = data;
    nuevoNodo->proximo = NULL;

    return nuevoNodo;
};

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

int obtenerTamanio(ListaPtr lista){

    return lista->tamanio;

}

NodoPtr getPrimerNodo(ListaPtr listaActual){
    NodoPtr nodo = listaActual->cabecera;
    return nodo;
}

NodoPtr getSiguienteNodo(NodoPtr nodoActual){
    NodoPtr nodo = nodoActual->proximo;
    return nodo;
}

void* getDatoNodo(NodoPtr nodoActual){

    return nodoActual->data;

}

void* obtenerPrimerDato(ListaPtr lista){
    return lista->cabecera->data;
}

void* obtenerDato (ListaPtr lista, int pos) {
    NodoPtr nodoActual = lista->cabecera;
    int i = 0;
    while(nodoActual != NULL && i != pos)
    {
        nodoActual = nodoActual->proximo;
        i++;
    }
    return nodoActual->data;
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
    } else{
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
    } else{
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
    } else{
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

int removerInicio(ListaPtr lista, void* backup){

    if(estaVacia(lista)){
        return FALSE;
    } else if(obtenerTamanio(lista) == 1){
        memcpy(backup, lista->cabecera->data, lista->tamDelDatoEnBytes);
        ///TODO : LIBERAR LISTA
        return TRUE;
    }

    NodoPtr proximoCpy = lista->cabecera->proximo;
    memcpy(backup, lista->cabecera->data, lista->tamDelDatoEnBytes);

    free(lista->cabecera->data);
    free(lista->cabecera);
    lista->cabecera = proximoCpy;
    lista->tamanio--;

    return TRUE;
}

int removerFinal(ListaPtr lista, void* backup){

    if(estaVacia(lista)){
        return FALSE;
    } else if(obtenerTamanio(lista) == 1){
        memcpy(backup, lista->cabecera->data, lista->tamDelDatoEnBytes);
        ///TODO : LIBERAR LISTA
        return TRUE;
    } else {
        NodoPtr f = NULL, ultimo = NULL;
        memcpy(backup, lista->ultimo->data, lista->tamDelDatoEnBytes);

        for(f = lista->cabecera; f != lista->ultimo; f = f->proximo){
            ultimo = f;
        }

        free(lista->ultimo->data);
        free(lista->ultimo);
        lista->ultimo = ultimo;
        lista->ultimo->proximo = NULL;
        lista->tamanio--;
    }
    return TRUE;
}

void* remover (ListaPtr lista, int pos, void* backup){

    if(pos == 0){
        NodoPtr nodoDestruir = lista->cabecera;
        lista->cabecera = nodoDestruir->proximo;
        void* dataRetorno = nodoDestruir->data;
        free(nodoDestruir);
        lista->tamanio--;
        return dataRetorno;
    } else {
        NodoPtr nodoAnterior = lista->cabecera;
        int i = 0;
        while(nodoAnterior != NULL && i < pos-1){
            nodoAnterior = nodoAnterior->proximo;
            i++;
        }
        NodoPtr nodoDestruir = nodoAnterior->proximo;
        nodoAnterior->proximo = nodoDestruir->proximo;
        void* dataRetorno = nodoDestruir->data;
        free(nodoDestruir);
        lista->tamanio--;
        return dataRetorno;
    }

}

void liberarLista(ListaPtr lista){

    NodoPtr nodoActual = lista->cabecera;
    while(nodoActual != NULL){
        NodoPtr nodoTemporal = nodoActual;
        nodoActual = nodoActual->proximo;
        free(nodoTemporal);
    }
    free(lista);
    lista = NULL;
}


ListaPtr duplicarLista(ListaPtr lista){

    ListaPtr nuevaLista = crearLista(lista->tamDelDatoEnBytes);

    NodoPtr actual = getPrimerNodo(nuevaLista);
    NodoPtr aux = getPrimerNodo(lista);
    for(int i = 0; i < obtenerTamanio(lista); i++){
        actual = aux;
        insertar(nuevaLista,getDatoNodo(actual),i);
        actual = getSiguienteNodo(actual);
        aux = getSiguienteNodo(aux);
    }

    return nuevaLista;
}

void setDatoEnLista(ListaPtr listaActual, void* dato, int pos){
    if(obtenerTamanio(listaActual) == 1){
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
