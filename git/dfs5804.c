#include<stdio.h>
#include<conio.h>
int a[10][10], n, visited[10];

void dfs(int v)
{
    int i;
    visited[v] = 1;

    for(i = 0; i < n; i++)
	if(a[v][i] == 1 && visited[i] == 0)
	{
	    printf(" -> %d",i);
	    dfs(i);
	}


}

int main()
{

    int i, j, s;

    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix");
    for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	    scanf("%d",&a[i][j]);
    printf("Enter the source vertex : ");
    scanf("%d",&s);
    printf("The DFS path is : %d",s);
    dfs(s);
    getch();

}
