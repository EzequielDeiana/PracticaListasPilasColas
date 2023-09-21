#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "estudiante.h"

struct EstudianteE{

    char nombre[20];
    int dni;

};

EstudiantePtr crearEstudiante(char nombre[20], int dni){

    EstudiantePtr nuevoEstudiante = malloc(sizeof(struct EstudianteE));

    nuevoEstudiante->dni = dni;
    strcpy(nuevoEstudiante->nombre, nombre);

    return nuevoEstudiante;
}

void mostrarEstudiante(EstudiantePtr estudiante){

    printf("-----Nombre: %s\n", estudiante->nombre);
    printf("-----Dni: %d\n\n", estudiante->dni);

}

void mostrarEstudiantes(ColaPtr estudiantes){
    while(estaVacia(estudiantes) == FALSE){
        mostrarEstudiante((EstudiantePtr)desencolar(estudiantes));
    }
}
