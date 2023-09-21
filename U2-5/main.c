#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "estudiante.h"
#include "guarani.h"

int main()
{

    ColaPtr cola = crearCola();

    EstudiantePtr estudiante1 = crearEstudiante("Estudiante1",11111);
    EstudiantePtr estudiante2 = crearEstudiante("Estudiante2",22222);
    EstudiantePtr estudiante3 = crearEstudiante("Estudiante3",33333);
    EstudiantePtr estudiante4 = crearEstudiante("Estudiante4",44444);
    EstudiantePtr estudiante5 = crearEstudiante("Estudiante5",55555);
    EstudiantePtr estudiante6 = crearEstudiante("Estudiante6",66666);

    agregarEstudiantesCola(cola,estudiante1);
    agregarEstudiantesCola(cola,estudiante2);
    agregarEstudiantesCola(cola,estudiante3);
    agregarEstudiantesCola(cola,estudiante4);
    agregarEstudiantesCola(cola,estudiante5);
    agregarEstudiantesCola(cola,estudiante6);

    GuaraniPtr sistema = crearGuarani(cola);



    mostrarEstudiantesColaGuarani(sistema);


    return 0;
}
