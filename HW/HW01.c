/*#include<stdio.h>

int main()
{
 int a[10];
 
 for(int i=0;i<=9;i++)
 a[i]=9-i;
 
 for(int i=0;i<=9;i++)
 a[i]=a[a[i]];
 
 for(int i=0;i<=9;i++)
 printf("%d ",a[i]);   //result: 0,1,2,3,4,4,3,2,1,0
}*/

/*#include<stdio.h>
int main()
{
 int a[5][5];
 for(int i=0;i<5;i++)
 for(int j=0;j<5;j++)
 if(i==j)a[i][j]=1;
 else a[i][j]=0;

 for(int i=0;i<5;i++)
 {
  for(int j=0;j<5;j++)
  printf("%d ",a[i][j]);
  printf("\n");
 }
}*/

/*#include<stdio.h>

int main()
{
 char name[20] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'};
 printf("%p",name+9);
}*/

/*#include<stdio.h>
#define WeatherTypeList WeatherType
#define DecadeWeather   WeatherType
typedef struct WeatherType
{
 int lowavg;
 int highavg;
}WeatherType;

int main()
{
 WeatherTypeList a[12];
 DecadeWeather da[10][12];
 
 int month;
 scanf("%d",&month);
 
 month--;
 scanf("%d",&a[month].highavg);
 printf("high temp of August:%d",a[month].highavg);
 
 
 int year,month2;
 scanf("%d %d",&year,&month2);
 
 year-=2001,month2--;
 scanf("%d",&da[year][month2].lowavg);
 printf("low temp of March 2006:%d",a[month].highavg);

}*/

/*#include<stdio.h>

typedef struct chessboard
{
  int white;
  int cell;
  char type_of_Rock;
}Chessboard;

typedef struct pointat_plan
{
 int x;
 int y;
}Point_Plan;

typedef struct book
{
 char name[30];
 char adrees[30];

}Book;

typedef struct  Temp_each_hour
{
 int hour;
 int temp;
}Temp_at_hour;
int main()
{
 
}*/

/*#include<stdio.h>

void increment(int *i){
(*i)++;
}
int main(){
int count = 1;
while (count < 10){
printf("%d",count);
increment(&count);
}
}*/