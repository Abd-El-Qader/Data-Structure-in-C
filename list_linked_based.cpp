#include<iostream>
using namespace std;

template <class ListEntery>
class list
{ 
                  private:
  struct Listnode
  {
    ListEntery e;
    Listnode *next;
  };

   Listnode *head;
   int Size;

                   public:
  
  list()
  {
   Size=0;
   head=NULL;
  }

 bool empty()
 {
  if(head)
  return 0;
  else 
  return 1;
 }

 int size()
 {
  return Size;
 }

 void DestroyList()
 {
  Listnode *pn;
  
  while(head)
  {
   pn=head->next;
   free(head);
   head=pn;
  }
  Size=0;
 }

 void TraverseList(void(*pf)(ListEntery))
{
  Listnode *pn=head;
  while(pn)  
  {
   (*pf)(pn->e);
   pn=pn->next;  
  }
}

 void insert(int pos,ListEntery e)
 {
  Listnode *p,*q;
  p->e=e;
  p->next=NULL;
  if(!pos)
  {
    p->next=head;
    head=p;
  }
  else
  {
   q=head;
   
   for(int i=0;i<pos-1;i++)
        q=q->next;
     
   p=q->next;
   q->next=p;
  }
   Size++;
 }

 void erae(int pos)
 {
   Listnode *p,*q;
   
   if(!pos)
   {
     p=head;
     head=head->next;
     free(p);
   }

   else
   {
    q=head;
    for(int i=0;i<pos-1;i++)
    q=q->next;
    p=q->next;
    q->next=q->next->next;
    free(p);
   }
   Size--;
 }
   
 ListEntery RetrievList(int pos)
 {
  Listnode *pn = head;

  for(int i=0;i<pos;i++)pn=pn->next;

  return pn->e;
  
 }

 void ReplaceList(int pos,ListEntery e)
 {
  Listnode *pn=head;
  for(int i=0;i<pos;i++)pn=pn->next;
  pn->e=e;
 }
};

template <class ListEntery>
class list2
{ 
                  private:
  struct Listnode
  {
    ListEntery e;
    Listnode *next;
  };

   Listnode *head;
    Listnode *Current;
    int Currentpos;
   int Size;
   

                   public:
  
  list2()
  {
   Size=0;
   head=NULL;
   Current=NULL;
   Currentpos=0;
  }

 bool empty()
 {
  if(head)
  return 0;
  else 
  return 1;
 }

 int size()
 {
  return Size;
 }

 void DestroyList()
 {
  Listnode *pn;
  
  while(head)
  {
   pn=head->next;
   free(head);
   head=pn;
  }
  Size=0;
 }

 void TraverseList(void(*pf)(ListEntery))
{
  Listnode *pn=head;
  while(pn)  
  {
   (*pf)(pn->e);
   pn=pn->next;  
  }
}

 void insert(int pos,ListEntery ea)
 {
  Listnode *p=new Listnode;
  p->e=ea;
  p->next=NULL;
  
if(!pos)
  {
    p->next=head;
    head=p;
    Current=head;
    Currentpos=0;
  }

  else
  {
   if(pos<=Currentpos)
   {
   Currentpos=0;
   Current=head;
     for(;Currentpos<pos-1;Currentpos++)
     Current=Current->next;
     p->next=Current->next;  
     Current->next=p;
     
   }
  
   else if(pos>Currentpos)
   {
    for(;Currentpos<pos-1;Currentpos++)
    Current=Current->next; 
   p->next=Current->next;
   Current->next=p;
   }
  }
   Size++;
 }

 void eraes(int pos)
 {
   Listnode *p;
  
   if(!pos)
   {
     
     Current=head->next;
     free(head);
     head =Current;
     Currentpos=0;
    
   }

   else
   {
    if(pos<=Currentpos)
   {
    Currentpos=0;
   Current=head;
   }
  
    for(;Currentpos<pos-1;Currentpos++)
    Current=Current->next; 
   p=Current->next->next;
   free(Current->next);
   Current->next=p;
   }
    
   Size--;
 }
   
 ListEntery RetrievList(int pos)
 {
  
  
  if(pos<=Currentpos)
   {
    Currentpos=0;
   Current=head;
   }
  for(;Currentpos<pos;Currentpos++)
    Current=Current->next;
    return Current->e;
 }

 void ReplaceList(int pos,ListEntery e)
 {
  if(pos<=Currentpos)
   {
    Currentpos=0;
   Current=head;
   }
    for(;Currentpos<pos;Currentpos++)
    Current=Current->next;

     Current->e=e;
  
 }

 void insert_order(int pos,ListEntery e)
 {
  
 }
};

int main()
{
  list2<int>l;
  
  l.insert(0,1);
  l.insert(1,5);
  l.insert(2,7);
  l.insert(3,0);
  l.insert(4,8);
  l.insert(5,9);
  l.eraes(2);
  int c;
  cin>>c;
  int s=l.size();
  for(int i=0;i<s;i++)
  {
    if(c==l.RetrievList(i))
    {cout<<"Finded at:"<<i<<"\n";return 0;}
  }
  cout<<"Not_Finded\n";
  return 0;
}