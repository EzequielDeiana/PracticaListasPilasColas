#ifndef DISCO_H_INCLUDED
#define DISCO_H_INCLUDED
#include "lista.h"

struct Disco;

typedef struct Disco * DiscoPtr;

DiscoPtr crearDisco(char nombre[20], int precio);

void mostrarDisco(DiscoPtr d);

char* getNombreDisco(DiscoPtr d);

int getPrecioDisco(DiscoPtr d);

void setNombreDisco(DiscoPtr d, char nombre[20]);
void setPrecioDisco(DiscoPtr d, int precio);

void destruirDisco(DiscoPtr d);

#endif // DISCO_H_INCLUDED
