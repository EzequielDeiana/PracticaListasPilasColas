#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

#include "miembro.h"
#include "banda.h"

struct Banda{
    char nombre[20];
    Lista listaMiembros;
};

BandaPtr crearBanda(char nombre[20]){

    BandaPtr b = (BandaPtr)malloc(sizeof(struct Banda));

    strcpy(b->nombre,nombre);

    b->listaMiembros = crearLista(sizeof(Lista));

    return b;
}

void mostrarBanda(BandaPtr b){

    printf("\n\n----------BANDA----------\n");
    printf("NOMBRE: %s\n",b->nombre);
    mostrarMiembros(getListaBanda(b));

}

char* getNombreBanda(BandaPtr b){
    return b->nombre;
}

void setNombreBanda(BandaPtr b, char nombre[20]){
    strcpy(b->nombre, nombre);
}

void destruir(BandaPtr b){
    free(b);
}

void mostrarMiembros(Lista lista){

    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        mostrarMiembro(*(MiembroPtr*)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }
}

Lista getListaBanda(BandaPtr b){
    return b->listaMiembros;
}

Lista copiarListaBanda(Lista lista){

    Lista listaCopia = crearLista(sizeof(Lista));

    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        MiembroPtr aux = (MiembroPtr)getDatoNodo(actual);
        insertarFinal(listaCopia,aux);
        actual = getSiguienteNodo(actual);
    }

    return listaCopia;
}

void ordenarListaBanda(BandaPtr b){

    int tam = obtenerTamanio(getListaBanda(b));
    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam -1; i++){
        nodo_i = getPrimerNodo(getListaBanda(b));
        nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            MiembroPtr miembro1 = *(MiembroPtr*)getDatoNodo(nodo_i);
            MiembroPtr miembro2 = *(MiembroPtr*)getDatoNodo(nodo_j);

            if(getAntiguedad(miembro1) > getAntiguedad(miembro2)){
                void* aux = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i, getDatoNodo(nodo_j));
                setDatoNodo(nodo_j, aux);
            }
        nodo_i = getSiguienteNodo(nodo_i);
        nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

void buscarMiembro(BandaPtr b){

    Nodo actual = getPrimerNodo(getListaBanda(b));

    while(actual != NULL){
        MiembroPtr aux = *(MiembroPtr*)getDatoNodo(actual);
        if(strcmp(getInstrumento(aux), "Guitarra") == 0){
            mostrarMiembro(aux);
        }
        actual = getSiguienteNodo(actual);
    }

}
