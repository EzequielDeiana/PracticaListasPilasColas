#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "estadio.h"
#include "persona.h"

struct PersonaE{

    ListaPtr listaMotivos;

};

PersonaPtr crearPersona(ListaPtr motivos){
    PersonaPtr persona = malloc(sizeof(struct PersonaE));

    persona->listaMotivos = motivos;

    return persona;
}

void mostrarPersona(PersonaPtr persona){
    NodoPtr actual = getPrimerNodo(persona->listaMotivos);
    while(actual != NULL){
        printf("%s\n",(char*)getDatoNodo(actual));
        actual = getSiguienteNodo(actual);
    }
}

