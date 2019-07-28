#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int data; 
    struct node *lchild, *rchild; 
}; 
 
struct node* search(struct node* root, int data) 
{ 
  
    if (root == NULL || root->data == data) 
       return root; 
 
    if (root->data < data) 
       return search(root->rchild, data); 
  
    return search(root->lchild, data); 
} 

  
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->lchild = temp->rchild = NULL; 
    return temp; 
} 
   
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->lchild); 
        printf("%d \n", root->data); 
        inorder(root->rchild); 
    } 
} 
   
struct node* insert(struct node* node, int data) 
{ 
    if (node == NULL) return newNode(data); 
  
    if (data < node->data) 
        node->lchild  = insert(node->lchild, data); 
    else if (data > node->data) 
        node->rchild = insert(node->rchild, data);    
  
    return node; 
} 
   
int main() 
{ 
   
    	struct node *root = NULL; 
    	int n, item, i, ch;
	printf("Enter number of nodes in BST : ");
	scanf("%d", &n);
	for(i =0; i < n; i++)
	{
		printf("Enter a element : ");
		scanf("%d", &item);
		root = insert(root, item);
	}
	while(1)
	{
		printf("**********Menu************\n\n");
		printf("1 inorder display\n");
		printf("2 insert new item\n");
		printf("3 search an element\n");
		printf("4 exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:inorder(root); 
				break;
			
			case 2 :printf("Enter a element : ");
				scanf("%d", &item);
				root = insert(root, item);
				break;
			case 3 :printf("Enter the element to be search : ");
				scanf("%d", &item);
				if(search(root, item)!= NULL)
					printf("\nKey element found\n\n");
				else
					printf("\nKey element not found\n\n");
				break;
			default:return 0;
		}
     
       }
    
} 

