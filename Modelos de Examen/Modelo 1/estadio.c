#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include "asistentes.h"
#include "estadio.h"


struct Estadio{

    char nombreEstadio[20];
    int capacidad;
    Lista asistentesEstadio;

};

EstadioPtr crearEstadio(char nombreEstadio[20],int capacidad){

    EstadioPtr e = (EstadioPtr)malloc(sizeof(struct Estadio));

    strcpy(e->nombreEstadio, nombreEstadio);
    e->capacidad = capacidad;
    e->asistentesEstadio = crearLista(sizeof(Lista));

    return e;
}

void mostrarEstadio(EstadioPtr e){

    printf("\n\n----------ESTADIO----------\n");
    printf("NOMBRE: %s\n",e->nombreEstadio);
    printf("CAPACIDAD: %d\n",e->capacidad);
    mostrarListaAsistentes(getListaEstadio(e));
}

char *getNombreEstadio(EstadioPtr e){
    return e->nombreEstadio;
}

int getCapacidadEstadio(EstadioPtr e){
    return e->capacidad;
}

void setNombreEstadio(EstadioPtr e, char nuevo[20]){
    strcpy(e->nombreEstadio, nuevo);
}

void setCapacidadEstadio(EstadioPtr e, int nuevaCapacidad){
    e->capacidad = nuevaCapacidad;
}

void destruirEstadio(EstadioPtr e){
    free(e);
}

void mostrarListaAsistentes(Lista lista){

    Nodo actual = getPrimerNodo(lista);
    while(actual != NULL){
        mostrarAsistente(*(AsistentePtr*)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }
}

Lista copiaListaAsistentes(EstadioPtr e){

    Lista listaCopia = (Lista)crearLista(sizeof(Lista));

    Nodo actual = getPrimerNodo(getListaEstadio(e));

    while(actual != NULL){
        insertarFinal(listaCopia,(AsistentePtr)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }

    return listaCopia;
}

void ordenarLista(EstadioPtr e){

    Lista lista = getListaEstadio(e);

    Nodo nodo_i, nodo_j;

    int tam = obtenerTamanio(lista);
    for(int i = 0; i < tam -1; i++){
    nodo_i = getPrimerNodo(lista);
    nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            AsistentePtr asistente1 = *(AsistentePtr*)getDatoNodo(nodo_i);
            AsistentePtr asistente2 = *(AsistentePtr*)getDatoNodo(nodo_j);
            if(strcmp(getApellidoAsistente(asistente1),getApellidoAsistente(asistente2)) > 0){
                void* aux = getDatoNodo(nodo_i);
                setDatoEnNodo(nodo_i, getDatoNodo(nodo_j));
                setDatoEnNodo(nodo_j, aux);
            }
            nodo_i = getSiguienteNodo(nodo_i);
            nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

void mostrarSocios(EstadioPtr e, char clave[20]){

    Nodo actual = getPrimerNodo(getListaEstadio(e));

    while(actual != NULL){
        char condicionAsistente[20];
        strcpy(condicionAsistente, getCondicionAsistente(*(AsistentePtr*)getDatoNodo(actual)));

        if(strcmp(condicionAsistente, clave) == 0){
            mostrarAsistente(*(AsistentePtr*)getDatoNodo(actual));
        }

        actual = getSiguienteNodo(actual);
    }

}

Lista getListaEstadio(EstadioPtr e){
    return e->asistentesEstadio;
}
