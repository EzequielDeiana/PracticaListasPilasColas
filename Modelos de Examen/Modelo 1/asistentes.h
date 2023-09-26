#ifndef ASISTENTES_H_INCLUDED
#define ASISTENTES_H_INCLUDED
#include "lista.h"

struct Asistente;

typedef struct Asistente * AsistentePtr;

AsistentePtr crearAsistente(char nombre[20], char apellido[20], char condicion[20]);

void mostrarAsistente(AsistentePtr a);

char* getNombreAsistente(AsistentePtr a);

char* getApellidoAsistente(AsistentePtr a);

char* getCondicionAsistente(AsistentePtr a);

void setNombreAsistente(AsistentePtr a, char nuevoNombre[20]);
void setApellidoAsistente(AsistentePtr a, char nuevoApellido[20]);
void setCondicionAsistente(AsistentePtr a, char condicion[20]);

void destruirAsistente(AsistentePtr a);

#endif // ASISTENTES_H_INCLUDED
