#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "persona.h"
#include "estadio.h"

struct EstadioE{

    ListaPtr listaAsistentes;

};

EstadioPtr crearEstadio(ListaPtr listaAsistentes){

    EstadioPtr nuevoEstadio = malloc(sizeof(struct EstadioE));

    nuevoEstadio->listaAsistentes = listaAsistentes;

    return nuevoEstadio;
}

void mostrarEstadio(EstadioPtr estadio){
    NodoPtr nodoActual = getPrimerNodo(estadio->listaAsistentes);
    int i = 1;
    while(nodoActual != NULL){
        printf("Motivos para ir a la cancha Persona %d: \n", i);
        mostrarPersona((PersonaPtr)getDatoNodo(nodoActual));
        nodoActual = getSiguienteNodo(nodoActual);
        i++;
        printf("\n\n");
    }

}
