#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "pila.h"

#include "cliente.h"
#include "banco.h"




int main()
{
    printf("PARCIAL AYED - NOMBRE - APELLIDO - DNI\n");

    ClientePtr c1 = crearCliente("Ruben Fernandez",11,"Caja de ahorro");
    ClientePtr c2 = crearCliente("Lucia Pascuale",9,"Inversiones");
    ClientePtr c3 = crearCliente("Brenda Benitez",11,"Moneda Extranjera");
    ClientePtr c4 = crearCliente("Luana Szpyrka",13,"Caja de ahorro");

    BancoPtr banco = crearBanco("Santander","EVA PERON 1111");

    insertarFinal(getListaBanco(banco),&c1);
    insertarFinal(getListaBanco(banco),&c2);
    insertarFinal(getListaBanco(banco),&c3);
    insertarFinal(getListaBanco(banco),&c4);

    BancoPtr bancoCopia = crearCopiaListaDeBanco(banco);

    printf("\n----------PUNTO 1: Original-----------\n ");

    mostrarBanco(banco);

    printf("\n----------PUNTO 2: Ordenado-----------\n ");

    ordenarListaClientes(banco);
    mostrarBanco(banco);

    printf("\n----------PUNTO 3: Copia-----------\n ");

    mostrarBanco(bancoCopia);

    printf("\n----------PUNTO 4: Buscar: Caja de Ahorro-----------\n ");

    mostrarClientesCajaDeAhorro(banco);

    printf("\n----------PUNTO 5: Apilar -----------\n ");

    PilaPtr pilaBanco = pilaDeClientes(bancoCopia);

    for(int i = 0; i < 4; i++){
        mostrarCliente(desapilar((ClientePtr)pilaBanco));
    }



    return 0;
}
