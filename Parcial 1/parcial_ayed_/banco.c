#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "cliente.h"
#include "banco.h"
#include "pila.h"


struct Banco{

    char nombre[15];

    char direccion[15];

    Lista listaClientes;

};



BancoPtr crearBanco(char n[15], char d[15]){

    BancoPtr b = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(b->direccion, d);

    strcpy(b->nombre, n);

    b->listaClientes = (Lista)crearLista(sizeof(ClientePtr));

    return b;

};

void mostrarBanco(BancoPtr b){

    printf("\n\n-----------BANCO-------------\n");
    printf("NOMBRE: %s\n", b->nombre);
    printf("DIRECCION: %s\n", b->direccion);
    mostrarListaClientes(b);


};

char *getNombre(BancoPtr b ){
    return b->nombre;
};

char * getDireccion(BancoPtr b){
    return b->direccion;
};

void setNombre(BancoPtr b, char nuevo[15]){

    strcpy(b->nombre, nuevo);

};

void setDireccion(BancoPtr b, char  nuevo[15]){
    strcpy(b->direccion, nuevo);
};

void destruirBanco(BancoPtr b){

    free(b);
};

Lista getListaBanco(BancoPtr b){
    return b->listaClientes;
}

void mostrarListaClientes(BancoPtr b){
    Nodo actual = getPrimerNodo(getListaBanco(b));

    while(actual != NULL){
        mostrarCliente(*(ClientePtr*)getDatoNodo(actual));
        actual = getProximoNodo(actual);
    }
}

BancoPtr crearCopiaListaDeBanco(BancoPtr b){
    BancoPtr bancoCopia = crearBanco(b->nombre,b->direccion);
    Lista listaCopia = (Lista)crearLista(sizeof(ClientePtr));
    Nodo actual = getPrimerNodo(getListaBanco(b));
    while(actual != NULL){
        Nodo aux = crearNodo(listaCopia, getDatoNodo(actual));
        actual = getProximoNodo(actual);
        insertarFinal(listaCopia,getDatoNodo(aux));
    }
    bancoCopia->listaClientes = listaCopia;
    return bancoCopia;
}

void ordenarListaClientes(BancoPtr b){

    Lista listaClientes = getListaBanco(b);

    int tam = obtenerTamanio(listaClientes);

    if(tam <= 1){
        return;
    }

    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam - 1; i++){
        nodo_i = getPrimerNodo(listaClientes);
        nodo_j = getProximoNodo(nodo_i);
        for(int j = 0; j < tam - i - 1; j++){
            ClientePtr cliente_i = *(ClientePtr*)getDatoNodo(nodo_i);
            ClientePtr cliente_j = *(ClientePtr*)getDatoNodo(nodo_j);

            if(getHora(cliente_i) > getHora(cliente_j)){
                void * temp = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i, getDatoNodo(nodo_j));
                setDatoNodo(nodo_j, temp);
            }
        nodo_i = nodo_j;
        nodo_j = getProximoNodo(nodo_j);
        }
    }

}

void mostrarClientesCajaDeAhorro(BancoPtr b){

    Nodo actual = getPrimerNodo(getListaBanco(b));

    while(actual != NULL){
        ClientePtr cliente1 = *(ClientePtr*)getDatoNodo(actual);
        if(strcmp(getTurno(cliente1), "Caja de ahorro" ) == 0){
            mostrarCliente(cliente1);
        }
        actual = getProximoNodo(actual);
    }

}

PilaPtr pilaDeClientes(BancoPtr b){
    PilaPtr pilaNueva = crearPila();

    Nodo actual = getPrimerNodo(getListaBanco(b));

    while(actual != NULL){
        apilar(pilaNueva,*(ClientePtr*)getDatoNodo(actual));
        actual = getProximoNodo(actual);
    }

    return pilaNueva;
}
