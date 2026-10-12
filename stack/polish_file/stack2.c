#include"stack2.h"


void CreatStack(Stack *ps) {
 ps->top=NULL;
 ps->size=0;
}

void push(Stack*ps,Stentry e) {
 Stacknod *pn =(Stacknod*)malloc(sizeof(Stacknod));
 pn->e=e;
 pn->next=ps->top;
 ps->top=pn;
 ps->size++;
}

int StackFull(Stack*ps) {
  return 0;
}

void pop(Stack*ps,Stentry*pe) {
  Stacknod *pn;
  *pe=ps->top->e;
  pn=ps->top;
  ps->top=ps->top->next;
  free(pn);
  ps->size--;
}

int StackEmpty(Stack*ps) {
 return ps->top==NULL;
}

void ClearStack(Stack *ps) {
 Stacknod *pn=ps->top;//to make pn point first Stacknod that have entry and next pointer
 while(pn) {
  pn=pn->next;
  free(ps->top);
  ps->top=pn;
 }
 ps->size=0;
}

void TraseverStack(Stack*ps,void(*pf)(Stentry)) {
  for(Stacknod *pn=ps->top;pn;pn=pn->next)
  (*pf)(pn->e);
}


int StackSize(Stack*ps) {
 return ps->size;
}

Stentry StackTop(Stack *ps,Stentry *pe) {
  *pe=ps->top->e;
  return *pe;
}