// Mattia Bittante - 29/12/2025 - version 1.1 - italian

#include "circularList.h"

puntaNodo cl_creaNodo(int valore)
{
  puntaNodo n = (puntaNodo)malloc(sizeof(nodo)); //cast per compatibilita con C++
  if (n == NULL) return NULL;
  n->dato=valore;
  n->next=n;
  return n;
}

lista cl_aggiungiInTesta(lista coda, int valore)
{
  puntaNodo n = cl_creaNodo(valore);
  if(n==NULL) return coda;
  if(coda == NULL) return n;

  n->next = coda->next;
  coda->next = n;
  return coda;
}

lista cl_aggiungiInMezzo(lista coda, int valore, int pos)
{
    int i;
    if (pos < 0) return coda;
    if (coda == NULL || pos == 0) return cl_aggiungiInTesta(coda, valore);

    puntaNodo n = cl_creaNodo(valore);
    if (n == NULL) return coda;

    puntaNodo corrente = coda->next;
    
    for (i=0; i<pos-1; i++) 
    {
        corrente = corrente->next;
        if (corrente == coda->next) break; //controllo se si è effettuato un giro completo
    }

    n->next = corrente->next;
    corrente->next = n;

    if (corrente == coda) //se pos è dopo la lista aggiungo in coda
    {
      return n; 
    }

    return coda;
}

lista cl_aggiungiInCoda(lista coda, int valore)
{
  puntaNodo n = cl_creaNodo(valore);
  if(n==NULL) return coda;
  if(coda == NULL) return n;

  n->next = coda->next;
  coda->next = n;
  return n;
}

lista cl_riempiRnd(lista coda, int dim, int range, int min, int div)
{
    int i, r, v;
    int valoriOccupati = 0; //valori del range già presenti nella lista

    if (div == 1) 
    {
        for (v=min; v<min+range; v++) 
        {
            if (cl_datoIncluso(coda, v)) valoriOccupati++;
        }
    }

    for (i = 0; i < dim; i++) 
    {
        if (div == 1 && valoriOccupati < range) //finché c'è spazio lo genera diverso, poi lo genera con ripetizioni
        {
            do 
            {
                r = (rand() % range) + min;
            }while(cl_datoIncluso(coda, r) == 1);
            valoriOccupati++; 
        } 
        else r = (rand() % range) + min;
        coda = cl_aggiungiInCoda(coda, r);
    }
    return coda;
}

void cl_stampaLista(lista coda)
{
  if (coda == NULL) 
  {
    printf("NULL\n");
    return;
  }

  puntaNodo corrente = coda->next;
  do
  {
    printf("[%d] -> ",corrente->dato);
    corrente = corrente->next;
  }while(corrente != coda->next);

  printf("testa\n");
}

lista cl_delLista(lista coda)
{
if(coda == NULL) return NULL;

  puntaNodo corrente = coda->next;
  puntaNodo testa = coda->next; //salvo la testa per il controllo nel do-while
  puntaNodo temp;

  do
  {
    temp = corrente;
    corrente = corrente->next;
    free(temp);
  }while(corrente != testa);
  
  return NULL;
}


lista cl_delTesta(lista coda)
{
  if(coda == NULL) return NULL; // 0 elementi
  puntaNodo del = coda->next;
  if(del == coda) // 1 elemento
  {
    free(del);
    return NULL;
  }
  coda->next = del->next;
  free(del);

  return coda;
}

lista cl_delCoda(lista coda)
{
  if(coda == NULL) return NULL; //0 elementi
  if(coda == coda->next) // 1 elemento
  {
    free(coda);
    return NULL;
  }
  puntaNodo corrente = coda->next;
  while(corrente->next != coda)
  {
    corrente = corrente->next;
  }
  corrente->next = coda->next;
  free(coda);

  return corrente;
}

lista cl_delEleLista(lista coda, int pos)
{
  int i;
  
  if(pos<0 || coda == NULL) return coda;

  if(pos == 0) return cl_delTesta(coda); 

  puntaNodo corrente = coda->next;

  for(i=0; i<pos-1; i++) //verifica che pos non sia > della dimesione della lista, se lo è ritorna coda
  {
    corrente = corrente->next;
    if(corrente == coda) return coda;
  }

  puntaNodo daEliminare = corrente->next; 
  if(daEliminare == coda) return cl_delCoda(coda);

  corrente->next = daEliminare->next;
  free(daEliminare);

  return coda;
}

int cl_nodoIncluso(lista coda, puntaNodo A)
{
  if (coda == NULL || A == NULL) return 0;
  puntaNodo corrente = coda->next;

  do
  {
    if(A == corrente) return 1;
    corrente = corrente->next;
  } while (corrente != coda->next);

  return 0;
}

int cl_datoIncluso(lista coda, int valore)
{
  if(coda == NULL) return 0;
  puntaNodo corrente = coda->next;
  
  do
  {
    if(corrente->dato==valore) return 1;
    corrente=corrente->next;
  }while(corrente != coda->next);
  
  return 0;
}

int cl_isVuota(lista coda)
{
  if(coda == NULL) return 1;
  else return 0;
}

int cl_posizione(lista coda, int valore)
{
  if(coda == NULL) return -2;
  puntaNodo corrente = coda->next;
  int pos=0;

  do
  {
    if(corrente->dato == valore) return pos;
    corrente = corrente->next;
    pos++;
  }while(corrente != coda->next);

  return -1;
}

void cl_swapDato(lista coda, puntaNodo A, puntaNodo B)
{
  if(cl_nodoIncluso(coda,A) == 0 || cl_nodoIncluso(coda,B) == 0) return;
  int temp = 0;
  temp = A->dato;
  A->dato = B->dato;
  B->dato = temp;
}

lista cl_bubbleSortLista(lista coda)
{
  if (coda == NULL) return coda;
  int scambiato;
  do 
  {
    scambiato = 0;
    puntaNodo corrente = coda->next;

    do
    {
      if (corrente->dato > corrente->next->dato)
      {
        cl_swapDato(coda, corrente, corrente->next);
        scambiato = 1;
      }
      corrente = corrente->next;
    } while (corrente != coda);
  }while(scambiato);

  return coda;
}

lista cl_copiaLista(lista coda)
{
  if(coda == NULL) return NULL;
  lista copia = NULL;
  puntaNodo corrente = coda->next;

  do
  {
    copia = cl_aggiungiInCoda(copia,corrente->dato);
    corrente = corrente->next;
  } while (corrente != coda->next);

  return copia;
}

lista cl_fondiListe(lista L1, lista L2)
{
  if (L1 == NULL && L2 == NULL) return NULL;
  if (L1 == NULL) return cl_copiaLista(L2);
  if (L2 == NULL) return cl_copiaLista(L1);

  lista nuovaLista = cl_copiaLista(L1);
  puntaNodo corrente = L2->next;

  do
  {
    nuovaLista = cl_aggiungiInCoda(nuovaLista, corrente->dato);
    corrente = corrente->next;
  } while (corrente != L2->next);

  return nuovaLista;
}

lista cl_invertiLista(lista coda)
{
  if(coda == NULL) return NULL;
  puntaNodo corrente = coda->next;
  lista listaInvertita = NULL;
  
  do
  {
    listaInvertita = cl_aggiungiInTesta(listaInvertita,corrente->dato);
    corrente = corrente->next;
  } while (corrente != coda->next);

  return listaInvertita;
}

int cl_ripetizioni(lista coda, int valore)
{
  if(coda == NULL) return 0;
  int rip = 0;
  puntaNodo corrente = coda->next;

  do
  {
    if(corrente->dato == valore) rip++;
    corrente = corrente->next;
  } while (corrente != coda->next);
  
  return rip;
}

int cl_modaLista(lista coda)
{
  if(coda == NULL) return INT_MIN;
  puntaNodo corrente = coda->next;
  int rip = 0;
  int maxRip = cl_ripetizioni(coda,corrente->dato);
  int valoreMax = corrente->dato;

  do
  {
    rip = cl_ripetizioni(coda,corrente->dato);
    if(rip>maxRip) 
    {
      maxRip = rip;
      valoreMax = corrente->dato; 
    }
    corrente=corrente->next;
  } while (corrente != coda->next);
  
  return valoreMax;
}

int cl_lenLista(lista coda)
{
  if(coda == NULL) return 0;
  puntaNodo corrente = coda->next;
  int len = 0;

  do
  {
      len++;
      corrente = corrente->next;
  } while (corrente != coda->next);

  return len;
}

int cl_sommaLista(lista coda)
{
  if(coda == NULL) return 0;
  puntaNodo corrente = coda->next;
  int somma = 0;

  do
  {
    somma += corrente->dato;
    corrente = corrente->next;
  } while (corrente != coda->next);
  
  return somma;
}

int cl_maxLista(lista coda)
{
  if (coda == NULL) return INT_MIN;
  int max = coda->next->dato;
  puntaNodo corrente = coda->next;

  do
  {
    if(corrente->dato > max) max = corrente->dato;
    corrente = corrente->next;
  }while(corrente != coda->next);
  
  return max;  
}

int cl_minLista(lista coda)
{
  if (coda == NULL) return INT_MAX;
  int min = coda->next->dato;
  puntaNodo corrente = coda->next;

  do
  {
    if(corrente->dato < min) min = corrente->dato;
    corrente = corrente->next;
  } while (corrente != coda->next);

  return min;  
}

float cl_medLista(lista coda)
{
  int somma = cl_sommaLista(coda);
  int len = cl_lenLista(coda);
  if(len == 0) return NAN;
  return(float)somma / len; 
}

float cl_medianaLista(lista coda)
{
  if(coda == NULL) return NAN;
  int i;
  float risultato;
  int len = cl_lenLista(coda);
  if(len == 0) return NAN;

  //eseguo una copia della lista per non ordinare quella originale.
  lista copia = NULL;
  copia = cl_copiaLista(coda);
  copia = cl_bubbleSortLista(copia);
  
  puntaNodo corrente = copia->next;

  if(len%2==1)
  {
    for(i=0; i<len/2; i++)
      corrente = corrente->next;  
    risultato = (float)corrente->dato;
  }
  else if(len%2==0)
  {
    for(i=0; i<(len/2)-1; i++)
      corrente = corrente->next;
    risultato = (float)(corrente->dato + corrente->next->dato) / 2;
  }
  copia = cl_delLista(copia);
  return risultato;
}