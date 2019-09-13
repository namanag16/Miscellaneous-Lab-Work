//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>

struct adj_list
{
	int node;
	int wt;
	struct adj_list *ptr;
};

struct adj_list **list;
int *in_degree;
int n;
int weight_sum;

void build_graph()
{

	int i;

	int s,d,wt;
	struct adj_list *temp;
	char choice[1];


	printf("\nlets allow the user to input the graph");
	printf("\nenter the number of nodes: ");
	scanf("%d",&n);

	printf("\n\nYour graph will have %d nodes",n);
	list = (struct adj_list **)malloc(sizeof(struct adj_list *)*n); // type casted to pointer to the pointer of struct adj_list rather than
																	// pointer to the array of struct adj_list pointers
	in_degree = (int *)malloc(sizeof(int)*n);   // same case here


	for(i = 0 ;i<n;i++)
	{
		list[i]=NULL;
		in_degree[i]=0;
	}

	//in_degree[n]={0};

	//printf("\n\nin_degree for vertex 1 is %d",in_degree[1]);
	printf("\nstart giving the edges in the graph");
	printf("\n0 will be the first node of the graph.. 1 being second and so on ");

	do
	{
		printf("\n\nenter the source, destination and weight of the edge: ");
		scanf("%d %d %d", &s, &d, &wt);
		in_degree[d]= in_degree[d]+1;
		printf("in_degree for vertex %d is %d ",d,in_degree[d]);
		if(list[s]== NULL)
		{
			list[s]=(struct adj_list *)malloc(sizeof(struct adj_list));
			list[s]->node= d;
			list[s]->wt= wt;
			list[s]->ptr=NULL;
		}
		else
		{
			//find where to insert the pointer to the new node
			temp=list[s];
			while(temp->ptr!=NULL)
			{
				temp= temp->ptr;
			}
			temp->ptr= (struct adj_list *)malloc(sizeof(struct adj_list));
			temp->ptr->node= d;
			temp->ptr->wt= wt;
			temp->ptr->ptr=NULL;
		}
		printf("\ndo you want to add another edge: ");
		scanf("%s", choice);
		printf("\nchoice is %c", choice[0]);
	}while(choice[0]=='y' || choice[0] == 'Y');

	printf("\nGraph initialized.. see the adjacency list of the graph below \n");
	for(i=0;i<n;i++)
	{
		printf("\n edges for node %d:   ",i);
		temp=list[i];
		if(temp==NULL)
			printf("");
		else
		{
			do
			{
				printf("node: %d,weight: %d    ",temp->node,temp->wt);
				weight_sum=weight_sum+temp->wt;
				temp= temp->ptr;
			}while(temp!=NULL);
		}
	}
	printf("\n\nthe in_degree array is:  ");
	for(i=0;i<n;i++)
	{
		printf("%d  ",in_degree[i]);
	}
}
