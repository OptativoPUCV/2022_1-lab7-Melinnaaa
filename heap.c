#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
   if (pq == NULL || pq->heapArray == NULL) return NULL;
   
   if (pq->heapArray[0].data != NULL)
   {
      return pq->heapArray[0].data != NULL;
   }
   return NULL;
}



void heap_push(Heap* pq, void* data, int priority)
{

}


void heap_pop(Heap* pq)
{

}

Heap* createHeap()
{
   Heap* pq = (Heap*) calloc (1, sizeof(Heap));
   pq->capac = 10;//Capacidad del HEAP
   pq->size = 0;// Total de elementos en el HEAP
   pq->heapArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
   return pq;
}
