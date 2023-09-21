#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "alumno.h"

int main()
{
    ListaPtr listaAlumnos = crearLista(sizeof(AlumnoPtr));
    AlumnoPtr alumno1 = crearAlumno("Gaston", 33333, 72.50);
    AlumnoPtr alumno2 = crearAlumno("Arturo", 22222, 100.00);
    AlumnoPtr alumno3 = crearAlumno("Roberto", 55555, 100.00);
    AlumnoPtr alumno4 = crearAlumno("Alberto", 11111, 100.00);
    AlumnoPtr alumno5 = crearAlumno("Hideo", 44444, 100.00);

    insertarInicio(listaAlumnos, alumno1);
    insertarFinal(listaAlumnos, alumno2);
    insertarInicio(listaAlumnos, alumno3);
    insertarInicio(listaAlumnos, alumno4);
    insertar(listaAlumnos, alumno5, 2);
    ListaPtr prueba = comprobarCantidad(listaAlumnos);
    mostrarListaAlumnos(prueba);
    void* backup;

    printf("\n\n---SEPARACION-LISTA ORIGINAL---\n\n");
    mostrarListaAlumnos(listaAlumnos);

    printf("\n\n---SEPARACION-LISTA DUPLICADA---\n\n");
    ListaPtr listaAlumnosDuplicada = duplicarLista(listaAlumnos);
    mostrarListaAlumnos(listaAlumnosDuplicada);

    printf("\n\n---SEPARACION-LISTA DUPLICADA ORDENADA---\n\n");
    ordenarLista(listaAlumnosDuplicada);
    mostrarListaAlumnos(listaAlumnosDuplicada);

    printf("\n\n---SEPARACION-LISTA ORIGINAL POST ORDENAMIENTO DUPLICADO---\n\n");
    mostrarListaAlumnos(listaAlumnos);



    return 0;
}
