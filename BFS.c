/* Traversal using BFS method*/

#include<stdio.h>
#include<conio.h>

void bfs(int a[10][10], int n, int u)
{
	int	f,r,q[10],v;
	int 	s[10]={0};//initialize all elem in s to 0, no node visited
	printf("The nodes visited from %d:",u);
	f=0, r=-1;// Q empty
	q[++r]=u; // Insert u into Q
	s[u]=1; // Insert u to s
	printf("%d",u); //pritn node visited
	while(f<=r)
	{
		u=q[f++];  //del an elem from Q
		for(v=0; v<n; v++)
		{
			if(a[u][v]==1)		//If v is adjacent to u
			{
				if(s[v]==0)  // If v is not in S i.e, V has not been visited
				{
					printf("%d",v); // print the node visited
					s[v]=1;		//add v to s,mark as visited
					q[++r]=v;	//insert v into Q
				}
			}
		}
	}
	printf("\n");
}






void main()
{
	int	n,a[10][10], source, i,j;
	clrscr();
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(source=0; source<n; source++)
	{
		bfs(a,n,source);
	}
	getch();
}
