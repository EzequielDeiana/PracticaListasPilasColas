#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "lista.h"
#include "cliente.h"


struct Banco{

    char nombre[15];

    char direccion[15];

    Lista listaClientes;

};



BancoPtr crearBanco(char n[15], char d[15]){

    BancoPtr b = (BancoPtr) malloc(sizeof(struct Banco));

    strcpy(b->direccion, d);

    strcpy(b->nombre, n);

    b->listaClientes = crearLista(sizeof(Lista));

    return b;

};

void mostrarBanco(BancoPtr b){

    printf("\n\n-----------BANCO-------------\n");
    printf("NOMBRE: %s\n", b->nombre);
    printf("DIRECCION: %s\n", b->direccion);
    mostrarListaClientes(getListaBanco(b));

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

void mostrarListaClientes(Lista lista){

    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        ClientePtr aux = *(ClientePtr*)getDatoNodo(actual);
        mostrarCliente(aux);
        actual = getSiguienteNodo(actual);
    }

}

Lista getListaBanco(BancoPtr b){
    return b->listaClientes;
}

Lista triplicarLista(Lista lista){

    Lista listaCopia = crearLista(sizeof(Lista));
    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){

        ClientePtr aux = *(ClientePtr*)getDatoNodo(actual);
        insertarFinal(listaCopia,&aux);
        actual = getSiguienteNodo(actual);
    }
    return listaCopia;
}

Lista ordenarPorTurno(Lista lista){

    int tam = obtenerTamanio(lista);
    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam -1; i++){
        nodo_i = getPrimerNodo(lista);
        nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            ClientePtr cliente1 = *(ClientePtr*)getDatoNodo(nodo_i);
            ClientePtr cliente2 = *(ClientePtr*)getDatoNodo(nodo_j);

            if(strcmp(getTurno(cliente1),getTurno(cliente2)) > 0){
                void* aux = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i,getDatoNodo(nodo_j));
                setDatoNodo(nodo_j,aux);
            }
        nodo_i = getSiguienteNodo(nodo_i);
        nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

Lista ordenarPorNombre(Lista lista){
    int tam = obtenerTamanio(lista);
    Nodo nodo_i, nodo_j;

    for(int i = 0; i < tam -1; i++){
        nodo_i = getPrimerNodo(lista);
        nodo_j = getSiguienteNodo(nodo_i);
        for(int j = 0; j < tam -1; j++){
            ClientePtr cliente1 = *(ClientePtr*)getDatoNodo(nodo_i);
            ClientePtr cliente2 = *(ClientePtr*)getDatoNodo(nodo_j);
            if(strcmp(getNombreYApellido(cliente1),getNombreYApellido(cliente2)) > 0){
                void* aux = getDatoNodo(nodo_i);
                setDatoNodo(nodo_i,getDatoNodo(nodo_j));
                setDatoNodo(nodo_j,aux);
            }
        nodo_i = getSiguienteNodo(nodo_i);
        nodo_j = getSiguienteNodo(nodo_j);
        }
    }

}

void buscarCliente(Lista lista){

    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        ClientePtr aux = *(ClientePtr*)getDatoNodo(actual);
        if(strcmp(getNombreYApellido(aux),"Brenda Benitez") == 0){
            mostrarCliente(aux);
        }
        actual = getSiguienteNodo(actual);
    }

}

int insertarOrdenado(Lista lista, void* dato){

    Nodo nuevoNodo = crearNodo(lista, dato);
    Nodo actual = getPrimerNodo(lista);
    int contador = 0;
    while(actual != NULL &&
          strcmp((getTurno((ClientePtr)getDatoNodo(nuevoNodo))),
                 getTurno((ClientePtr)getDatoNodo(actual))) > 0){

        actual = getSiguienteNodo(actual);
        contador++;
    }
    ClientePtr cliente = *(ClientePtr*)getDatoNodo(nuevoNodo);

    insertar(lista,&cliente,contador-1);
}

PilaPtr apilarClientes(Lista lista){

    PilaPtr nuevaPila = crearPila();
    Nodo actual = getPrimerNodo(lista);

    while(actual != NULL){
        void* aux = *(ClientePtr*)getDatoNodo(actual);
        apilar(nuevaPila,aux);
        actual = getSiguienteNodo(actual);
    }
    return nuevaPila;
}

void mostrarPilaClientes(PilaPtr pila){

    int tam = getTamanioPila(pila);

    for(int i = 0; i < tam; i++){
        ClientePtr aux = (ClientePtr)desapilar(pila);
        mostrarCliente(aux);
    }

}
