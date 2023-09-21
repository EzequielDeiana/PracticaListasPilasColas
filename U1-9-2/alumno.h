#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "lista.h"

typedef struct AlumnoE * AlumnoPtr;

AlumnoPtr crearAlumno(char nombre[30], int dni, float promedio);

void mostrarAlumno(AlumnoPtr alumno);

void mostrarListaAlumnos(ListaPtr listaAlumnos);

char* getNombreAlumno(AlumnoPtr alumno);
int getDniAlumno(AlumnoPtr alumno);
float getPromedioAlumno(AlumnoPtr alumno);



#endif // ALUMNO_H_INCLUDED
