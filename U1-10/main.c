#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "estadio.h"
#include "persona.h"

int main()
{
    ListaPtr listaMotivos1 = crearLista(sizeof(ListaPtr));
    ListaPtr listaMotivos2 = crearLista(sizeof(ListaPtr));
    ListaPtr listaMotivos3 = crearLista(sizeof(ListaPtr));

    insertar(listaMotivos1,"Conocer la cancha",0);
    insertar(listaMotivos1,"Ver al Diegote",0);
    insertar(listaMotivos1,"Huir, huir",0);

    insertar(listaMotivos2,"No se",0);
    insertar(listaMotivos2,"A pasarlo bien",0);
    insertar(listaMotivos2,"Me invito un amigo",0);

    insertar(listaMotivos3,"Que cancha?",0);
    insertar(listaMotivos3,"Que no era el ballet?",0);
    insertar(listaMotivos3,"Coso",0);

    PersonaPtr persona1 = crearPersona(listaMotivos1);
    PersonaPtr persona2 = crearPersona(listaMotivos2);
    PersonaPtr persona3 = crearPersona(listaMotivos3);

    ListaPtr listaAsistentes = crearLista(sizeof(ListaPtr));

    insertar(listaAsistentes,persona1,0);
    insertar(listaAsistentes,persona2,0);
    insertar(listaAsistentes,persona3,0);


    EstadioPtr estadio1 = crearEstadio(listaAsistentes);

    mostrarEstadio(estadio1);


    return 0;
}

