#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct NodoPila * NodoPilaPtr;

typedef struct Pila * PilaPtr;

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data);

PilaPtr crearPila();

int apilar(PilaPtr pila, void* data);

void* desapilar(PilaPtr pila);

int getTamanioPila(PilaPtr pila);


#endif // PILA_H_INCLUDED
