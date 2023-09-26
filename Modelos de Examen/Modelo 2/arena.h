#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

struct Arena;

typedef struct Arena * ArenaPtr;

ArenaPtr crearArena(char nombreArena[20], char direccion[20]);

void mostrarArena(ArenaPtr a);

char* getNombreArena(ArenaPtr a);

char* getDireccionArena(ArenaPtr a);

void setNombreArena(ArenaPtr a, char nuevoNombre[20]);

void setDireccioArena(ArenaPtr a, char nuevaDireccion[20]);

void destruirArena(ArenaPtr a);

#endif // ARENA_H_INCLUDED
