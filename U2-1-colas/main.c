#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    ColaPtr cola = crearCola();

    encolar(cola,20);
    encolar(cola,30);
    encolar(cola,40);

    printf("Coso1: %d\n", desencolar(cola));
    printf("Coso2: %d\n", desencolar(cola));
    printf("Coso3: %d\n", desencolar(cola));



    return 0;
}
