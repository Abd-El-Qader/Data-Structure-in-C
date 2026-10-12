#include"stack2.h"

double operate(char op1,char op2,char p) {
  double x1=op1;
  double x2=op2;
  double x;
  switch(p) {
    case '+':x= x1 + x2;
    break;
    case '-':x= x1-x2;
    break;
    case '*':x= x1*x2;
    break;
    case '/':x= x1/x2;
  };
  return x;
}

_Bool Is_op(char c) {
  return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

double Evalute_postfix(char postfix[]) {
  double x;
  char c;
  double op1,op2;
  Stack s;
  CreatStack(&s);
  for(int i=0;(c=postfix[i])!='\0';i++) {
   if(!Is_op(c)) {
    push(&s,(double)c-'0');
   }

   else {
     pop(&s,&op2);
     pop(&s,&op1);
     x=operate(op1,op2,c);
     push(&s,x);
   }
  }
  pop(&s,&x);
  return x;
}

int main() {
  printf("%f",Evalute_postfix("245*+3-"));
}