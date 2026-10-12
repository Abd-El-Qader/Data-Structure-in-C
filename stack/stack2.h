
#ifndef STACK2_H
#define STACK2_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define Stentry char
typedef struct stacknod {
  Stentry e;
  struct stacknod *next;
} Stacknod;

typedef struct stack {
  Stacknod *top;
  int size;
} Stack;

void CreatStack(Stack *);
void ClearStack(Stack *);
void push(Stack *, Stentry);
int StackFull(Stack *);
void pop(Stack *, Stentry *);
int StackEmpty(Stack *);
Stentry StackTop(Stack *, Stentry *);
int StackSize(Stack *);
void TraseverStack(Stack *, void (*)(Stentry));

#endif
