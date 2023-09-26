#ifndef ASISTENTE_H_INCLUDED
#define ASISTENTE_H_INCLUDED

struct Asistente;

typedef struct Asistente * AsistentePtr;

AsistentePtr crearAsistente(char nya[20], int precioEntrada);

void mostrarAsistente(AsistentePtr a);

char* getNyA(AsistentePtr a);

int getPrecio(AsistentePtr a);


void setNombreAsistente(AsistentePtr a, char nuevoNombre[20]);
void setPrecio(AsistentePtr a, int precioEntrada);

void destruirAsistente(AsistentePtr a);


#endif // ASISTENTE_H_INCLUDED
