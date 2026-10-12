#ifndef STACK_H
#define STACK_H


#define MaxEntry 100
#define StEntry char 

typedef struct stack
{
   int top;
   StEntry entry[MaxEntry];
}Stack;

void CreatStack(Stack *) ;
void ClearStack(Stack *);
void push(Stack *,StEntry);
int StackFull(Stack *);
void pop(Stack *,StEntry *);
int StackEmpty(Stack *);
StEntry StackTop (Stack *,StEntry *);
int StackSize(Stack *);
void TraseverStack(Stack *,void(*)(StEntry));

#endif