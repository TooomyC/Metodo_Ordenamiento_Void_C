#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ord.h"

#define TAM_VEC 1000
#define TAM_VEC_ALU 8

typedef struct
{
    int legajo;
    char apyn[1010];
    int cantMatAprob;
} Alumno;


int cmpInt(const void* e1, const void* e2);
int cmpIntDesc(const void* e1, const void* e2);
void mostrarInt(const void* e);
int cmpAlu(const void* e1, const void* e2);
int cmpAluApyn(const void* e1, const void* e2);
void mostrarAlu(const void* e);

int main()
{
    int v[TAM_VEC]; //= {9, 5, 8, 2, 12, 3, 1, 4};
    inicializa_VecRandom(v,TAM_VEC);

    puts("Antes de ordenar");
    mostrar_vec(v, TAM_VEC, sizeof(int), mostrarAlu);

    long segIni= time(NULL);

    puts("ASC");
    ord_seleccion(v, TAM_VEC, sizeof(int), cmpInt);
    puts("Ordenado");
    mostrar_vec(v, TAM_VEC, sizeof(int), mostrarInt);

/*  ord_burbujeo(v, TAM_VEC);
    printf("\nOrdenamiento por Burbujeo");
    mostrar_vec(v, TAM_VEC);
*/

    puts("DESC");
    ord_seleccion(v, TAM_VEC, sizeof(int), cmpIntDesc);

    long segFin= time(NULL);

    long tiempoEjec= segFin - segIni;

    printf("\n\nOrdenamiento (por Seleccion)");
    mostrar_vec(v, TAM_VEC, sizeof(int), mostrarAlu);

    printf("\n\nTiempo de Ejecucion: %ld",tiempoEjec);


    /*ord_insercion(v, TAM_VEC);
    printf("\n\nOrdenamiento por Insercion");
    mostrar_vec(v, TAM_VEC);*/


    Alumno vecAlu[TAM_VEC_ALU] =
    {
        {432,"Perez, Juan",23}, {123,"Rodriguez, Ariel", 12}, {247,"Bermudez, Alejandro", 2}, {564,"Alvarez, Alberto", 20},
        {999,"Casares, Carlos", 40}, {444,"Damasco, Daniel", 30}, {111, "Garcia, Gabriel", 11}, {333,"Fernandez, Alberto", 1}
    };

    ord_seleccion(vecAlu, TAM_VEC_ALU, sizeof(Alumno), cmpAlu);
    mostrar_vec(vecAlu, TAM_VEC_ALU, sizeof(Alumno), mostrarAlu);

    putc("\n", stdout);

    ord_seleccion(vecAlu, TAM_VEC_ALU, sizeof(Alumno), cmpAluApyn);
    mostrar_vec(vecAlu, TAM_VEC_ALU, sizeof(Alumno), mostrarAlu);

    return 0;
}

int cmpInt(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int cmpIntDesc(const void* e1, const void* e2)
{
    return *(int*)e2 - *(int*)e1;
}

int cmpAlu(const void* e1, const void* e2)
{
    Alumno* alu1 = (Alumno*)e1;
    Alumno* alu2 = (Alumno*)e2;

    return alu1->legajo - alu2->legajo;
}

int cmpAluApyn(const void* e1, const void* e2)
{
    Alumno* alu1 = (Alumno*)e1;
    Alumno* alu2 = (Alumno*)e2;

    return strcmp(alu1->apyn - alu2->apyn);
}

void mostrarAlu(const void* e)
{
    Alumno* alu = (Alumno*)e;

    printf("%d, %s, %d", alu->legajo, alu->apyn, alu->cantMatAprob);
}

void mostrarInt(const void* e)
{
    printf("%d", *(int*)e);
}
