#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int edad = 52;
    int edad2 = 55;
    int edad3 = 23;

    PilaPtr pila = crearPila();

    apilar(pila,edad);
    apilar(pila,edad2);
    apilar(pila,edad3);

    printf("MOSTRAR PILA \n");

    for(int i = 0; i < 3; i++){
        printf("Edad: %d \n", (int)desapilar(pila));
    }

    return 0;
}
