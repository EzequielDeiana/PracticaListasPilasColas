#ifndef GUARANI_H_INCLUDED
#define GUARANI_H_INCLUDED

typedef struct GuaraniE * GuaraniPtr;

GuaraniPtr crearGuarani(ColaPtr cola);

ColaPtr agregarEstudiantesCola(ColaPtr cola, EstudiantePtr estudiante);

void mostrarEstudiantesColaGuarani(GuaraniPtr guarani);

ColaPtr getColaSistema(GuaraniPtr guarani);

#endif // GUARANI_H_INCLUDED
