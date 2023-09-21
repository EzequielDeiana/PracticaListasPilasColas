#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "alumno.h"
#include "inmueble.h"

int main()
{
    /*
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
    printf("PASO CERO\n");
    system("pause");

    void* backup;
//    remover(listaAlumnosDuplicada, 1, backup);

    printf("\n\n---SEPARACION-LISTA ORIGINAL---\n\n");
    mostrarListaAlumnos(listaAlumnos);

    printf("PASO UNO\n");
    system("pause");

    printf("\n\n---SEPARACION-LISTA DUPLICADA---\n\n");
    ListaPtr listaAlumnosDuplicada = duplicarLista(listaAlumnos);
    mostrarListaAlumnos(listaAlumnosDuplicada);
    printf("PASO DOS\n");
    system("pause");

    printf("\n\n---SEPARACION-LISTA DUPLICADA ORDENADA---\n\n");
    ordenarLista(listaAlumnosDuplicada);
    mostrarListaAlumnos(listaAlumnosDuplicada);
    printf("PASO TRES\n");
    system("pause");

    printf("\n\n---SEPARACION-LISTA ORIGINAL POST ORDENAMIENTO DUPLICADO---\n\n");
    mostrarListaAlumnos(listaAlumnos);
    printf("PASO CUATRO\n");
    system("pause");

*/

    ListaPtr listaInmueble = crearLista(sizeof(InmueblePtr));
    InmueblePtr inmueble1 = crearInmueble(10000.00, 1992, "Yrigoyen 1800", "John Doe");
    InmueblePtr inmueble2 = crearInmueble(150000.00, 2002, "Yrigoyen 1700", "Pepito Grillo");
    InmueblePtr inmueble3 = crearInmueble(9200.00, 1998, "Yrigoyen 1200", "Gagandri");
    InmueblePtr inmueble4 = crearInmueble(18000.00, 2010, "Yrigoyen 2200", "Rangu");
    InmueblePtr inmueble5 = crearInmueble(11562.45, 2015, "Yrigoyen 700", "Eric Rodriguez");

    insertar(listaInmueble,inmueble1,0);
    insertarInicio(listaInmueble,inmueble2);
    insertarInicio(listaInmueble,inmueble3);
    insertarInicio(listaInmueble,inmueble4);
    insertarInicio(listaInmueble,inmueble5);

    printf("\n\n---SEPARACION-LISTA ORIGINAL---\n\n");
    mostrarListaInmueble(listaInmueble);

    printf("\n\n---SEPARACION-LISTA DUPLICADA / ORDENADA---\n\n");
    ListaPtr listaInmueble2 = duplicarLista(listaInmueble);
    ListaPtr listaInmuebleDuplicada = comprobarCantidadInmuebles(listaInmueble2);
    mostrarListaInmueble(listaInmuebleDuplicada);


    printf("\n\n---SEPARACION-LISTA ORIGINAL POST ORDENAMIENTO DUPLICADO---\n\n");
    mostrarListaInmueble(listaInmueble);
    return 0;
}
