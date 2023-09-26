#ifndef MIEMBRO_H_INCLUDED
#define MIEMBRO_H_INCLUDED

struct Miembro;

typedef struct Miembro * MiembroPtr;

MiembroPtr crearMiembro(char nombre[20], char instrumento[20], int antiguedad);

void mostrarMiembro(MiembroPtr m);

char* getNombreMiembro(MiembroPtr m);
char* getInstrumento(MiembroPtr m);
int getAntiguedad(MiembroPtr m);

void setNombreMiembro(MiembroPtr m, char nombre[20]);
void setInstrumento(MiembroPtr m, char instrumento[20]);
void setAntiguedad(MiembroPtr m, int antiguedad);

void destruirMiembro(MiembroPtr m);




#endif // MIEMBRO_H_INCLUDED
