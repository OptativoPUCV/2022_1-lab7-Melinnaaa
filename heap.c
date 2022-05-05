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
   
   if (pq->size != 0)
   {
      return pq->heapArray[0].data;
   }
   return NULL;
}

void swap (Heap* pq, int pos)
{
  heapElem* aux = (heapElem*) calloc (1, sizeof(heapElem*));
  while (pos >= 0)
   {
      //Swaps
      if (pq->heapArray[pos].priority > pq->heapArray[(pos-1)/2].priority)
      {
         aux->data = pq->heapArray[(pos-1)/2].data;
         aux->priority = pq->heapArray[(pos-1)/2].priority;
         pq->heapArray[(pos-1)/2] = pq->heapArray[pos]; 
         pq->heapArray[pos].data = aux->data;
         pq->heapArray[pos].priority = aux->priority;
         pos = (pos-1)/2;
      }
      else
      {
        return;
      }
   } 
}

void heap_push(Heap* pq, void* data, int priority)
{
   if (pq->capac == pq->size)
   {
      heapElem* tmpArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
      for (int i = 0 ; i < pq->size ; i = i + 1)
      {
        tmpArray[i] = pq->heapArray[i];    
      }
      pq->capac = (pq->capac * 2) + 1;
      pq->heapArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
      for (int i = 0 ; i < pq->size ; i = i + 1)
      {
        pq->heapArray[i] = tmpArray[i];    
      }
   }

   int pos = pq->size;
   pq->heapArray[pos].data = data;
   pq->heapArray[pos].priority = priority;
  
   swap(pq, pos);
   pq->size = pq->size + 1;
}

//Heap Pop tiene problemas
void heap_pop(Heap* pq)
{/*
   pq->size = pq->size - 1;
   pq->heapArray[0] = pq->heapArray[pq->size];
   heapElem* aux = (heapElem*) calloc (1, sizeof(heapElem*));
   int pos = 0;
   while (pos <= pq->size - 1)
   {
      //Swaps
      if (pq->heapArray[(2*pos)+1].priority > pq->heapArray[(2*pos)+2].priority)
      {
        if (pq->heapArray[(2*pos)+1].priority > pq->heapArray[pos].priority)
        {
         aux->data = pq->heapArray[(2*pos)+1].data;
         aux->priority = pq->heapArray[(2*pos)+1].priority;
         pq->heapArray[(2*pos)+1] = pq->heapArray[pos]; 
         pq->heapArray[pos].data = aux->data;
         pq->heapArray[pos].priority = aux->priority;
         pos = (2*pos)+1;
        }
      }
      else if (pq->heapArray[(2*pos)+1].priority < pq->heapArray[(2*pos)+2].priority)
      {
        if (pq->heapArray[0].priority < pq->heapArray[(2*pos)+2].priority)
        {
          aux->data = pq->heapArray[(2*pos)+2].data;
          aux->priority = pq->heapArray[(2*pos)+2].priority;
          pq->heapArray[(2*pos)+2] = pq->heapArray[pos]; 
          pq->heapArray[pos].data = aux->data;
          pq->heapArray[pos].priority = aux->priority;
          pos = (2*pos)+2;          
        }
      }
      else
      {
        return;
      }
      swap(pq, pos);
   }*/  
}

Heap* createHeap()
{
   Heap* pq = (Heap*) calloc (1, sizeof(Heap));
   pq->capac = 3;//Capacidad del HEAP
   pq->size = 0;// Total de elementos en el HEAP
   pq->heapArray = (heapElem*) calloc (pq->capac, sizeof(heapElem));
   return pq;
}