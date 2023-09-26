#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct NodoCola * NodoColaPtr;

typedef struct Cola * ColaPtr;


NodoColaPtr crearNodoCola(ColaPtr cola, void* dato);

ColaPtr crearCola();

int encolar(ColaPtr cola, void* dato);
void* desencolar(ColaPtr cola);

void* getDatoNodoCola(NodoColaPtr nodo);



#endif // COLA_H_INCLUDED
