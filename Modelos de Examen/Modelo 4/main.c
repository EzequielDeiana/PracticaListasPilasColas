#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "cola.h"
#include "disco.h"
#include "cancion.h"



int main()
{
    printf("PARCIAL AYED - NOMBRE - APELLIDO - DNI\n");
    DiscoPtr d = crearDisco("Collection7",9359);

    CancionPtr c1 = crearCancion("Cry Baby", "Raise A Suilen", 4.01);
    CancionPtr c2 = crearCancion("Unravel", "Morfonica", 3.57);
    CancionPtr c3 = crearCancion("Mental Chainsaw", "Afterglow", 2.58);
    CancionPtr c4 = crearCancion("Realize", "Roselia", 4.05);
    CancionPtr c5 = crearCancion("Megitsune", "Raise A Suilen", 4.11);

    insertarFinal(getListaDisco(d),&c1);
    insertarFinal(getListaDisco(d),&c2);
    insertarFinal(getListaDisco(d),&c3);
    insertarFinal(getListaDisco(d),&c4);
    insertarFinal(getListaDisco(d),&c5);

    Lista copiaLista = copiarListaDisco(d);

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarDisco(d);

    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarLista(d);
    mostrarDisco(d);

    printf("\n----------PUNTO 3: Copia-----------\n ");

    mostrarCanciones(copiaLista);

    printf("\n----------PUNTO 4: Buscar: Guitarra-----------\n ");

    buscarMiembro(d);

    printf("\n----------PUNTO 5: Encolar -----------\n ");

    ColaPtr nuevaCola = crearCola();

    encolar(nuevaCola,c1);
    encolar(nuevaCola,c2);
    encolar(nuevaCola,c3);
    encolar(nuevaCola,c4);
    encolar(nuevaCola,c5);

    for(int i = 0; i < 5;i++){
        mostrarCancion((CancionPtr)desencolar(nuevaCola));
    }




    return 0;
}
