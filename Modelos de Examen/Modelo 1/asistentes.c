#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include "asistentes.h"

struct Asistente{

    char nombre[20];
    char apellido[20];
    char condicion[20];

};

AsistentePtr crearAsistente(char nombre[20], char apellido[20], char condicion[20]){

    AsistentePtr asistente = (AsistentePtr)malloc(sizeof(struct Asistente));

    strcpy(asistente->nombre,nombre);
    strcpy(asistente->apellido,apellido);
    strcpy(asistente->condicion,condicion);

    return asistente;
}

void mostrarAsistente(AsistentePtr a){

    printf("\n\t--------ASISTENTE--------\n");
    printf("\tNOMBRE: %s\n",a->nombre);
    printf("\tAPELLIDO: %s\n",a->apellido);
    printf("\tCONDICION: %s\n",a->condicion);

}

char* getNombreAsistente(AsistentePtr a){
    return a->nombre;
}

char* getApellidoAsistente(AsistentePtr a){
    return a->apellido;
}

char* getCondicionAsistente(AsistentePtr a){
    return a->condicion;
}

void setNombreAsistente(AsistentePtr a, char nuevoNombre[20]){
    strcpy(a->nombre,nuevoNombre);
}

void setApellidoAsistente(AsistentePtr a, char nuevoApellido[20]){
    strcpy(a->apellido,nuevoApellido);
}

void setCondicionAsistente(AsistentePtr a, char condicion[20]){
    strcpy(a->condicion,condicion);
}

void destruirAsistente(AsistentePtr a){
    free(a);
}
