#include<stdio.h>

int G[10][10],visited[10],n;

void DFS(int v)
{
	int w;
	printf("\tv%d ",v+1);
	visited[v]=1;
	for(w=0;w<n;w++)
		if(visited[w]==0 && G[v][w]==1)
			DFS(w);
}

void main()
{
	int i,j;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("Enter 1 if there is an edge between the vertices and 0 if not :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
		    if(i==j)
		    {
		        G[i][j]=0;
		        continue;
		    }
			printf("v%d and v%d : ",i+1,j+1);
			scanf("%d",&G[i][j]);
		}
	printf("\nadjacency matrix : ");
	for(i=0;i<n;i++)
	{
	    printf("\n");
	    for(j=0;j<n;j++)
	    {
	     printf("%d\t",G[i][j]);   
	    }
	}
	for(i=0;i<n;i++)
        visited[i]=0;
	printf("\nDFS traversal through graph ");
	DFS(0);
}