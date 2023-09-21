#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct NodoE{

    void* data;
    NodoPtr prox;

};

struct ListaE{

    NodoPtr cabecera;
    NodoPtr ultimo;
    int tam;
    int tamDelDatoEnBytes;

};


NodoPtr crearNodo(ListaPtr lista, void* data){
    NodoPtr nuevoNodo = malloc(sizeof(struct NodoE));

    nuevoNodo->data = data;
    nuevoNodo->prox = NULL;

    return nuevoNodo;

}

ListaPtr crearLista(int tamDelDatoEnBytes){
    ListaPtr nuevaLista = malloc(sizeof(struct ListaE));

    nuevaLista->cabecera = nuevaLista->ultimo = NULL;
    nuevaLista->tam = 0;
    nuevaLista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return nuevaLista;
}

int estaVacia(ListaPtr lista){

    if(lista->tam == 0){
        return TRUE;
    }
    return FALSE;
}

int obtenerTamanio(ListaPtr lista){

    return lista->tam;

}

void* obtenerPrimerDato(ListaPtr lista){

    return lista->cabecera->data;

}

void* obtenerUltimoDato(ListaPtr lista){

    return lista->ultimo->data;

}

void* obtenerDato(ListaPtr lista, int pos){

    if(estaVacia(lista)){
        return obtenerPrimerDato(lista);
    }
    NodoPtr actual = lista->cabecera;
    for(int i = 0; i < pos-1; i++){
        actual = actual->prox;
    }
    actual->data = actual->prox->data;

    return actual->data;

}

int insertarInicio(ListaPtr lista, void *data){

    NodoPtr aux = crearNodo(lista, data);

    if(estaVacia(lista)){
        lista->cabecera = aux;
        lista->ultimo = aux;
        lista->cabecera->prox = NULL;
        lista->tam++;
        return TRUE;
    }

    aux->prox = lista->cabecera;
    lista->cabecera = aux;
    lista->tam++;

    return TRUE;
}

int insertarFinal(ListaPtr lista, void *data){

    NodoPtr aux = crearNodo(lista, data);

    if(estaVacia(lista)){
        lista->cabecera = aux;
        lista->ultimo = aux;
        lista->cabecera->prox = NULL;
        lista->tam++;
        return TRUE;
    }

    lista->ultimo->prox = aux;
    aux->prox = NULL;
    lista->tam++;

    return TRUE;
}

int insertar(ListaPtr lista, void *data, int pos){

    NodoPtr aux = crearNodo(lista, data);

    if(estaVacia(lista)){
        lista->cabecera = aux;
        lista->ultimo = aux;
        lista->cabecera->prox = NULL;
        lista->tam++;
        return TRUE;
    }
    NodoPtr anterior = lista->cabecera;
    int i = 0;
    while(anterior != NULL && i < pos-1){
        anterior = anterior->prox;
        i++;
    }
    aux->prox = anterior->prox;
    anterior->prox = aux;
    lista->tam++;

    return TRUE;
}

int removerInicio(ListaPtr lista, void *backup){

    if(estaVacia(lista)){
        return FALSE;
    } else if(lista->tam == 1){
        memcpy(backup,lista->cabecera->data, lista->tamDelDatoEnBytes);
        //Liberar Lista
        return TRUE;
    }

    NodoPtr proximoCpy = lista->cabecera->prox;
    memcpy(backup, lista->cabecera->data, lista->tamDelDatoEnBytes);

    free(lista->cabecera->data);
    free(lista->cabecera);
    lista->cabecera = proximoCpy;
    lista->tam--;

    return TRUE;
}

int removerFinal(ListaPtr lista, void *backup){
    if (!lista)
        return FALSE;

    // Se a lista tiver apenas 1 elemento
    if (lista->tam == 1) {
        memcpy(backup, lista->cabecera->data, lista->tamDelDatoEnBytes);
        //liberarlista(lista);
    }
    // A lista possui mais de um elemento
    else {
        NodoPtr f = NULL, ultimo = NULL;
        memcpy(backup, lista->ultimo->data, lista->tamDelDatoEnBytes);

        // Percorre a lista até encontrar o penúltimo elemento da lista
        for (f = lista->cabecera; f != lista->ultimo; f = f->prox)
            ultimo = f;

        // Nesse momento 'ultimo' aponta para o penúltimo elemeto da lista

        free(lista->ultimo->data); // Remove o dado do último elemento
        free(lista->ultimo); // Remove o último elemento
        lista->ultimo = ultimo; // Agora o último elemento se torna 'ultimo'
        lista->ultimo->prox = NULL; // Portanto ultimo->proximo deve ser NULL
        lista->tam--;
    }
    return TRUE;
}

void* remover (ListaPtr lista, int pos, void *backup) {
    if(pos == 0)
    {
        NodoPtr nodoDestruir = lista->cabecera;
        lista->cabecera = nodoDestruir->prox;
        void* data = nodoDestruir->data;
        free(nodoDestruir);
        lista->tam--;
        return data;
    }
    else
    {
        NodoPtr nodoAnterior = lista->cabecera;
        int i = 0;
        while(nodoAnterior != NULL && i < pos-1)
        {
            nodoAnterior = nodoAnterior->prox;
            i++;
        }
        NodoPtr nodoDestruir = nodoAnterior->prox;
        nodoAnterior->prox = nodoDestruir->prox;
        void* dato = nodoDestruir->data;
        free(nodoDestruir);
        lista->tam--;
        return dato;
    }
}

void liberarlista (ListaPtr lista) {
    NodoPtr nodoActual = lista->cabecera;
    while(nodoActual != NULL)
    {
        NodoPtr nodoTemporal = nodoActual;
        nodoActual = nodoActual->prox;
        free(nodoTemporal);
    }
    free(lista);
    lista = NULL;
}

NodoPtr getPrimerNodo(ListaPtr listaActual){
    return listaActual->cabecera;
}

NodoPtr getSiguienteNodo(NodoPtr nodoActual){
    return nodoActual->prox;
}

void* getDatoNodo(NodoPtr nodoActual){
    return nodoActual->data;
}

void setNodoSiguiente(NodoPtr nodoActual, NodoPtr nodoSiguiente){
    nodoActual->prox = nodoSiguiente;
}

