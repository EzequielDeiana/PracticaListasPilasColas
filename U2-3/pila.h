#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

enum {FALSE, TRUE};

typedef struct NodoE * NodoPtr;

typedef struct PilaE * PilaPtr;

NodoPtr crearNodo(PilaPtr pila, void* data);

PilaPtr crearPila();

void apilar(PilaPtr pila, void* data);

void* desapilar(PilaPtr pila);

NodoPtr getCabecera(PilaPtr pila);

void destruirPila(PilaPtr pila);

int estaVacia(PilaPtr pila);



#endif // PILA_H_INCLUDED
