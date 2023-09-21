#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "moneda.h"

int main()
{

    PilaPtr pilaMonedas = crearPila();

    MonedaPtr moneda1 = crearMoneda(50.25,"bronce", 1997);
    MonedaPtr moneda2 = crearMoneda(22.50,"dorado", 1990);
    MonedaPtr moneda3 = crearMoneda(100.75,"plateado", 2000);

    apilar(pilaMonedas,moneda1);
    apilar(pilaMonedas,moneda2);
    apilar(pilaMonedas,moneda3);

    mostrarMonedas(pilaMonedas);

    return 0;
}
