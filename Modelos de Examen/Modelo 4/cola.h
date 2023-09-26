#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct NodoCola * NodoColaPtr;

typedef struct Cola * ColaPtr;

NodoColaPtr crearNodoCola(ColaPtr cola, void* data);

ColaPtr crearCola();

int encolar(ColaPtr cola, void* data);

void* desencolar(ColaPtr cola);

int getTamanioCola(ColaPtr cola);

void* getDatoNodoCola(NodoColaPtr actual);

#endif // COLA_H_INCLUDED
