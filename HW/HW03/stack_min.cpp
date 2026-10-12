#include<iostream>
using namespace std;

template<class t>
class stack
{
 private:
 
 struct node
 {
  t e;
  node *next;
 };

 struct Top
 {
   node *ptr;
   int Size;
   t MIN ;
 };
  Top s;
 
  public:

 stack()
 {
   s.ptr=NULL;
   s.Size=0;
   s.MIN=__INT_MAX__; 
 }

 void push(t element)
 {
   node *nodenew = new node;
   if(s.Size)
   s.MIN=min(s.ptr->e,element);
   nodenew->e=element;
   nodenew->next=s.ptr;
   s.ptr=nodenew;
   s.Size++;
 }

 void pop()
 {
   node *newnod = s.ptr;
   s->ptr=s->ptr->next;
   delete newnod;
 }

 t top()
 {
   return s.ptr->e;
 }

 int size()
 {
  return s.Size;
 }

 t Min()
 {
  return s.MIN;
 }

 
};

int main()
{
 stack<int>s;
 s.push(4);
 s.push(6);
 s.push(3);
 s.push(8);
 cout<<s.Min();
}