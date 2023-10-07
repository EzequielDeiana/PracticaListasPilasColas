#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "lista.h"
#include "pila.h"

struct Banco;

typedef struct Banco * BancoPtr;

BancoPtr crearBanco(char n[15], char d[15]);

void mostrarBanco(BancoPtr b);

char *getNombre(BancoPtr b );

char * getDireccion(BancoPtr b);

void setNombre(BancoPtr b, char  nuevo[15]);

void setDireccion(BancoPtr b, char  nuevo[15]);

void destruirBanco(BancoPtr b);

void mostrarListaClientes(Lista lista);

Lista getListaBanco(BancoPtr b);

Lista triplicarLista(Lista lista);

Lista ordenarPorTurno(Lista lista);

Lista ordenarPorNombre(Lista lista);

void buscarCliente(Lista lista);

int insertarOrdenado(Lista lista, void* dato);

PilaPtr apilarClientes(Lista lista);

void mostrarPilaClientes(PilaPtr pila);

#endif // BANCO_H_INCLUDED
