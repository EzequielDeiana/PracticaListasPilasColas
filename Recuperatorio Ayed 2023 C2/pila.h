#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct NodoPila * NodoPilaPtr;

typedef struct Pila * PilaPtr;

NodoPilaPtr crearNodoPila(PilaPtr pila, void* data);

PilaPtr crearPila();

NodoPilaPtr getPrimerNodoPila(PilaPtr pila);

NodoPilaPtr getSiguienteNodoPila(NodoPilaPtr actual);

int getTamanioPila(PilaPtr pila);

void* getDatoNodoPila(NodoPilaPtr actual);

int apilar(PilaPtr pila, void* data);

void* desapilar(PilaPtr pila);

#endif // PILA_H_INCLUDED
