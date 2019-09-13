//#include<stdio.h>
//#include<conio.h>

extern struct adj_list **list;
extern int *in_degree;
extern int n;
int find_zero();
int zero_found;
int *p;
int *already_took_u;

int top_sort()
{
	int x;
	int i;
	int j=0;
	int *color;
	struct adj_list *temp;

	p=(int *)malloc(sizeof(int)*(n+1));

	for(i=0;i<n;i++)
	{
		p[i]=n;
	}
	printf("\ndoes the control comes here ");
	already_took_u = (int *)calloc(n,2);
	color= (int *)malloc(sizeof(int)*n);
	i=0;
	printf("\nvalue of i is %d",i);
	printf("\nthe value of n is %d",n);
	for(i=0;i<n;i++)
	{
		printf("\nvalue of i is %d",i);
		printf("\n testing the value here: %d ",already_took_u[i]);
		already_took_u[i]=0;
		color[i]=0;
	}

	do
	{
		x = find_zero();
		if(zero_found==1)
		{
			printf("\n\nnode %d taken for relaxing ",x);
			temp=list[x];
			p[j++]=x;
			color[x]=1;
			while(temp!=NULL)
			{
				if(color[temp->node]==1)
				{
					printf("\n\n input graph has a cycle.. exiting");
					//getch();
					return 0 ;
				}
				else
				{
					in_degree[temp->node]-=1;
					temp=temp->ptr;

				}
			}
		}
		else
		{
			printf("\n\n topological order cannot be found");
			//getch();
			return 0 ;
		}




	}while(zero_found && j!=n);

	printf("\n\n the topological order is given below");
			for(i=0;i<n;i++)
			{
				printf("\n\n %d",p[i]);
			}
	printf("\nReturning success from topological sorting");
	return 1;
}

int find_zero()
{
	int i;
	zero_found=0;
	printf("\n\ninside the function to find zero degree");
	for(i=0;i<n;i++)
	{
		printf("\ni is %d , degree is %d",i,in_degree[i]);
		printf("\nalready took u [%d] is %d",i,already_took_u[i]);
		if(in_degree[i]==0 && already_took_u[i]==0)
		{
			printf("\n\nfound a zero");
			zero_found=1;
			already_took_u[i]=1;
			return i;
		}
	}
}
