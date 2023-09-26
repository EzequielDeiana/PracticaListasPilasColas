#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "cola.h"

#include "miembro.h"
#include "banda.h"



int main()
{
    printf("PARCIAL AYED - NOMBRE - APELLIDO - DNI\n");

    BandaPtr b = crearBanda("Afterglow");

    MiembroPtr m1 = crearMiembro("Ran Mitake", "Guitarra", 5);
    MiembroPtr m2 = crearMiembro("Himari Uehara", "Bajo", 3);
    MiembroPtr m3 = crearMiembro("Tsugumi Hazawa", "Teclado", 6);
    MiembroPtr m4 = crearMiembro("Moca Aoba", "Guitarra", 2);
    MiembroPtr m5 = crearMiembro("Tomoe Udagawa", "Bateria", 7);

    insertarFinal(getListaBanda(b),&m1);
    insertarFinal(getListaBanda(b),&m2);
    insertarFinal(getListaBanda(b),&m3);
    insertarFinal(getListaBanda(b),&m4);
    insertarFinal(getListaBanda(b),&m5);

    Lista copia = copiarListaBanda(getListaBanda(b));

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarBanda(b);

    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarListaBanda(b);
    mostrarBanda(b);

    printf("\n----------PUNTO 3: Copia-----------\n ");

    mostrarMiembros(copia);

    printf("\n----------PUNTO 4: Buscar: Guitarra-----------\n ");

    buscarMiembro(b);

    printf("\n----------PUNTO 5: Encolar -----------\n ");

    ColaPtr cola = crearCola();

    encolar(cola,m1);
    encolar(cola,m2);
    encolar(cola,m3);
    encolar(cola,m4);
    encolar(cola,m5);

    for(int i = 0; i < 5; i++){
        mostrarMiembro((MiembroPtr)desencolar(cola));
    }

    return 0;
}
