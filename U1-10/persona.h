#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "lista.h"

typedef struct PersonaE * PersonaPtr;

PersonaPtr crearPersona(ListaPtr motivos);

void mostrarPersona(PersonaPtr persona);

void mostrarMotivos(ListaPtr motivos);



#endif // PERSONA_H_INCLUDED
