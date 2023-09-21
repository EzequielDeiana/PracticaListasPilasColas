#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "equipo.h"


struct EquipoE{

    char nombre[20];

    int titulos;

    ListaPtr listaJugadores;

};

EquipoPtr crearEquipo(char nombre[20], int titulos, ListaPtr listaJugadores){

    EquipoPtr nuevoEquipo = malloc(sizeof(struct EquipoE));

    strcpy(nuevoEquipo->nombre, nombre);
    nuevoEquipo->titulos = titulos;
    nuevoEquipo->listaJugadores = listaJugadores;

    return nuevoEquipo;

}

char* getNombre(EquipoPtr equipo){
    return equipo->nombre;
}

int getTitulos(EquipoPtr equipo){
    return equipo->titulos;
}

ListaPtr getListaJugadores(EquipoPtr equipo){
    return equipo->listaJugadores;
}

void setNombre(EquipoPtr equipo, char nuevoNombre[20]){
    strcpy(equipo->nombre, nuevoNombre);
}

void setTitulos(EquipoPtr equipo, int titulos){
    equipo->titulos = titulos;
}

void mostrarEquipo(EquipoPtr equipo){
    NodoPtr actual = getPrimerNodo(getListaJugadores(equipo));
    int tam = obtenerTamanio(getListaJugadores(equipo));
        printf("-------Nombre del Equipo: %s\n", getNombre(equipo));
        printf("-------Titulos: %d\n", getTitulos(equipo));
        printf("-------Jugadores: \n");
        mostrarJugadores(getListaJugadores(equipo));

}
