#include "stack2.h"
_Bool Is_op(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

_Bool precedence(char op1, char op2) {
  if (op1 == '^')
    return 1;

  if (op1 == '*' || op1 == '/')
    if (op2 != '^')
      return 1;

  if (op1 == '+' || op1 == '-')
    if (op2 != '^' && op2 != '*' && op2 != '/')
      return 1;

  return 0;
}

void to_postfix(char infix[], char postfix[]) {
  Stack s;
  CreatStack(&s);
  int j = 0;
  char c;
  char op;
  for (int i = 0; (c = infix[i]) != '\0'; i++) {
    if (!Is_op(c))
      postfix[j++] = c;

    else {
      postfix[j++] = ' ';
      if (!StackEmpty(&s))
        StackTop(&s, &op);

      while (!StackEmpty(&s) && precedence(op, c)) {
        pop(&s, &op);
        postfix[j++] = op;
        postfix[j++] = ' ';
        if (!StackEmpty(&s))
          StackTop(&s, &op);
      }
      push(&s, c);
    }
  }
  while (!StackEmpty(&s)) {
    postfix[j++] = ' ';
    postfix[j++] = StackTop(&s, &op);
    pop(&s, &op);
  }

  for (int i = 0; i < j; i++)
    printf("%c", postfix[i]);
}

int main() {
  char infex[50] = "20+4-87*4^2";
  char postfex[50];
  to_postfix(infex, postfex);
}
