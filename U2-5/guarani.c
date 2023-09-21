#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "estudiante.h"
#include "guarani.h"

struct GuaraniE{

    ColaPtr colaDeEstudiantes;

};

GuaraniPtr crearGuarani(ColaPtr cola){

    GuaraniPtr nuevoSistemaGuarani = malloc(sizeof(struct GuaraniE));

    nuevoSistemaGuarani->colaDeEstudiantes = cola;

    return nuevoSistemaGuarani;
}

ColaPtr getColaSistema(GuaraniPtr guarani){

    return guarani->colaDeEstudiantes;

}

ColaPtr agregarEstudiantesCola(ColaPtr cola, EstudiantePtr estudiante){

    if(getTamanio(cola) < 5){
        encolar(cola,estudiante);
    } else {
        printf("\n[ERROR, LIMITE DE ESTUDIANTES EN COLA ALCANZADO]\n");
    }
}

void mostrarEstudiantesColaGuarani(GuaraniPtr guarani){

    mostrarEstudiantes(getColaSistema(guarani));

}
