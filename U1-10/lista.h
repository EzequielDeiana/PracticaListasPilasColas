#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum {FALSE, TRUE};

typedef struct ListaE * ListaPtr;

typedef struct NodoE * NodoPtr;

ListaPtr crearLista(int tamDelDatoEnBytes);

NodoPtr crearNodo(ListaPtr lista, void* data);

int estaVacia(ListaPtr lista);
int getTamanioLista(ListaPtr lista);

void* obtenerPrimerDato(ListaPtr lista);
void* obtenerDato(ListaPtr lista, int pos);
void* obtenerUltimoDato(ListaPtr lista);

int insertarInicio(ListaPtr lista, void* data);
int insertar(ListaPtr lista, void* data, int pos);
int insertarFinal(ListaPtr lista, void* data);

int removerInicio(ListaPtr lista, void* backup);
void* remover(ListaPtr lista, void* backup, int pos);
int removerFinal(ListaPtr lista, void* backup);

void liberarLista(ListaPtr lista);

NodoPtr getPrimerNodo(ListaPtr listaActual);
NodoPtr getSiguienteNodo(NodoPtr nodoActual);
void* getDatoNodo(NodoPtr nodoActual);
void setDatoEnLista(ListaPtr listaActual, void* dato, int pos);

#endif // LISTA_H_INCLUDED
