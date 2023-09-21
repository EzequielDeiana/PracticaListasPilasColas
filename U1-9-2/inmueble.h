#ifndef INMUEBLE_H_INCLUDED
#define INMUEBLE_H_INCLUDED

#include "lista.h"

typedef struct InmuebleE * InmueblePtr;

InmueblePtr crearInmueble(float valor, int anio, char direccion[20], char duenio[20]);

void mostrarInmueble(InmueblePtr inmueble);

void mostrarListaInmueble(ListaPtr listaInmuebles);

float getValorInmueble(InmueblePtr inmueble);
int getAnioInmueble(InmueblePtr inmueble);
char* getDireccionInmueble(InmueblePtr inmueble);
char* getDuenioInmueble(InmueblePtr inmueble);

ListaPtr listaDuplicada(ListaPtr listaInmuebles);
ListaPtr ordenarListaInmuebles(ListaPtr listaInmuebles);
#endif // INMUEBLE_H_INCLUDED
