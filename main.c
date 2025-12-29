#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include "circularList.h"

int main() {
    srand(time(NULL));
    lista l = NULL;
    
    printf("originale:\n");
    l = cl_riempiRnd(l,5,10,1,1);
    cl_stampaLista(l);

    printf("aggiunta elementi:\n");
    l = cl_aggiungiInMezzo(l, 3, 5);
    cl_stampaLista(l);
    
    printf("cancellazione elementi:\n");
    l= cl_delEleLista(l,4);
    cl_stampaLista(l);
    printf("lista invertita:\n");
    l = cl_invertiLista(l);
    cl_stampaLista(l);
    printf("lista ordinata:\n");
    l = cl_bubbleSortLista(l);
    cl_stampaLista(l);

    printf("Lunghezza: %d\n", cl_lenLista(l));
    printf("Somma: %d\n", cl_sommaLista(l));
    printf("Min: %d\n", cl_minLista(l));
    printf("Max: %d\n", cl_maxLista(l));
    printf("Media: %.2f\n", cl_medLista(l));
    printf("Mediana: %.2f\n", cl_medianaLista(l));
    return 0;
}