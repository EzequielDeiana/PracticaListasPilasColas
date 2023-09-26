#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "miembro.h"
#include "banda.h"

struct Miembro{

    char nombre[20];
    char instrumento[20];
    int antiguedad;

};

MiembroPtr crearMiembro(char nombre[20], char instrumento[20], int antiguedad){

    MiembroPtr m = (MiembroPtr)malloc(sizeof(struct Miembro));

    strcpy(m->nombre, nombre);
    strcpy(m->instrumento, instrumento);
    m->antiguedad = antiguedad;

    return m;
}

void mostrarMiembro(MiembroPtr m){

    printf("\n\t--------MIEMBRO--------\n");
    printf("\tNOMBRE: %s\n",m->nombre);
    printf("\tINSTRUMENTO: %s\n",m->instrumento);
    printf("\tANTIGUEDAD: %d\n",m->antiguedad);

}

char* getNombreMiembro(MiembroPtr m){
    return m->nombre;
}

char* getInstrumento(MiembroPtr m){
    return m->instrumento;
}

int getAntiguedad(MiembroPtr m){
    return m->antiguedad;
}

void setNombreMiembro(MiembroPtr m, char nombre[20]){
    strcpy(m->nombre,nombre);
}

void setInstrumento(MiembroPtr m, char instrumento[20]){
    strcpy(m->instrumento, instrumento);
}

void setAntiguedad(MiembroPtr m, int antiguedad){
    m->antiguedad = antiguedad;
}

void destruirMiembro(MiembroPtr m){
    free(m);
}

