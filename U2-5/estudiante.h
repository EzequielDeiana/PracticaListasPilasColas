#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "cola.h"

typedef struct EstudianteE * EstudiantePtr;

EstudiantePtr crearEstudiante(char nombre[20], int dni);

void mostrarEstudiante(EstudiantePtr estudiante);

void mostrarEstudiantes(ColaPtr estudiantes);


#endif // ESTUDIANTE_H_INCLUDED
