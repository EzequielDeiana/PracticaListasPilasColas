#ifndef ESTADIO_H_INCLUDED
#define ESTADIO_H_INCLUDED

typedef struct EstadioE * EstadioPtr;

EstadioPtr crearEstadio(ListaPtr listaAsistentes);

void mostrarEstadio(EstadioPtr estadio);

#endif // ESTADIO_H_INCLUDED
