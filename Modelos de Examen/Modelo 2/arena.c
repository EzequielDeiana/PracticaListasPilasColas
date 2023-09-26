#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "asistente.h"
#include "arena.h"

struct Arena{

    char nombre[20];
    char direccion[20];

};

ArenaPtr crearArena(char nombreArena[20], char direccion[20]){

    ArenaPtr a = (ArenaPtr)malloc(sizeof(struct Arena));

    strcpy(a->nombre,nombreArena);
    strcpy(a->direccion,direccion);

    return a;
}

void mostrarArena(ArenaPtr a){

    printf("\n\n----------ARENA----------\n");
    printf("NOMBRE: %s\n", a->nombre);
    printf("DIRECCION: %s\n", a->direccion);

}

char* getNombreArena(ArenaPtr a){
    return a->nombre;
}

char* getDireccionArena(ArenaPtr a){
    return a->direccion;
}

void setNombreArena(ArenaPtr a, char nuevoNombre[20]){
    strcpy(a->nombre, nuevoNombre);
}

void setDireccioArena(ArenaPtr a, char nuevaDireccion[20]){
    strcpy(a->direccion, nuevaDireccion);
}

void destruirArena(ArenaPtr a){
    free(a);
}
