#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum {FALSE , TRUE};

typedef struct NodoE * NodoPtr;

typedef struct ListaE * ListaPtr;

NodoPtr crearNodo(ListaPtr lista, void *data);
ListaPtr crearLista(int tamDelDatoEnBytes);

int estaVacia(ListaPtr lista);
int obtenerTamanio(ListaPtr lista);

void* obtenerPrimerDato(ListaPtr lista);
void* obtenerDato(ListaPtr lista, int pos);
void* obtenerUltimoDato(ListaPtr lista);

NodoPtr getPrimerNodo(ListaPtr listaActual);
NodoPtr getSiguienteNodo(NodoPtr nodoActual);
void* getDatoNodo(NodoPtr nodoActual);
void setNodoSiguiente(NodoPtr nodoActual, NodoPtr nodoSiguiente);



int insertarInicio(ListaPtr lista, void *data);
int insertar(ListaPtr lista, void *data, int pos);
int insertarFinal(ListaPtr lista, void *data);

int removerInicio(ListaPtr lista, void *backup);
void* remover (ListaPtr lista, int pos, void *backup);
int removerFinal(ListaPtr lista, void *backup);

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
