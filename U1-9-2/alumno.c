#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "alumno.h"

struct AlumnoE{

    char nombre[30];
    int dni;
    float promedio;

};

AlumnoPtr crearAlumno(char nombre[30], int dni, float promedio){

    AlumnoPtr nuevoAlumno = malloc(sizeof(struct AlumnoE));

    nuevoAlumno->dni = dni;
    nuevoAlumno->promedio = promedio;
    strcpy(nuevoAlumno->nombre, nombre);

    return nuevoAlumno;
};

void mostrarAlumno(AlumnoPtr alumno){

    printf("\n-----NOMBRE: %s\n", getNombreAlumno(alumno));
    printf("-----DNI: %d\n", getDniAlumno(alumno));
    printf("-----PROMEDIO: %.2f\n", getPromedioAlumno(alumno));
}

void mostrarListaAlumnos(ListaPtr listaAlumnos){
    NodoPtr actual = getPrimerNodo(listaAlumnos);

    while(actual != NULL){
            mostrarAlumno((AlumnoPtr)getDatoNodo(actual));
            actual = getSiguienteNodo(actual);
    }
}
ListaPtr ordenarLista(ListaPtr listaAlumnos){
    int intercambiado = 0;
    do
    {
        intercambiado = 0;
        for(int j = 0; j < obtenerTamanio(listaAlumnos)-1 ; j++){
            AlumnoPtr alumno1 = (AlumnoPtr)obtenerDato(listaAlumnos,j);
            AlumnoPtr alumno2 = (AlumnoPtr)obtenerDato(listaAlumnos,j+1);
            if(strcmp(getNombreAlumno(alumno1), getNombreAlumno(alumno2)) > 0){
                AlumnoPtr alumno3 = remover(listaAlumnos, j, alumno3);
                insertar(listaAlumnos, alumno3, j+1);
                intercambiado = 1;
            }
        }
    }while(intercambiado == 1);
    return listaAlumnos;

}

char* getNombreAlumno(AlumnoPtr alumno){
    return alumno->nombre;
}

int getDniAlumno(AlumnoPtr alumno){
    return alumno->dni;
}

float getPromedioAlumno(AlumnoPtr alumno){
    return alumno->promedio;
}

ListaPtr comprobarCantidad(ListaPtr listaActual){

    if(obtenerTamanio(listaActual) >= 5){

        ListaPtr listaDuplicada = crearLista(200);

        printf("PASO CREAR\n");
        system("pause");

        listaDuplicada = duplicarLista(listaActual);

        printf("PASO DUPLICAR\n");
        system("pause");

        ordenarLista(listaDuplicada);

        printf("PASO ORDENAR\n");
        system("pause");

        mostrarListaAlumnos(listaDuplicada);

        printf("PASO MOSTRAR\n");
        system("pause");

        return listaDuplicada;

    }
}
