#include<stdio.h>
#include<stdlib.h>
#defineCOMPARE(x,y)((x==y)?0:(x>y)?1:-1)
structnode
{
floatcoeff;
intexp;
structnode*link;
};
typedefstructnode*polypointer;
voidattach(floatcoefficient,intexponent,polypointer*ptr)
{
polypointertemp;
temp=(polypointer)malloc(sizeof(structnode));
temp->coeff=coefficient;
temp->exp=exponent;
(*ptr)->link=temp;
*ptr=temp;
(*ptr)->link=NULL;
}
polypointercadd(polypointera,polypointerb)
{
polypointerc,lastC,startA;
intsum,done=0;
startA=a;
a=a->link;
b=b->link;
c=(polypointer)malloc(sizeof(structnode));
c->exp=-1;
lastC=c;
do
{
switch(COMPARE(a->exp,b->exp))
{
case1:attach(a->coeff,a->exp,&lastC);

a=a->link;
break;

case0:if(startA==a)
done=1;
else
{
sum=a->coeff+b->coeff;
if(sum)
attach(sum,a->exp,&lastC);
a=a->link;
b=b->link;
}
break;

case-1:attach(b->coeff,b->exp,&lastC);

b=b->link;
break;

}
}while(!done);
lastC->link=c;
returnc;
}
voidprintPoly(polypointerk)
{
k=k->link;
while(((k->link)->exp)!=-1)
{
printf("%fx^%d+",k->coeff,k->exp);
k=k->link;
}
printf("%fx^%d",k->coeff,k->exp);
printf("\n");
}
intmain()
{
polypointera,b,c,endA,endB;
intn,i,expon;
floatcoef;
a=(polypointer)malloc(sizeof(structnode));
a->exp=-1;
b=(polypointer)malloc(sizeof(structnode));
b->exp=-1;
printf("enterthenumberoftermsforfirstpolynomial\n");
scanf("%d",&n);
endA=a;
for(i=0;i<n;i++)
{
printf("enterthecoefficient\n");
scanf("%f",&coef);
printf("entertheexponenet\n");
scanf("%d",&expon);
attach(coef,expon,&endA);
}

endA->link=a;
printf("enterthenumberoftermsforsecondpolynomial\n");
scanf("%d",&n);
endB=b;
for(i=0;i<n;i++)
{
printf("enterthecoefficient\n");
scanf("%f",&coef);
printf("entertheexponenet\n");
scanf("%d",&expon);
attach(coef,expon,&endB);
}
endB->link=b;
c=cadd(a,b);
printPoly(a);
printPoly(b);
printPoly(c);
}
