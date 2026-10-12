#include<stdio.h>
#include<stdlib.h>
#define Qentery int
typedef struct queuenode
{
 struct  queuenode *next;
 Qentery e;
}Qnode;

typedef struct queue
{
  Qnode *front;
  Qnode *rear;
  int size;
}Queue;

void CreatQueue(Queue *pq)
{
 pq->front=NULL;
 pq->rear=NULL;
 pq->size=0;
}

int Append(Queue *pq,Qentery e)
{
 Qnode *pn=(Qnode*)malloc(sizeof(Qnode));
 if(!pn)
 return 0;
 pn->e=e;
 pn->next=NULL;
 if(!pq->front)
 pq->front=pn;
 else
 pq->rear->next=pn;
 pq->rear=pn;
 pq->size++;
 return 1;
}

void serve(Queue *pq,Qentery *pe)
{
 Qnode *pn=pq->front;
 *pe=pn->e;
 pq->front=pq->front->next;
 if(!pq->front)
 pq->rear=NULL;
 free(pn);
 pq->size--;
}

int Size(Queue *pq)
{
  return pq->size;
}

void ClearQueue(Queue *pq)
{
 Qnode *pn;
 while(pq->front)
 {
  pq->rear=pq->front->next;
  pn=pq->front;
  pq->front=pq->front->next;
  free(pn);
 }
 pq->size=0;
}

void TravesQueue(Queue*pq,void(*pf)(Qentery))
{
 Qnode *pin=pq->front;
 for(;pin;pin=pin->next)
 (*pf)(pin->e);
}

int main()
{
                  
}