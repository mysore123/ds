#include <stdio.h>
#include <stdlib.h>
struct node
{
int key;
struct node*llink;
struct node*rlink;
};
typedef struct node*nodepointer;
void insert(int item,nodepointer head)
{
nodepointer temp;
temp=(nodepointer)malloc(sizeof(struct node));
temp->key=item;
temp->llink=head;
temp->rlink=head->rlink;
head->rlink->llink=temp;
head->rlink=temp;
head=temp;
}
int del(int item,nodepointer head)
{
if(head==NULL)
{
printf("EMPTYLIST:Noelementtobedeleted\n");
return 0;
}
head=head->rlink;
if((head)->key==-1)

{
printf("Cannotdeleteheadernode\n");
return item;
}
while((head)->key!=-1)
{
if((head)->key==item)
{
printf("Elementdeleted:%d",item);
if(head->rlink)
(head->llink)->rlink=head->rlink;
if(head->llink)
(head->rlink)->llink=head->llink;
return item;
}
head=head->rlink;
}
printf("Elementnotfound\n");
return 0;
}
void displayr(nodepointer head)
{
head=head->rlink;
if(head==NULL)
{
printf("EMPTYLSIT\n");
return;
}
while((head->rlink)->key!=-1)
{
printf("%d\t",head->key);
head=head->rlink;
}
if(head->key!=-1)
printf("%d\n",head->key);
else
printf("EMPTYLIST\n");
}
void displayf(nodepointer head)
{
head=head->llink;
if(head==NULL)
{
printf("EMPTYLSIT\n");
return;
}
while((head->llink)->key!=-1)
{
printf("%d\t",head->key);
head=head->llink;

}
printf("%d\n",head->key);
}
int main()
{
int ch,element;
nodepointer first;
first=(nodepointer)malloc(sizeof(struct node));
first->key=-1;
first->llink=first;
first->rlink=first;
int copy;
while(1)
{
printf("\nEnter\n1.Insert\n2.Delete\n3.DisplayForward\n4.DisplayBackward\n5.Close\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enterelementtobeinserted\n");

scanf("%d",&element);
insert(element,first);
break;

case 2:printf("Enterelementtobedeleted\n");
scanf("%d",&element);
del(element,first);
break;

case 3:printf("Listis\n");
displayf(first);
break;
case 4:printf("Listis\n");
displayr(first);
break;
case 5:printf("Closing\n");
exit(0);
}
}
}
