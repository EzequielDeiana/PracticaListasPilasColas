#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "disco.h"

struct Disco{

    char nombre[20];
    int precio;

};

DiscoPtr crearDisco(char nombre[20], int precio){

    DiscoPtr d = (DiscoPtr)malloc(sizeof(struct Disco));

    strcpy(d->nombre,nombre);
    d->precio = precio;

    return d;
}

void mostrarDisco(DiscoPtr d){
    printf("\n\t--------DISCO--------\n");
    printf("\tNOMBRE: %s\n",d->nombre);
    printf("\tPRECIO: $%d\n",d->precio);
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
