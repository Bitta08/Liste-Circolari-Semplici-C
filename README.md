# Libreria Liste Circolari in C

**Autore:** Mattia Bittante

**Versione:** 1.1

**Data:** 29/12/2025

**Linguaggio:** C (compatibile con C++)

**Compatibilità:** Windows / Linux / macOS

Una libreria semplice, didattica e completa per la gestione di **liste circolari semplicemente concatenate** in C.

**‼️La libreria è a solo scopo didattico e non è pensata per l'utilizzo professionale.**

---

## ❓Cos'è una lista circolare

Una lista circolare semplicemente concatenata è una struttura dati dinamica composta da una sequenza di nodi.
ogni nodo contiene:

* un **dato** di tipo intero
* il **puntatore** al nodo successivo

> ℹ️ Ogni nodo potrebbe in realtà avere infiniti dati di qualunque tipo, per semplificare gestiamo solo nodi con un singolo dato di tipo intero.

La proprietà fondamentale delle liste circolari è che l'ultimo nodo non punta a NULL, ma punta nuovamente al primo nodo della lista. **Ogni nodo vede quindi il nodo successivo** in un ciclo continuo.
La gestione ottimale di questa struttura avviene puntando all'ultimo elemento (coda), in modo da avere accesso immediato sia alla coda stessa che alla testa (`coda->next`).

## 📁 Struttura del progetto

Prima di tutto scarica i file `circularList.h` e `circularList.c` e assicurati di posizionarli **nella stessa directory** assieme ad un altro file C (o C++) che sarà il programma che andrà ad utilizzare la libreria: in questo caso `main.c`.

```txt
/Cartella
│
├── circularList.h    # Header della libreria
├── circularList.c    # Implementazione
└── main.c            # Esempio di utilizzo
```

---

## 🔧 Compilazione

### Compilazione con Visual Studio Code

Per compilare programmi C in Visual Studio Code servono **due cose:**

1. L’estensione ufficiale **C/C++ di Microsoft**
2. Un compilatore C installato sul sistema (ad esempio `gcc`)

#### 1️⃣ Scaricare l'estensione C/C++

Apri VSC vai su **Extensions** o premi `Ctrl + Shift + X`, cerca C/C++ e scarica l'estensione ufficiale **C/C++ di Microsoft.**

#### 2️⃣ Scaricare il compilatore C

Per compilare un codice C in VSC è necessario aver installato un compilatore come `gcc` (o `g++` per compilare anche in C++). se hai già programmi come **Dev-C++** dovresti trovare già entrambi nella cartella `bin` del programma, in alternativa puoi seguire [la guida ufficiale](https://code.visualstudio.com/docs/languages/cpp) per scaricare un compilatore adatto.

Una volta che hai scaricato il compilatore, vai sul terminale di VSC e lancia:

```bash
gcc --version
g++ --version
gdb --version

```

Se tutto funziona correttamente, non ti resta che aprire la cartella del progetto su VSC, scrivere il proprio programma nel file `main.c` e poi lanciare sul terminale:

```bash
gcc main.c circularList.c -o main.exe
.\main.exe

```

Se stai utlizzando Linux o macOS, assicurati di aggiungere -lm nella compilazione per collegare la libreria `math.h`, in questo modo:

```bash
gcc main.c circularList.c -o main -lm
./main

```

> ‼️Non compilare con il tasto Run di VSC in quanto compilerà solo il file `main.c` generando errori di linking.

### Compilazione con Dev-C++

Se usi Dev-C++, crea un progetto vuoto (`New` > `Progetto` > `Empty Project`) seleziona linguaggio e nome e salva.
A questo punto premi tasto destro sul progetto creato e seleziona `Aggiungi al Progetto` e apri i 2 file `circularList.h` e `circularList.c`.
Ora apri il file iniziale del progetto (solitamente `SenzaTitolo1.c`). Questo sarà il corrispondente di `main.c` , scrivi quindi il programma e premi `Compila & Esegui` o `F11` per compilare.

> ℹ️ Puoi anche eliminare il file `SenzaTitolo1.c` e aggiungere al progetto `main.c`

---

## 🔵 Esempio di main.c

```c
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

```

**Esempio output:**

```bash
originale:
[3] -> [7] -> [4] -> [8] -> [9] -> testa
aggiunta elementi:
[3] -> [7] -> [4] -> [8] -> [9] -> [3] -> testa
cancellazione elementi:
[3] -> [7] -> [4] -> [8] -> [3] -> testa
lista invertita:
[3] -> [8] -> [4] -> [7] -> [3] -> testa
lista ordinata:
[3] -> [3] -> [4] -> [7] -> [8] -> testa
Lunghezza: 5
Somma: 25
Min: 3
Max: 8
Media: 5.00
Mediana: 4.00

```

> ‼️Alcune funzione della libreria utilizzano `<limits.h>`, `<math.h>`, `<stdlib.h>`, assicurati di includerle nel tuo `main.c` per garantire l'autosufficienza del codice. Il programma compilerebbe anche senza, ma è buona pratica farlo.

---

## 📄 Documentazione delle funzioni

### Struttura del nodo

```c
// Struttura base del nodo
struct s_nodo 
{
  int dato; //dato del nodo
  struct s_nodo *next;  //puntatore al nodo successivo
};
typedef struct s_nodo nodo;
   
typedef nodo *lista;      // puntatore alla lista (alla sua coda)
typedef nodo *puntaNodo;  // puntatore a nodo specifico

```

La struttura `s_nodo` rappresenta l’elemento fondamentale della lista:
ogni nodo contiene un valore (`dato`) e un puntatore al nodo successivo (`*next`).

con `typedef struct s_nodo nodo` creo l'alias `nodo` per evitare di scrivere ogni volta `struct s_nodo`

Per leggibilità aggiungo inoltre due alias a `*nodo`:

* `lista` usato esclusivamente per indicare la coda della lista.
* `puntaNodo` usato per riferirsi a un nodo generico della lista.

> ℹ️ Nelle liste circolari, il tipo `lista` punta alla coda per permettere l'accesso in tempo costante sia alla fine che all'inizio della struttura (`coda->next`). Distinguerli semanticamente rende il codice più chiaro.

---

### `puntaNodo cl_creaNodo(int valore);`

Crea un nuovo nodo allocando memoria dinamicamente e gli assegna il valore specificato.

**Parametri:**

* **`int valore`**: Il dato intero da memorizzare nel nodo.

**Ritorno:**

* Il **puntatore** al nuovo nodo creato.
* **`NULL`** se non è stato possibile allocare la memoria (Heap overflow).

**Esempio di utilizzo:**

```c
puntaNodo nuovo = cl_creaNodo(5);
if (nuovo != NULL) {
    // utilizzo del nodo
}
```

**Note:**

* Per garantire la circolarità minima, il puntatore al nodo successivo (`next`) viene impostato a se stesso.
* Questa funzione è principalmente utilizzata internamente dalle funzioni di inserimento, ma può essere usata per creare nodi isolati circolari.

---

### `lista cl_aggiungiInTesta(lista coda, int valore);`

Crea un nuovo nodo e lo inserisce come primo elemento della lista (subito dopo la coda).

**Parametri:**

* **`lista coda`**: Il puntatore alla coda della lista.
* **`int valore`**: Il dato intero da memorizzare nel nodo.

**Ritorno:**

* Il **puntatore** alla coda della lista (che rimane invariato).
* La **coda originale** se malloc fallisce, senza apportare modifiche.

**Esempio di utilizzo:**

```c
lista miaLista = NULL;
miaLista = cl_aggiungiInTesta(miaLista, 6);
```

**Note:**

* Il nuovo nodo diventa l'elemento a cui punta `coda->next`.

---

### `lista cl_aggiungiInMezzo(lista coda, int valore, int pos);`

Inserisce un nuovo nodo in una posizione specifica della lista circolare. Se la posizione indicata supera la lunghezza della lista, il nodo viene inserito in coda.

**Parametri:**

* **`lista coda`**: La coda della lista in cui inserire il nodo.
* **`int valore`**: Il dato intero da memorizzare nel nodo.
* **`int pos`**: L'indice (base 0) dove inserire il nodo.

**Ritorno:**

* Il **puntatore** alla coda della lista (può cambiare se l'elemento viene inserito come nuova coda).
* La **coda originale** se `pos < 0` o se l'allocazione fallisce.

**Esempio di utilizzo:**

```c
miaLista = cl_aggiungiInMezzo(miaLista, 15, 2);
```

**Note:**

* Se `pos == 0`, richiama `cl_aggiungiInTesta`.
* Se `pos` è maggiore della lunghezza attuale, il nodo viene aggiunto come nuova coda aggiornando il puntatore principale.

---

### `lista cl_aggiungiInCoda(lista coda, int valore);`

Inserisce un nuovo nodo alla fine della lista circolare e sposta il puntatore `coda` sul nuovo elemento.

**Parametri:**

* **`lista coda`**: La coda a cui aggiungere il nodo.
* **`int valore`**: Il dato intero da memorizzare nel nodo.

**Ritorno:**

* Il **puntatore** alla nuova coda della lista (il nodo appena creato).

**Esempio di utilizzo:**

```c
miaLista = cl_aggiungiInCoda(miaLista, 42);
```

---

### `lista cl_riempiRnd(lista coda, int dim, int range, int min, int div);`

Aggiunge alla lista `dim` numeri casuali da `min` a `min + range`.

**Parametri:**

* **`int dim`**: Quantità di numeri da generare e aggiungere alla lista.
* **`int range`**: L'ampiezza dell'intervallo (quanti valori diversi sono possibili).
* **`int min`**: Il valore minimo possibile (il limite inferiore dell'intervallo).
* **`int div`**: Valore booleano:
* **`1`**: Forza la generazione di numeri univoci.
* **`0`**: Permette la generazione di numeri duplicati.

**Ritorno:**

* Il **puntatore** alla coda della lista.

**Esempio di utilizzo:**

```c
miaLista = cl_riempiRnd(miaLista, 5, 10, 1, 1);
cl_stampaLista(miaLista);
// es. di output (5 numeri da 1 a 10 tutti diversi)
[6] -> [8] -> [2] -> [4] -> [5] -> testa
```

**Note:**

* Se `div = 1`, la funzione utilizza `cl_datoIncluso`, il quale scorre l'intera lista circolare per ogni nuovo numero.
* I numeri generati vengono inseriti nella lista tramite `cl_aggiungiInCoda`.
* Se non esistono abbastanza numeri univoci, vengono inseriti finché disponibili, poi vengono accettati duplicati.

---

### `void cl_stampaLista(lista coda);`

Stampa a video il contenuto della lista nel formato `[dato] -> [dato] -> testa`.

**Parametri:**

* **`lista coda`**: La coda della lista da stampare.

**Esempio di utilizzo:**

```c
cl_stampaLista(miaLista); // Output: [10] -> [20] -> testa
```

---

### `lista cl_delLista(lista coda);`

Elimina l'intera lista circolare deallocando la memoria di ogni singolo nodo.

**Parametri:**

* **`lista coda`**: La coda della lista da eliminare.

**Ritorno:**

* Sempre **`NULL`**, per indicare che la lista è ora vuota.

**Esempio di utilizzo:**

```c
miaLista = cl_delLista(miaLista);
```

**Note:**

* Rompe internamente la circolarità per evitare cicli infiniti durante la `free()`. È fondamentale per prevenire memory leak.

---

### `lista cl_delTesta(lista coda);`

Rimuove l'elemento subito dopo la coda (la testa).

**Parametri:**

* **`lista coda`**: La coda della lista.

**Ritorno:**

* Il **puntatore** alla coda della lista.
* **`NULL`** se la lista conteneva un solo elemento o era già vuota.

**Esempio di utilizzo:**

```c
miaLista = cl_delTesta(miaLista);
```

---

### `lista cl_delCoda(lista coda);`

Rimuove l'ultimo elemento della lista (la coda).

**Parametri:**

* **`lista coda`**: La coda da eliminare.

**Ritorno:**

* Il **puntatore** alla nuova coda della lista (il penultimo elemento).
* **`NULL`** se la lista conteneva un solo elemento che è stato eliminato.

**Esempio di utilizzo:**

```c
miaLista = cl_delCoda(miaLista);
```

**Note:**

* Richiede uno scorrimento completo della lista per individuare il penultimo nodo.

---

### `lista cl_delEleLista(lista coda, int pos);`

Elimina un nodo in una posizione specifica della lista circolare.

**Parametri:**

* **`lista coda`**: La coda da cui eliminare il nodo.
* **`int pos`**: L'indice (base 0) del nodo da rimuovere.

**Ritorno:**

* Il **puntatore** alla coda della lista aggiornata.
* La **coda originale** se `pos < 0` o se la posizione indicata è fuori dai limiti.

**Esempio di utilizzo:**

```c
miaLista = cl_delEleLista(miaLista, 3);
```

**Note:**

* Se `pos == 0`, la funzione richiama internamente `cl_delTesta`.
* Se viene eliminato l'ultimo elemento, il puntatore `coda` viene correttamente aggiornato.

---

### `int cl_nodoIncluso(lista coda, puntaNodo A);`

Verifica se un determinato nodo appartiene alla lista circolare specificata.

**Parametri:**

* **`lista coda`**: La coda della lista in cui cercare.
* **`puntaNodo A`**: Il puntatore al nodo da cercare.

**Ritorno:**

* **`1`**: Se il nodo è presente nella lista.
* **`0`**: Se il nodo non è presente o la lista è vuota.

**Esempio di utilizzo:**

```c
isIncluded = cl_nodoIncluso(miaLista, A);
if(isIncluded) printf("A è presente nella lista");
```

---

### `int cl_datoIncluso(lista coda, int valore);`

Verifica se un determinato valore è presente nella lista circolare.

**Parametri:**

* **`lista coda`**: La coda della lista in cui cercare.
* **`int valore`**: Il valore del dato da cercare.

**Ritorno:**

* **`1`**: Se il valore è già presente nella lista.
* **`0`**: Se il valore non è presente o la lista è vuota.

**Esempio di utilizzo:**

```c
isIncluded = cl_datoIncluso(miaLista, 7);
```

---

### `int cl_isVuota(lista testa);`

Verifica se una lista è vuota.

**Parametri:**

* **`lista testa`**: la lista da verificare

**Ritorno:**

* **`1`**: Se la lista è vuota.
* **`0`**: Se la lista non è vuota.

**Esempio di utilizzo:**

```c
if(cl_isVuota(miaLista)) printf("lista vuota");
```

---

### `int cl_posizione(lista testa, int valore);`

Restituisce la posizione della prima occorrenza del valore dato.

**Parametri:**

* **`lista testa`**: la lista dove cercare.
* **`int valore`**: il numero da cercare.

**Ritorno:**

* la **posizione** del valore nella lista.
* **`-1`**: Se il valore non è presente nella lista.
* **`-2`**: Se la lista è vuota.

**Esempio di utilizzo:**

```c
int pos = cl_posizione(miaLIsta,3);
printf("3 è il %d della lista",pos+1);
```

---

### `void cl_swapDato(lista coda, puntaNodo A, puntaNodo B);`

Scambia i valori contenuti in due nodi appartenenti alla stessa lista circolare.

**Parametri:**

* **`lista coda`**: La coda contenente i nodi.
* **`puntaNodo A`**: Puntatore al primo nodo.
* **`puntaNodo B`**: Puntatore al secondo nodo.

**Esempio di utilizzo:**

```c
cl_swapDato(miaLista, A, B);
```

**Note:**

* La funzione verifica l'appartenenza di entrambi i nodi alla lista circolare tramite `cl_nodoIncluso` prima di procedere.

---

### `lista cl_bubbleSortLista(lista coda);`

Ordina la lista circolare in modo crescente utilizzando l'algoritmo Bubble Sort tramite lo scambio dei dati.

**Parametri:**

* **`lista coda`**: La coda della lista da ordinare.

**Ritorno:**

* Il **puntatore** alla coda della lista ordinata.

**Esempio di utilizzo:**

```c
listaOrdinata = cl_bubbleSortLista(listaOrdinata);
```

---

### `lista cl_fondiListe(lista L1, lista L2);`

Crea una nuova lista circolare che è la concatenazione di due liste circolari esistenti. Crea una copia profonda senza modificare gli originali.

**Parametri:**

* **`lista L1`**: La prima lista da copiare.
* **`lista L2`**: La seconda lista i cui elementi seguiranno quelli di `L1`.

**Ritorno:**

* Il puntatore alla coda della nuova lista creata.
* `NULL` se entrambe le liste sono vuote.

**Esempio di utilizzo:**

```c
listaUnita = cl_fondiListe(listaA, listaB);
```

**Note:**

* Alloca nuova memoria per ogni nodo. L'utente deve gestire la deallocazione della lista risultante.

---

### `lista cl_copiaLista(lista coda);`

Crea una copia indipendente (deep copy) dell'intera lista circolare.

**Parametri:**

* **`lista coda`**: La lista originale da duplicare.

**Ritorno:**

* Il **puntatore** alla coda della nuova lista creata.
* **`NULL`** se la lista originale è vuota.

**Esempio di utilizzo:**

```c
miaCopia = cl_copiaLista(listaOriginale);
```

**Note:**

* Le modifiche alla copia non influenzano la lista originale. Utilizza internamente `cl_aggiungiInCoda`.

---

### `lista cl_invertiLista(lista coda);`

Crea una nuova lista circolare che contiene gli stessi elementi della lista originale, ma in ordine invertito.

**Parametri:**

* **`lista coda`**: La lista originale da invertire.

**Ritorno:**

* **`lista`**: Il puntatore alla coda della nuova lista invertita.
* **`NULL`**: Se la lista originale è vuota.

**Esempio di utilizzo:**

```c
listaSpeculare = cl_invertiLista(miaLista);
```

**Note:**

* Alloca nuova memoria. La lista risultante deve essere liberata tramite `cl_delLista`.

---

### `int cl_ripetizioni(lista coda, int valore);`

Conta quante volte un determinato valore compare nella lista circolare.

**Parametri:**

* **`lista coda`**: La coda della lista.
* **`int valore`**: Il valore da cercare.

**Ritorno:**

* Il numero di occorrenze del valore.

```c
rip = cl_ripetizioni(miaLista,3);
printf("Nella lista 3 è ripetuto %d volte",rip);
```

---

### `int cl_modaLista(lista coda);`

Individua il valore che compare più frequentemente nella lista circolare.

**Parametri:**

* **`lista coda`**: La lista da analizzare.

**Ritorno:**

* Il **valore** più frequente.
* **`INT_MIN`** se la lista è vuota.

**Esempio di utilizzo:**

```c
moda = cl_modaLista(miaLista);
```

---

### `int cl_lenLista(lista coda);`

Calcola il numero di elementi (nodi) presenti nella lista circolare effettuando un ciclo completo.

**Parametri:**

* **`lista coda`**: La lista da misurare.

**Ritorno:**

* Il numero intero di nodi.

```c
len = cl_lenLista(miaLista);
printf("la lista è composta da %d nodi",len);
```

---

### `int cl_sommaLista(lista coda);`

Calcola la somma algebrica di tutti i valori contenuti nella lista circolare.

**Parametri:**

* **`lista coda`**: La lista da sommare.

**Ritorno:**

* La somma totale dei dati.

**Esempio di utilizzo:**

```c
somma = cl_sommaLista(miaLista);
printf("Il totale della lista è %d",somma);
```

---

### `int cl_maxLista(lista coda);`

Trova il valore massimo contenuto nella lista circolare.

**Parametri:**

* **`lista coda`**: La coda da analizzare.

**Ritorno:**

* Il valore massimo.
* **`INT_MIN`** se la lista è vuota.

**Esempio di utilizzo:**

```c
max = cl_maxLista(miaLista);
printf("il valore maggiore nella lista è %d",max);
```

---

### `int cl_minLista(lista coda);`

Trova il valore minimo contenuto nella lista circolare.

**Parametri:**

* **`lista coda`**: La coda da analizzare.

**Ritorno:**

* Il valore minimo.
* **`INT_MAX`** se la lista è vuota.

**Esempio di utilizzo:**

```c
min = cl_minLista(miaLista);
printf("il valore minore nella lista è %d",min);
```

---

### `float cl_medLista(lista coda);`

Calcola la media aritmetica dei valori nella lista circolare.

**Parametri:**

* **`lista coda`**: La coda da analizzare.

**Ritorno:**

* Valore **`float`** della media.
* **`NAN`** se la lista è vuota.

**Esempio di utilizzo:**

```c
med = cl_medLista(miaLista);
printf("il valore medio nella lista è %.2f",med);
```

---

### `float cl_medianaLista(lista coda);`

Calcola la mediana dei valori contenuti nella lista circolare senza alterare l'ordine originale.

**Parametri:**

* **`lista coda`**: La lista da analizzare.

**Ritorno:**

* Il valore **mediano** (tipo `float`).
* **`NAN`** se la lista è vuota.

**Esempio di utilizzo:**

```c
float m = cl_medianaLista(miaLista);
if(!isnan(m)) printf("La mediana è: %.2f", m);
```

**Note:**

* Crea internamente una copia tramite `cl_copiaLista`, la ordina, calcola la mediana e dealloca la copia prima di restituire il risultato.
* Gestisce correttamente sia liste con numero di elementi pari che dispari.
