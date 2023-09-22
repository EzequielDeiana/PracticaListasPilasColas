#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "lista.h"

typedef struct NodoPilaE * NodoPilaPtr;

typedef struct PilaE * PilaPtr;

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data);

PilaPtr crearPila();

int apilar(PilaPtr pila, void* data);

void* desapilar(PilaPtr pila);

int getTamanioPila(PilaPtr pila);


#endif // PILA_H_INCLUDED
