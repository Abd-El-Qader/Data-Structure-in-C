/*Hanoi Disks
#include<stdio.h>

void moveDisks(int count,int start,int finsh,int temp)
{
  if(count<1)return;
  moveDisks(count-1,start,temp,finsh);
  printf("move %d from %d to %d\n",count,start,finsh);
  moveDisks(count-1,temp,finsh,start);
}

int main()
{
  moveDisks(2,1,3,2);
}*/

#include<stdio.h>
typedef long long ll;



ll Factoria(ll n)
{
 if(n==0ll)
 return 1ll;
 return n*Factoria(n-1);
}

int main()
{
  ll n=0ll;
  scanf("%lld",&n);
  printf("%lld",Factoria(n));
}