#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "equipo.h"
#include "jugador.h"

int main()
{
    ListaPtr titulosHaaland = crearLista(sizeof(char));
    ListaPtr titulosJulian = crearLista(sizeof(char));

    insertar(titulosHaaland,"Liga de Campeones de la UEFA",0);
    insertar(titulosHaaland,"Premier League",0);
    insertar(titulosHaaland,"Copa de Alemania",0);

    insertar(titulosJulian,"Copa Mundial 2022",0);
    insertar(titulosJulian,"Copa de Campeones Conmebol-UEFA 2022",0);
    insertar(titulosJulian,"Copa America 2021",0);

    JugadorPtr j1 = crearJugador("Erling","Haaland",23,titulosHaaland);
    JugadorPtr j2 = crearJugador("Julian","Alvarez",23,titulosJulian);

    //mostrarJugador(j1);
    //mostrarJugador(j2);

    ListaPtr jugadoresCity = crearLista(sizeof(EquipoPtr));

    insertar(jugadoresCity,j1,0);
    insertar(jugadoresCity,j2,0);

    EquipoPtr manchesterCity = crearEquipo("Manchester City", 52, jugadoresCity);

    mostrarEquipo(manchesterCity);


    return 0;
}
