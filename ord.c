#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ord.h"

//FUNCIONES INTERNAS DE ORDENAMIENTO.C
void* buscar_menor(void* desde ,void* hasta ,int tamElem, Cmp cmp);
void intercambiar(void* a, void* b, int tamElem);
int cmp(const void* e1, const void* e2);

/*void ord_burbujeo(int* v,int cantElem)
{
    int i=1,j;
    int huboIntercambios=1;

        while(huboIntercambios && i<cantElem)
        {
            huboIntercambios=0;
                for(j=0;j<cantElem-i;j++)
                {
                    if(v[j] > v[j+1])
                    {
                        intercambiar (&v[j],&v[j+1]);
                        huboIntercambios=1;
                    }
                }

                i++;
        }

}
*/

void ord_seleccion(void* v, int cantElem, int tamElem, Cmp cmp)
{
    void* m;
    void* ult = v + (cantElem - 1)* tamElem; //LO MULTIPLICO POR EL TAMAÑO DEL ELEMENTO, PERO AL SER VOID PIERDO ESE DATO. HAY QUE ENVIARLO POR PARAMETRO.

        for(void* i = v; i < ult; i + tamElem)
        {
            m = buscar_menor(i, ult, tamElem, cmp);

            if(m != i) //SE SIGUE COMPARANDO DIRECCIONES DE MEMORIA
                intercambiar(m, i);
        }
}

void ord_insercion(int* v,int cantElem)
{
    int* j;
    int* elemAIns;
    int* ult= v + cantElem-1;

        for(int* i=v;i<ult;i++)
        {
            elemAIns=i;
            j=i-1;
                while(j>=0 && elemAIns < j)
                {
                    j=j-1;
                    j--;
                }

            j=elemAIns-1;
        }
}

void intercambiar(void* a, void* b, int tamElem)
{
    char aux[tamElem];

    memcpy(aux, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, aux, tamElem);

}

void* buscar_menor(void *desde, void *hasta, int tamElem, Cmp cmp)
{
    void* m = desde;

        for(void* j = desde + tamElem; j <= hasta; j + tamElem)
        {
            if(cpm (j, m) < 0) //LE CAMBIO TEMPORALMENTE EL TIPO DE VARIABLE AL QUE APUNTA EL PUNTERO. DE VOID A INT.(CAST).
                m = j;
        }

        return m;
}

void mostrar_vec(void* v,int cantElem, int tamElem, Mostrar mostrar)
{
    void* ult= v + (cantElem - 1) - tamElem ;

    for(void* i = v; i <= ult; i += tamElem)
       {
        mostrar(i);
        putc("\n", stdout); //Stdout es el puntero a file que apunta a la pantalla.
       }
}

void inicializa_VecRandom(int* v, int cantElem)
{
    int* ult= v + cantElem-1;
        srand(time(NULL));
        for(int* i=v; i<=ult; i++)
            *i=srand;
}
