#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct ColaE * ColaPtr;

typedef struct NodoColaE * NodoColaPtr;

NodoColaPtr crearNodoCola (ColaPtr cola, void* data);

ColaPtr crearCola();

NodoColaPtr getPrimerNodoCola(ColaPtr cola);
NodoColaPtr getUltimoNodoCola(ColaPtr cola);
NodoColaPtr getSiguienteNodoCola(NodoColaPtr actual);

void* getDatoNodoCola(NodoColaPtr actual);

int getTamanioCola(ColaPtr cola);

int encolar(ColaPtr cola, void* data);

void* desencolar(ColaPtr cola);


#endif // COLA_H_INCLUDED
