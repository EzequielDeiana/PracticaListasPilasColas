#ifndef ESTADIO_H_INCLUDED
#define ESTADIO_H_INCLUDED
#include "lista.h"

struct Estadio;

typedef struct Estadio * EstadioPtr;

EstadioPtr crearEstadio(char nombreEstadio[20],int capacidad);

void mostrarEstadio(EstadioPtr e);

char *getNombreEstadio(EstadioPtr e);

int getCapacidadEstadio(EstadioPtr e);

void setNombreEstadio(EstadioPtr e, char nuevo[20]);

void setCapacidadEstadio(EstadioPtr e, int nuevaCapacidad);

void destruirEstadio(EstadioPtr e);

void mostrarListaAsistentes(Lista lista);

Lista getListaEstadio(EstadioPtr e);

Lista copiaListaAsistentes(EstadioPtr e);

void ordenarLista(EstadioPtr e);

void mostrarSocios(EstadioPtr e, char clave[20]);


#endif // ESTADIO_H_INCLUDED
