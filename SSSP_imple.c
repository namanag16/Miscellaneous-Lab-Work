#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include "Build_graph_uc.c"
#include "top_sort_uc.c"
#define INFINITY 32767

extern struct adj_list **list;
extern int *in_degree;
extern int n;
extern int weight_sum;
extern int *p;
int *distance;
int *parent;

void relax(int,int,int);
void print_node(int);
void main()
{
	int source,i,y;
	struct adj_list *temp;
	build_graph();
	if (!top_sort())
	{
		printf("failed while topological sorting ... exiting ");
		//getch();
		exit(1);
	}

	printf("\n\nplease enter source: ");
	scanf("%d",&source);

	distance = (int *)malloc(sizeof(int)*n);
	parent = (int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		if(i==source)
		{
			distance[i]=0;
			parent[i]=-1;
		}
		else
		{
			parent[i]=-1;
			distance[i]=INFINITY;
		}
	}

	for(i=0;i<n;i++)
	{
		printf("\n\ndistance[%d]: %d",p[i],distance[p[i]]);
		if(distance[p[i]]==INFINITY)
		{
			printf("\ni did nothing ");;
		}
		else
		{
			printf("will try to relax now for vertex %d",p[i]);
			temp=list[p[i]];
			while(temp!=NULL)
			{
				relax(p[i],temp->node,temp->wt);
				printf("\nthe distance after relaxing for vertex %d is %d ",p[i],distance[p[i]]);
				printf("\n\nparent of vertex %d is now %d",p[i],parent[p[i]]);
				temp=temp->ptr;
			}
		}

	}
	printf("i am out of the relax loop ");
	for(i=0;i<n;i++)
	{
		if(!(distance[i]==32767))
			printf("\n\n shortest distance of node %d from source is %d",i,distance[i]);
		else
			printf("\n\n shortest distance of node %d from source is infinity",i);
	}

	for(i=0;i<n;i++)
	{
		printf("\n\nparent for node %d is %d",i,parent[i]);
	}

	printf("\n\n give the destination for which u want to print the shortest path tree: ");
	scanf("%d",&y);

	if(y==source)
		printf("\ndestination is source itself");
	else if(parent[y]==-1)
		printf("\ndestination unreachable");
	else
	{
		printf("\n");
		print_node(parent[y]);
		printf(" %d ",y);
	}
}

void relax(u,v,w)
{
	if(distance[v]>distance[u]+w)
	{
		distance[v]=distance[u]+w;
		parent[v]=u;
	}

}

void print_node(int y)
{
	if(parent[y]!=-1)
		print_node(parent[y]);
	printf(" %d -->",y);
}
