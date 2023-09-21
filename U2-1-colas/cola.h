#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

enum {FALSE, TRUE};

typedef struct NodoE * NodoPtr;

typedef struct ColaE * ColaPtr;

NodoPtr crearNodo(ColaPtr cola, void* data);
ColaPtr crearCola();

void encolar(ColaPtr cola, void* data);
void* desencolar(ColaPtr cola);

NodoPtr getCabecera(ColaPtr cola);

NodoPtr getUltimo(ColaPtr cola);

int estaVacia(ColaPtr cola);
void destruirCola(ColaPtr cola);

#endif // COLA_H_INCLUDED
