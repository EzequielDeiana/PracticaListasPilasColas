#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

enum {FALSE, TRUE};

typedef struct NodoE * NodoPtr;

typedef struct ColaE * ColaPtr;

NodoPtr crearNodo(ColaPtr cola, void* data);

ColaPtr crearCola();

void encolar(ColaPtr cola, void* data);

void* desencolar(ColaPtr cola);

int estaVacia(ColaPtr cola);

int getTamanio(ColaPtr cola);

NodoPtr getNodoCabecera(ColaPtr cola);

NodoPtr getNodoUltimo(ColaPtr cola);

void* getDato(NodoPtr nodo);


#endif // COLA_H_INCLUDED
