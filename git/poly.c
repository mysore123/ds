#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(a,b)((a)==(b)?0:(a)>(b)?1:-1)
typedef struct
{
float coeff;
int exp;
}polynomial;
polynomial terms[100];
int avail=0;
void attach(float coefficient,int exponent)
{
if(avail>=100)
{
exit(1);
}
terms[avail].coeff=coefficient;
terms[avail].exp=exponent;
avail++;
}

void padd(int starta,int finisha,int startb,int finishb,int*startd,int*finishd)
{
float sum;
*startd=avail;
while(starta<=finisha&&startb<=finishb)
{
switch(COMPARE(terms[starta].exp,terms[startb].exp))
{
case -1: attach(terms[startb].coeff,terms[startb].exp);
startb++;
break;
case 0: sum=terms[starta].coeff+terms[startb].coeff;
if(sum)
{
attach(sum,terms[starta].exp);
}
starta++;
startb++;
break;
case 1: attach(terms[starta].coeff,terms[starta].exp);
starta++;
break;
}
}
for(;starta<=finisha;starta++)
{
attach(terms[starta].coeff,terms[starta].exp);
}
for(;startb<=finishb;startb++)
{
attach(terms[startb].coeff,terms[startb].exp);
}
*finishd=avail-1;
}
void printpoly(int start,int end)
{
int i;
printf("\n");
for(i=start;i<=end;i++)
{
if(i==end)
printf("%.2fX^%d",terms[i].coeff,terms[i].exp);
else
printf("%.2fX^%d+",terms[i].coeff,terms[i].exp);
}
printf("\n");
}

int main()
{
int choice;
int startd=0,finishd=0;
int expon,count=0,i,n,starta=0,startb=0,finisha=0,finishb=0;
float coeff;
int starte,ende,x;
double result;
printf("Menu:\n");
printf("\t1.Additionoftwopolynomials\n\t2.Evaluationofpolynomial\n");
scanf("%d",&choice);

switch(choice)
{
case 1:starta=avail;
while(count!=2)
{
printf("enternumberofterms\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("entertheexponent\n");
scanf("%d",&expon);
printf("enterthecoefficient\n");
scanf("%f",&coeff);
attach(coeff,expon);
}
if(count==0)
{
finisha=avail-1;
startb=avail;
}
if(count==1)
{
finishb=avail-1;
}
count++;
}
printpoly(starta,finisha);
printpoly(startb,finishb);
padd(starta,finisha,startb,finishb,&startd,&finishd);
printpoly(startd,finishd);
break;
}}


