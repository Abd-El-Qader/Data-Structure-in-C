#include<stdio.h> 
#include"stack.h"

int main()
{
 Stack s;
 StEntry e;
 CreatStack(&s);

 scanf("%s",&e);
 if(!StackFull(&s))
  push(&s,e);

  push(&s,'b');
  push(&s,'c');
  push(&s,'d');
  push(&s,'e');
  push(&s,'f');
  
  if(!StackEmpty(&s))
  pop(&s,&e);
  
  printf("Stack size befor clear:%d\n",StackSize(&s));
  printf("Stack top:%c\n",StackTop(&s,&e));
  ClearStack(&s);
  printf("Stack size after clear:%d\n",StackSize(&s));
  return 0;
}


