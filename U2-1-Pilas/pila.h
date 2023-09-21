#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct PilaE * PilaPtr;

typedef struct NodoE * NodoPtr;

PilaPtr crearPila();

NodoPtr crearNodo(PilaPtr pila, void* dato);

void apilar(PilaPtr pila, void* dato);

void* desapilar(PilaPtr pila);

NodoPtr getCabecera(PilaPtr pila);

void destruirPila(PilaPtr pila);



#endif // PILA_H_INCLUDED
