#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

typedef struct MonedaE * MonedaPtr;

MonedaPtr crearMoneda(float valor, char color[20], int anio);

void mostrarMoneda(MonedaPtr moneda);

void mostrarMonedas(PilaPtr pilaMonedas);




#endif // MONEDA_H_INCLUDED
