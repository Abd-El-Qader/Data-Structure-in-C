#include<iostream>
#include<vector>
using namespace std;

int binar_search(vector<int>v,int key)
{
 int botom=0,top=v.size()-1;
 int midel;
 while(botom<top)
 {
  midel=(botom+top)/2;
  if(v[midel]==key)return midel;

  else if(v[midel]<key)botom=midel+1;

  else top=midel-1;
 }
 return -1;
}

int main()
{
 vector<int>v{1,2,4,6,7,9};
 int ind=binar_search(v,5);
 cout<<(ind>(-1)?ind:-1);

}