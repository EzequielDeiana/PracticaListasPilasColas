#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "inmueble.h"

struct InmuebleE{

    float valor;
    int anio;
    char direccion[20];
    char duenio[20];

};

InmueblePtr crearInmueble(float valor, int anio, char direccion[20], char duenio[20]){
    InmueblePtr nuevoInmueble = malloc(sizeof(struct InmuebleE));

    nuevoInmueble->valor = valor;
    nuevoInmueble->anio = anio;
    strcpy(nuevoInmueble->duenio, duenio);
    strcpy(nuevoInmueble->direccion, direccion);

    return nuevoInmueble;
}

float getValorInmueble(InmueblePtr inmueble){
    return inmueble->valor;
}

int getAnioInmueble(InmueblePtr inmueble){
    return inmueble->anio;
}

char* getDireccionInmueble(InmueblePtr inmueble){
    return inmueble->direccion;
}

char* getDuenioInmueble(InmueblePtr inmueble){
    return inmueble->duenio;
}

void mostrarInmueble(InmueblePtr inmueble){
    printf("\n------DIRECCION: %s\n", getDireccionInmueble(inmueble));
    printf("------DUENIO: %s\n", getDuenioInmueble(inmueble));
    printf("------ANIO: %d\n", getAnioInmueble(inmueble));
    printf("------VALOR: $%.2f\n", getValorInmueble(inmueble));
}

void mostrarListaInmueble(ListaPtr listaInmuebles){
    NodoPtr nodoActual = getPrimerNodo(listaInmuebles);

    while(nodoActual != NULL){
        mostrarInmueble((InmueblePtr)getDatoNodo(nodoActual));
        nodoActual = getSiguienteNodo(nodoActual);
    }
}
ListaPtr comprobarCantidadInmuebles(ListaPtr listaActual){

    if(obtenerTamanio(listaActual) >= 5){

        ListaPtr listaDuplicada = crearLista(200);

        printf("PASO CREAR\n");
        system("pause");

        listaDuplicada = duplicarLista(listaActual);

        printf("PASO DUPLICAR\n");
        system("pause");

        ordenarListaInmuebles(listaDuplicada);

        printf("PASO ORDENAR\n");
        system("pause");

        mostrarListaInmueble(listaDuplicada);

        printf("PASO MOSTRAR\n");
        system("pause");

        return listaDuplicada;

    }
}

ListaPtr ordenarListaInmuebles(ListaPtr listaInmuebles){
    int intercambiado = 0;
    do
    {
        intercambiado = 0;
        for(int j = 0; j < obtenerTamanio(listaInmuebles)-1 ; j++){
            ListaPtr inmueble1 = (ListaPtr)obtenerDato(listaInmuebles,j);
            ListaPtr inmueble2 = (ListaPtr)obtenerDato(listaInmuebles,j+1);
            if(strcmp(getDuenioInmueble(inmueble1), getDuenioInmueble(inmueble2)) > 0){
                ListaPtr inmueble3 = remover(listaInmuebles, j, inmueble3);
                insertar(listaInmuebles, inmueble3, j+1);
                intercambiado = 1;
            }
        }
    }while(intercambiado == 1);
    return listaInmuebles;

}
