#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "cola.h"

#include "asistentes.h"
#include "estadio.h"



int main()
{
    printf("PARCIAL AYED - NOMBRE - APELLIDO - DNI\n");
    EstadioPtr e = crearEstadio("Monumental", 84000);

    AsistentePtr a1 = crearAsistente("Hernan", "Lopez", "Socio");
    AsistentePtr a2 = crearAsistente("Juan", "Perez", "Neutral");
    AsistentePtr a3 = crearAsistente("Ruben", "Insua", "Neutral");
    AsistentePtr a4 = crearAsistente("Ricardo", "Alonso", "Socio");
    AsistentePtr a5 = crearAsistente("Ricardo", "Martinez", "Socio");


    insertarFinal(getListaEstadio(e),&a1);
    insertarFinal(getListaEstadio(e),&a2);
    insertarFinal(getListaEstadio(e),&a3);
    insertarFinal(getListaEstadio(e),&a4);
    insertarFinal(getListaEstadio(e),&a5);

    Lista listaCopiaAsistentes = copiaListaAsistentes(e);

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarEstadio(e);

    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarLista(e);
    mostrarEstadio(e);

    printf("\n----------PUNTO 3: Copia-----------\n ");

    mostrarListaAsistentes(listaCopiaAsistentes);

    printf("\n----------PUNTO 4: Buscar: Socio-----------\n ");

    mostrarSocios(e,"Socio");

    printf("\n----------PUNTO 5: Encolar -----------\n ");

    ColaPtr cola = crearCola();

    encolar(cola, a1);
    encolar(cola, a2);
    encolar(cola, a3);
    encolar(cola, a4);
    encolar(cola, a5);

    for(int i = 0; i < 5; i++){
        mostrarAsistente((AsistentePtr)desencolar(cola));
    }

    return 0;
}
