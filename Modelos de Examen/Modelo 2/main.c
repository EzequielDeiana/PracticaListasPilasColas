#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "pila.h"

#include "asistente.h"
#include "arena.h"



int main()
{
    printf("PARCIAL AYED - NOMBRE - APELLIDO - DNI\n");

    ArenaPtr a = crearArena("Movistar Arena", "Humboldt 450");

    AsistentePtr p1 = crearAsistente("Aina Aiba", 15000);
    AsistentePtr p2 = crearAsistente("Haruka Kudou", 7500);
    AsistentePtr p3 = crearAsistente("Yuki Nakashima", 8500);
    AsistentePtr p4 = crearAsistente("Megu Sakuragawa", 20000);
    AsistentePtr p5 = crearAsistente("Kanon Shizaki", 10000);

    insertarFinal(getListaArena(a),&p1);
    insertarFinal(getListaArena(a),&p2);
    insertarFinal(getListaArena(a),&p3);
    insertarFinal(getListaArena(a),&p4);
    insertarFinal(getListaArena(a),&p5);

    Lista listaCopiada = copiarLista(getListaArena(a));

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarArena(a);

    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarListaAsistentes(a);
    mostrarArena(a);

    printf("\n----------PUNTO 3: Copia-----------\n ");

    mostrarAsistentes(listaCopiada);

    printf("\n----------PUNTO 4: Buscar: > $10000-----------\n ");

    buscarAsistentes(a);

    printf("\n----------PUNTO 5: Apilar -----------\n ");

    PilaPtr nuevaPila = crearPila();

    apilar(nuevaPila,p1);
    apilar(nuevaPila,p2);
    apilar(nuevaPila,p3);
    apilar(nuevaPila,p4);
    apilar(nuevaPila,p5);

    for(int i = 0; i < 5; i++){
        mostrarAsistente((AsistentePtr)desapilar(nuevaPila));
    }


    return 0;
}
