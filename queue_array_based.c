#include<stdio.h>
#define QEntery int
#define MAX 1000000000

typedef struct queue
{
 int front;
 int rear;
 QEntery qarry[MAX] ;
 int size;
}Queue;

void CreatQueue(Queue *pq)
{
  pq->front=0;
  pq->rear=-1;
  pq->size=0;
}

void Append(Queue *pq,QEntery e)
{
  pq->rear=(pq->rear+1)%MAX;
  pq->qarry[pq->rear]=e;
}

void rever(Queue *pq,QEntery *pe)
{
  *pe=pq->qarry[pq->front];
  pq->front=(pq->front+1)%MAX;
}

int Size(Queue *pq)
{
  return pq->size;
}

void ClearQueue(Queue *pq)
{
  pq->front=0;
  pq->rear=-1;
  pq->size=0;
}

void Travese(Queue *pq,void(*pf)(QEntery))
{

  for(int s=0,pos=pq->front;s<=pq->size;s++)
  {
    (*pf)(pq->qarry[pos]);
    pos=(pos+1)%MAX;
  }
  
}



