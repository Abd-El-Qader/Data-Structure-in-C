#include <stdio.h>
// note we can`t difine StackEntery
typedef struct stack {
  int top;
  int entry[__INT16_MAX__];
} Stack;

void creatstack(Stack *ps) // to make top = -1
{
  ps->top = -1;
}

void push(int e, Stack *ps) // to increas top 1 then add e to orignal stack
{
  ps->top++;
  ps->entry[ps->top] = e;
}

int StachFull(Stack *ps) // to check if top >= maxsize - 1
{
  return ps->top >= __INT16_MAX__ - 1;
}

void pop(int *pe,
         Stack *ps) // to make top refer to the index that top refer to it
{
  *pe = ps->entry[ps->top];
  ps->top--;
}

int StackEmpty(Stack *ps) //  to make sure if top >=0
{

  return !(ps->top + 1);
  /*if(ps->top<0)
  return 1;
  else
  return 0;*/
}

int StackTop(Stack *ps,
             int *pe) //    to return element that top refer to it's index
{
  pop(pe, ps);
  push(*pe, ps);
  return *pe;
}

int StackSize(Stack *ps) //  to return top+1
{
  return ps->top + 1;
}

void display(int e) { printf("e:%d\n", e); }

void trevarsstac(Stack *ps, void (*pf)(int)) {
  for (int i = 0; i <= ps->top; i++)
    (*pf)(ps->entry[i]);
}

int main() {
  int e;
  Stack s;
  creatstack(&s);
  e = 3;
  push(e, &s);
  push(4, &s);
  push(5, &s);
  push(20, &s);

  if (!StachFull(&s))
    push(e, &s);

  if (!StackEmpty(&s))
    pop(&e, &s);
  trevarsstac(&s, &display);
}
