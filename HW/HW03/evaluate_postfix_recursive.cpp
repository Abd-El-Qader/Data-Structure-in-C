/*#include<iostream>
#include<cmath>
using namespace std;

int i=0;
string s;

double Evaluate_pre()
{
  int x=0;
   
  if(s[i]==' ')
   i++;

   if(s[i]=='+')
   {i++; return Evaluate_pre() + Evaluate_pre();}

   if(s[i]=='*')
   {i++; return Evaluate_pre() * Evaluate_pre();}

   while(s[i]>='0'&&s[i]<='9')
   x= x*10 + (s[i++]-'0');
  return x;
}

int main()
{
  cin>>s;
  cout<<Evaluate_pre();
}*/