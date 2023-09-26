#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "disco.h"
#include "cancion.h"

struct Disco{

    char nombre[20];
    int precio;
    Lista canciones;

};

DiscoPtr crearDisco(char nombre[20], int precio){

    DiscoPtr d = (DiscoPtr)malloc(sizeof(struct Disco));

    strcpy(d->nombre,nombre);
    d->precio = precio;
    d->canciones = crearLista(sizeof(Lista));

    return d;
}

void mostrarDisco(DiscoPtr d){
    printf("\n\t--------DISCO--------\n");
    printf("\tNOMBRE: %s\n",d->nombre);
    printf("\tPRECIO: $%d\n",d->precio);
    mostrarCanciones(getListaDisco(d));
}

char* getNombreDisco(DiscoPtr d){
    return d->nombre;
}

int getPrecioDisco(DiscoPtr d){
    return d->precio;
}

void setNombreDisco(DiscoPtr d, char nombre[20]){
    strcpy(d->nombre, nombre);
}

void setPrecioDisco(DiscoPtr d, int precio){
    d->precio = precio;
}

void destruirDisco(DiscoPtr d){
    free(d);
}

void mostrarCanciones(Lista lista){
    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        mostrarCancion(*(CancionPtr*)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }

}

Lista getListaDisco(DiscoPtr d){
    return d->canciones;
}

Lista copiarListaDisco(DiscoPtr d){

    Lista copiaLista = crearLista(sizeof(Lista));
    Nodo actual = getPrimerNodo(getListaDisco(d));

    while(actual != NULL){
        CancionPtr aux = *(CancionPtr*)getDatoNodo(actual);
        insertarFinal(copiaLista, &aux);
        actual = getSiguienteNodo(actual);
    }
    return copiaLista;
}

void ordenarLista(DiscoPtr d){
    int tam = obtenerTamanio(getListaDisco(d));
    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam -1; i++){
        nodo_i = getPrimerNodo(getListaDisco(d));
        nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            CancionPtr cancion1 = *(CancionPtr*)getDatoNodo(nodo_i);
            CancionPtr cancion2 = *(CancionPtr*)getDatoNodo(nodo_j);

            if(getDuracionCancion(cancion1) > getDuracionCancion(cancion2)){
                void* aux = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i,getDatoNodo(nodo_j));
                setDatoNodo(nodo_j,aux);
            }
        nodo_i = getSiguienteNodo(nodo_i);
        nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

void buscarMiembro(DiscoPtr d){

    Nodo actual = getPrimerNodo(getListaDisco(d));

    while(actual != NULL){
        CancionPtr aux = *(CancionPtr*)getDatoNodo(actual);
        if(strcmp(getBandaCancion(aux),"Raise A Suilen") == 0){
            mostrarCancion(aux);
        }

        actual = getSiguienteNodo(actual);
    }

}
