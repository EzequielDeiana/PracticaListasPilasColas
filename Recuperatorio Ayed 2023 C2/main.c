#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "pila.h"
#include "cliente.h"
#include "banco.h"



int main()
{
    printf("PARCIAL AYED - EZEQUIEL AGUSTIN - GONZALEZ - 42397100\n");

    BancoPtr b = crearBanco("Santander", "EVA PERON 1111");

    ClientePtr c1 = crearCliente("Ruben Fernandez",11,"Caja de Ahorro");
    ClientePtr c2 = crearCliente("Lucia Pascuale",9,"Inversiones");
    ClientePtr c3 = crearCliente("Brenda Benitez",11,"Moneda Extranjera");
    ClientePtr c4 = crearCliente("Luana Szpyrka",13,"Caja de Ahorro");
    ClientePtr c5 = crearCliente("John Doe",17,"Moneda Extranjera");

    insertarFinal(getListaBanco(b),&c1);
    insertarFinal(getListaBanco(b),&c2);
    insertarFinal(getListaBanco(b),&c3);
    insertarFinal(getListaBanco(b),&c4);

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarBanco(b);

    printf("\n----------PUNTO 2: Triplicar-----------\n ");
    printf("\n LISTA COPIADA 1\n");
    Lista listaCopia1 = triplicarLista(getListaBanco(b));
    mostrarListaClientes(listaCopia1);
    printf("\n LISTA COPIADA 2\n");
    Lista listaCopia2 = triplicarLista(getListaBanco(b));
    mostrarListaClientes(listaCopia2);

    printf("\n----------PUNTO 3: Ordenar y Buscar-----------\n ");
    printf("\n ORDENADA POR TURNO\n");
    ordenarPorTurno(getListaBanco(b));
    mostrarBanco(b);
    printf("\n ORDENADA POR NOMBRE\n");
    ordenarPorNombre(listaCopia1);
    mostrarListaClientes(listaCopia1);
    printf("\n BUSCAR BRENDA BENITEZ\n");
    buscarCliente(listaCopia2);
    printf("\n----------PUNTO 4: Buscar: Insertar Ordenado-----------\n ");

    insertarOrdenado(getListaBanco(b),&c5);
    mostrarBanco(b);

    printf("\n----------PUNTO 5: Apilar -----------\n ");

    PilaPtr pila = apilarClientes(listaCopia1);
    mostrarPilaClientes(pila);
    return 0;
}
