#include<stdio.h>
#include<malloc.h>

int n,visited[10],front,rear,q[10];

struct node
{
	int vertex;
	struct node *next;
};

struct node *G[10];

void initialize(int q[])
{
	front=rear=-1;
} 

void insert(int vi,int vj)
{
	struct node *p,*q;
	q = malloc(sizeof(struct node));
	q->vertex = vj;
	q->next = NULL;
	if(G[vi]==NULL)
		G[vi]=q;
	else{
		p=G[vi];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
}

int isempty(int q[])
{
	if(front<0 || front>rear)
	    return 1;
    else
		return 0;
}

void addqueue(int q[],int data)
{
	if(rear==-1)
	{
	  front=0;
	  rear=0;
	  q[rear]=data;
	}
	else
	{
		++rear;
		q[rear]=data;
	}		
}

int deletequeue(int q[])
{
    int data=q[front];
    printf(" v%d",data);
	front++;
    return data;
}

void BFS(int v)
{
	int w;
	visited[v]=1;
	initialize(q);
	addqueue(q,v);
	while(!isempty(q))
	{
		v=deletequeue(q);
		struct node *loc;
		loc=G[v];
		for(;loc;loc=loc->next)
		{
			w=loc->vertex;
			if(visited[w]==0)
			{
				addqueue(q,w);
				visited[w]=1;
			}
	}   }
}

void main()
{
	int i,j,x,m;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the no. of edges from vertex v%d: ",i);
		scanf("%d",&x);
		printf("Enter the adjacent vertices ");
		for(j=0;j<x;j++)
		{
			scanf("%d",&m);
			insert(i,m);
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
		printf("BFS is");
	BFS(1);
}