// Mattia Bittante - 29/12/2025 - version 1.1 - italian

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

// Struttura base del nodo
struct s_nodo 
{
  int dato;
  struct s_nodo *next;
};
typedef struct s_nodo nodo;
   
typedef nodo *lista;      // puntatore alla lista (alla sua coda)
typedef nodo *puntaNodo;  // puntatore a nodo specifico

// Prototipi
puntaNodo cl_creaNodo(int valore);
lista cl_aggiungiInTesta(lista coda, int valore);
lista cl_aggiungiInMezzo(lista coda, int valore, int pos);
lista cl_aggiungiInCoda(lista coda, int valore);
lista cl_riempiRnd(lista coda, int dim, int range, int min, int div);
void cl_stampaLista(lista coda);
lista cl_delLista(lista coda);
lista cl_delTesta(lista coda);
lista cl_delCoda(lista coda);
lista cl_delEleLista(lista coda, int pos);
int cl_nodoIncluso(lista coda, puntaNodo A);
int cl_datoIncluso(lista coda, int valore);
int cl_isVuota(lista coda);
int cl_posizione(lista coda, int valore);
void cl_swapDato(lista coda, puntaNodo A, puntaNodo B);
lista cl_bubbleSortLista(lista coda);
lista cl_copiaLista(lista coda);
lista cl_fondiListe(lista L1, lista L2);
lista cl_invertiLista(lista coda);
int cl_ripetizioni(lista coda, int valore);
int cl_modaLista(lista coda);
int cl_lenLista(lista coda);
int cl_sommaLista(lista coda);
int cl_maxLista(lista coda);
int cl_minLista(lista coda);
float cl_medLista(lista coda);
float cl_medianaLista(lista coda);
#endif