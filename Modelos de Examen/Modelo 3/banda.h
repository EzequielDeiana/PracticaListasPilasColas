#ifndef BANDA_H_INCLUDED
#define BANDA_H_INCLUDED

struct Banda;

typedef struct Banda * BandaPtr;

BandaPtr crearBanda(char nombre[20]);

void mostrarBanda(BandaPtr b);

char* getNombreBanda(BandaPtr b);

void setNombreBanda(BandaPtr b, char nombre[20]);

void destruir(BandaPtr b);

Lista getListaBanda(BandaPtr b);

void mostrarMiembros(Lista lista);

Lista copiarListaBanda(Lista lista);

void ordenarListaBanda(BandaPtr b);

void buscarMiembro(BandaPtr b);

#endif // BANDA_H_INCLUDED
