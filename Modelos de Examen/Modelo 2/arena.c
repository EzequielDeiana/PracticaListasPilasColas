#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "asistente.h"
#include "arena.h"

struct Arena{

    char nombre[20];
    char direccion[20];
    Lista asistentes;

};

ArenaPtr crearArena(char nombreArena[20], char direccion[20]){

    ArenaPtr a = (ArenaPtr)malloc(sizeof(struct Arena));

    strcpy(a->nombre,nombreArena);
    strcpy(a->direccion,direccion);
    a->asistentes = crearLista(sizeof(Lista));

    return a;
}

void mostrarArena(ArenaPtr a){

    printf("\n\n----------ARENA----------\n");
    printf("NOMBRE: %s\n", a->nombre);
    printf("DIRECCION: %s\n", a->direccion);

    mostrarAsistentes(getListaArena(a));

}

char* getNombreArena(ArenaPtr a){
    return a->nombre;
}

char* getDireccionArena(ArenaPtr a){
    return a->direccion;
}

void setNombreArena(ArenaPtr a, char nuevoNombre[20]){
    strcpy(a->nombre, nuevoNombre);
}

void setDireccioArena(ArenaPtr a, char nuevaDireccion[20]){
    strcpy(a->direccion, nuevaDireccion);
}

void destruirArena(ArenaPtr a){
    free(a);
}

Lista getListaArena(ArenaPtr a){
    return a->asistentes;
}

void mostrarAsistentes(Lista lista){
    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        mostrarAsistente(*(AsistentePtr*)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }

}

Lista copiarLista(Lista lista){
    Lista nuevaLista = crearLista(sizeof(Lista));
    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        insertarFinal(nuevaLista,(AsistentePtr)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }
    return nuevaLista;
}

void ordenarListaAsistentes(ArenaPtr a){

    int tam = obtenerTamanio(getListaArena(a));

    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam -1; i++){
        nodo_i = getPrimerNodo(getListaArena(a));
        nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            AsistentePtr asistente1 = *(AsistentePtr*)getDatoNodo(nodo_i);
            AsistentePtr asistente2 = *(AsistentePtr*)getDatoNodo(nodo_j);

            if(getPrecio(asistente1) > getPrecio(asistente2)){
                void* aux = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i,getDatoNodo(nodo_j));
                setDatoNodo(nodo_j, aux);
            }
            nodo_i = getSiguienteNodo(nodo_i);
            nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

void buscarAsistentes(ArenaPtr a){

    Nodo actual = getPrimerNodo(getListaArena(a));
    while(actual != NULL){
            AsistentePtr aux = *(AsistentePtr*)getDatoNodo(actual);
        if(getPrecio(aux) > 10000){
            mostrarAsistente(aux);
        }
    actual = getSiguienteNodo(actual);
    }
}


