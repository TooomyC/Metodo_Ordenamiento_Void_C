#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Mostrar)(const void* e);

void ord_seleccion(void* v, int cantElem, int tamElem, Cmp cmp);
void mostrar_vec(void* v, int cantElem, int tamElem, Mostrar mostrar);
void inicializa_VecRandom(int* v, int cantElem);

void ord_burbujeo(int* v,int cantElem);
void ord_insercion(int* v,int cantElem);


#endif // ORDENAMIENTO_H_INCLUDED
