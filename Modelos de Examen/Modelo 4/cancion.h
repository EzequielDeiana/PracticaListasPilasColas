#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

struct Cancion;

typedef struct Cancion * CancionPtr;

CancionPtr crearCancion(char nombre[20], char banda[20], float duracion);

void mostrarCancion(CancionPtr c);

char* getNombreCancion(CancionPtr c);
char* getBandaCancion(CancionPtr c)
float getDuracionCancion(CancionPtr c);

void setNombreCancion(CancionPtr c, char nombre[20]);
void setBandaCancion(CancionPtr c, char banda[20]);
void serDuracionCancion(CancionPtr c, float duracion);

void destruirCancion(CancionPtr c);


#endif // CANCION_H_INCLUDED
