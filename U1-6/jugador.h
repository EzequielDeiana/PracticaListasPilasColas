#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "lista.h"
#include "equipo.h"

typedef struct JugadorE * JugadorPtr;

JugadorPtr crearJugador(char nombre[20], char apellido[20], int edad,  ListaPtr titulosPersonales);

char* getNombreJugador(JugadorPtr jugador);
char* getApellidoJugador(JugadorPtr jugador);
int getEdadJugador(JugadorPtr jugador);
ListaPtr getListaTitulos(JugadorPtr jugador);
void agregarTitulo(JugadorPtr jugador, char titulo[50]);

void setNombreJugador(JugadorPtr jugador, char nombre[20]);
void setApellidoJugador(JugadorPtr jugador, char apellido[20]);
void setEdadJugador(JugadorPtr jugador, int edad);

void mostrarJugador(JugadorPtr jugador);
void mostrarJugadores(ListaPtr listaJugadores);

void eliminarJugador(JugadorPtr jugador);

#endif // JUGADOR_H_INCLUDED
