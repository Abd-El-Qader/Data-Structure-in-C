#include<iostream>
#include<cmath>
using namespace std;

template<class t>
class stack
{

private:
struct stacknod
{
 t e;
 struct stacknod *next;
};

 stacknod *top;
 int size;
 public:
 stack()
 {
  top=NULL;
  size=0;
 }
  
 void push(t newelement)
 {
  stacknod*newnode=new stacknod;
  newnode->e=newelement;
  newnode->next=top;
  top=newnode;
 }

void pop(t *element)
{
  *element=top->e;
  stacknod*newnode =top;
  top=top->next;
  delete newnode;
}

t stackTop()
{ t topstack;
  topstack=top->e;
  return topstack;
}

int stacksize()
{
 return size;
}

};

double operate(double op1,double op2,char p)
{
  double x;
  switch(p)
  {
    case '+':x= op1 + op2;
    break;
    case '-':x= op1 - op2;
    break;
    case '*':x= op1 * op2;
    break;
    case '/':x= op1 / op2;
    break;
    default: x=powf(op1,op2);
     
  };
  return x;
}

bool Is_op(char c)
{
  return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

double Evalute_postfix(string postfix)
{
  double x;
  char c;
  string c2;
  double op1,op2;
  stack<double>s;

  for(int i=0;i < (int)(postfix.size());i++)
  {
    c=postfix[i];
  
   if(c==',')
  {
   double a=stod(c2);
   s.push(a);
   c2.clear();
  }
  
  else if(!Is_op(c))
     c2+=c;
  
   else
   {
     s.pop(&op2);
     s.pop(&op1);
     x=operate(op1,op2,c);
     s.push(x);
   }
  }
  s.pop(&x);
  return x;
}


int main()
{
 double x=Evalute_postfix("2,59,4,7,*-+");
 cout<<x;
 return 1;
}

