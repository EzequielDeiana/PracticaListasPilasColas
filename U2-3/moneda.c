#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "moneda.h"

struct MonedaE{

    float valor;
    char color[20];
    int anio;

};

MonedaPtr crearMoneda(float valor, char color[20], int anio){

    MonedaPtr nuevaMoneda = malloc(sizeof(struct MonedaE));

    nuevaMoneda->anio = anio;
    nuevaMoneda->valor = valor;
    strcpy(nuevaMoneda->color, color);

    return nuevaMoneda;
}

void mostrarMoneda(MonedaPtr moneda){

    printf("\n-----Anio: %d\n", moneda->anio);
    printf("-----Color: %s\n", moneda->color);
    printf("-----Valor: $%.2f\n", moneda->valor);

}

void mostrarMonedas(PilaPtr pilaMonedas){

    while(estaVacia(pilaMonedas) == FALSE){
        mostrarMoneda((MonedaPtr)desapilar(pilaMonedas));
    }

}
