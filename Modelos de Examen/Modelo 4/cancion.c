#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "disco.h"
#include "cancion.h"

struct Cancion{

    char nombre[20];
    char banda[20];
    float duracion;

};

CancionPtr crearCancion(char nombre[20], char banda[20], float duracion){

    CancionPtr nueva = malloc(sizeof(struct Cancion));

    strcpy(nueva->nombre,nombre);
    strcpy(nueva->banda,banda);
    nueva->duracion = duracion;

    return nueva;
}

void mostrarCancion(CancionPtr c){

    printf("\n\t--------CANCION--------\n");
    printf("\tNOMBRE: %s\n",c->nombre);
    printf("\tBANDA: %s\n",c->banda);
    printf("\tDURACION: %.2f\n",c->duracion);
}

char* getNombreCancion(CancionPtr c){
    return c->nombre;
}

char* getBandaCancion(CancionPtr c){
    return c->banda;
}

float getDuracionCancion(CancionPtr c){
    return c->duracion;
}

void setNombreCancion(CancionPtr c, char nombre[20]){
    strcpy(c->nombre,nombre);
}

void setBandaCancion(CancionPtr c, char banda[20]){
    strcpy(c->banda,banda);
}

void serDuracionCancion(CancionPtr c, float duracion){
    c->duracion = duracion;
}
