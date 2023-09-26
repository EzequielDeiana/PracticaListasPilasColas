#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "asistente.h"

struct Asistente{

    char nya[20];
    int precio;

};

AsistentePtr crearAsistente(char nya[20], int precioEntrada){

    AsistentePtr a = (AsistentePtr)malloc(sizeof(struct Asistente));

    a->precio = precioEntrada;

    strcpy(a->nya, nya);


    return a;
}

void mostrarAsistente(AsistentePtr a){
    printf("\n\t--------ASISTENTE--------\n");
    printf("\tNOMBRE: %s\n",a->nya);
    printf("\tPRECIO ENTRADA: $%d\n",a->precio);

}

char* getNyA(AsistentePtr a){
    return a->nya;
}

int getPrecio(AsistentePtr a){
    return a->precio;
}

void setNombreAsistente(AsistentePtr a, char nuevoNombre[20]){
    strcpy(a->nya,nuevoNombre);
}
void setPrecio(AsistentePtr a, int precioEntrada){
    a->precio = precioEntrada;
}

void destruirAsistente(AsistentePtr a){
    free(a);
}
