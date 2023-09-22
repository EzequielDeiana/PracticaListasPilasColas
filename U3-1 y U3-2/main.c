#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbol.h"

int main()
{
    srand(time(NULL));
    printf("----- Ejemplo arbol binario ----\n");

    Nodo raiz = nuevoNodo(rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);
    insertar(raiz, rand()%100);

    printf("\nImprimiendo preorden\n");
    preorden(raiz);
    printf("\nImprimiendo inorden\n");
    inorden(raiz);
    printf("\nImprimiendo postorden\n");
    postorden(raiz);

    printf("\nBuscando el 30\n");
    Nodo buscado = buscar(raiz, 30);

    if(buscado == NULL){
        printf("No encontrado!!!!!");
    }

    else{

        printf("Encontrado");
    }



    return 0;
}
