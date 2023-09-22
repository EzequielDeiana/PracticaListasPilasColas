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

Lista getListaBanco(BancoPtr b);

void mostrarListaClientes(BancoPtr b);

BancoPtr crearCopiaListaDeBanco(BancoPtr b);

void ordenarListaClientes(BancoPtr b);

void mostrarClientesCajaDeAhorro(BancoPtr b);

PilaPtr pilaDeClientes(BancoPtr b);


#endif // BANCO_H_INCLUDED
