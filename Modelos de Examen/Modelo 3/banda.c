#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#include "miembro.h"
#include "banda.h"

struct Banda{
    char nombre[20];
};

BandaPtr crearBanda(char nombre[20]){

    BandaPtr b = (BandaPtr)malloc(sizeof(struct Banda));

    strcpy(b->nombre,nombre);

    return b;
}

void mostrarBanda(BandaPtr b){

    printf("\n\n----------BANDA----------\n");
    printf("NOMBRE: %s\n",b->nombre);

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
