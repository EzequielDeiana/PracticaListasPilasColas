#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipo.h"
#include "jugador.h"
#include "lista.h"

struct JugadorE{

    char nombre[20];
    char apellido[20];
    int edad;
    ListaPtr titulosPersonales;

};


JugadorPtr crearJugador(char nombre[20], char apellido[20], int edad,  ListaPtr titulosPersonales){

    JugadorPtr nuevoJugador = malloc(sizeof(struct JugadorE));

    nuevoJugador->edad = edad;
    strcpy(nuevoJugador->nombre, nombre);
    strcpy(nuevoJugador->apellido, apellido);
    nuevoJugador->titulosPersonales = titulosPersonales;

    return nuevoJugador;
}

void agregarTitulo(JugadorPtr jugador, char titulo[50]){
    insertar(getListaTitulos(jugador),titulo,0);

}

void mostrarTitulosJugador(ListaPtr listaTitulos){
    NodoPtr nodoActual;
    nodoActual = getPrimerNodo(listaTitulos);
    printf("------Titulos: \n");
    while(nodoActual != NULL){
        printf("%s\n", (char*)getDatoNodo(nodoActual));
        nodoActual = getSiguienteNodo(nodoActual);
    }

}

char* getNombreJugador(JugadorPtr jugador){
    return jugador->nombre;
}

char* getApellidoJugador(JugadorPtr jugador){
    return jugador->apellido;
}

int getEdadJugador(JugadorPtr jugador){
    return jugador->edad;
}

ListaPtr getListaTitulos(JugadorPtr jugador){
    return jugador->titulosPersonales;
}

void setNombreJugador(JugadorPtr jugador, char nombre[20]){
    strcpy(jugador->nombre, nombre);
}

void setApellidoJugador(JugadorPtr jugador, char apellido[20]){
    strcpy(jugador->apellido, apellido);
}

void setEdadJugador(JugadorPtr jugador, int edad){
    jugador->edad = edad;
}

void mostrarJugador(JugadorPtr jugador){
    printf("\n---JUGADOR---\n");
    printf("---Nombre: %s\n", getNombreJugador(jugador));
    printf("---Apellido: %s\n", getApellidoJugador(jugador));
    printf("---Edad: %d\n", getEdadJugador(jugador));
    mostrarTitulosJugador(getListaTitulos(jugador));
}

void mostrarJugadores(ListaPtr listaJugadores){

    NodoPtr actual = getPrimerNodo(listaJugadores);

    while(actual != NULL){
        mostrarJugador((JugadorPtr)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }

}
