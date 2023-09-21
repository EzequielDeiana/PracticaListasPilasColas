#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED
#include "lista.h"
#include "jugador.h"


typedef struct EquipoE * EquipoPtr;

EquipoPtr crearEquipo(char nombre[20], int titulos, ListaPtr listaJugadores);

void mostrarEquipo(EquipoPtr equipo);

char* getNombre(EquipoPtr equipo);
int getTitulos(EquipoPtr equipo);
ListaPtr getListaJugadores(EquipoPtr equipo);

void setNombre(EquipoPtr equipo, char nuevoNombre[20]);
void setTitulos(EquipoPtr equipo, int titulos);

void destruirEquipo(EquipoPtr equipo);


#endif // EQUIPO_H_INCLUDED
