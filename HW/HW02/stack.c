#include"stack.h"

void CreatStack(Stack *ps) //to make top = -1
{
 ps->top=0;
}

void ClearStack(Stack *ps)
{
   ps->top=0;
}

void push(Stack *ps,StEntry e) //to increas top 1 then add e to orignal stack
{
 ps->entry[ps->top]=e;
 ps->top++;
}

int StackFull(Stack *ps)  // to check if top >= maxsize - 1 
{
  return ps->top==MaxEntry;
}

void pop(Stack *ps,StEntry *pe)// to make top refer to the index that top refer to it
{
  ps->top--;
  *pe=ps->entry[ps->top];
}

int StackEmpty(Stack *ps)//  to make sure if top >=0
{
 return !(ps->top);
}



StEntry StackTop (Stack *ps,StEntry *pe)//    to return element that top refer to it's index
{
  *pe=ps->entry[ps->top-1];
  return *pe;
}

int StackSize(Stack *ps)//  to return top+1
{
 return ps->top;
}

void TraseverStack(Stack *ps,void(*pf)(StEntry))
{
 for(int i=0;i<ps->top;i++)
 (*pf)(ps->entry[i]);
}
