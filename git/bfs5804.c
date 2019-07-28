#include<stdio.h>
#include<conio.h>
int q[10],f=-1,r=-1;
void bfs(int g[10][10],int n, int s)
{
int visited[10]={0}, v, u;
visited[s]=1;
q[++r]=s;
printf("bfs traversal is %d",s);
while(!isqueueempty())
{
v=q[++f];
for(u=0;u<n;u++)
{
if(visited[u]==0&&g[u][v]!=0)
{
q[++r]=u;
visited[u]=1;
printf(" --> %d",u);
}
}
}
}
int isqueueempty()
{
if(f==r)
return 1;
return 0;
}

void main()
{
	int g[10][10], n, i, j, s;

	printf("Enter no of nodes : ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix \n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&g[i][j]);

	printf("enter the start node : ");
	scanf("%d",&s);
	bfs(g, n, s);


}
