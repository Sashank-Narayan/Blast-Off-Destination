#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 9
int ch;
int r;

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
 int v;
    for ( v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
void printPath(int parent[], int j)
{
    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

int printSolution(int dist[], int n, int parent[])
{
    int src = 0;
   // printf("\n\n\n Vertex\t  Distance \tPath");
    int i;
    for ( i = ch; i <=ch; i++)
    {
       // printf("\n%d -> %d \t\t %d\t\t%d ", src, ch, dist[ch], src);
        //src=ch;
        printf("\nDistance  = %d /mts",dist[ch]);
        printf("\npath =%d\t",src);
      printPath(parent, i);
      
    }
}
 
void route(int graph[V][V], int src)
{
    int dist[V];  
    bool sptSet[V];
    int parent[V];
 
    
    int i;
    for ( i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    dist[src] = 0;
 int count;
    for ( count = 0; count < V-1; count++)
{
        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        
        int v;
        for ( v = 0; v < V; v++)
 
            
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }  
    }

    printSolution(dist, V, parent); 
}
int main()
{

	printf("BLAST OFF DESTINATION\n\n\n");
//	printf("enter your choice");
//	scanf("%d",&r);
printf("\n To find shortest distance in a mall\n");
	do
	{
    printf("\n                   (1)----80---(2)----70----(3) ");
	printf("\n                  / |           |\\           |  \\ ");
	printf("\n               40/  |           |20\\         |   \\ 90");
	printf("\n                /   |           |    \\       |    \\");
	printf("\n              (0)   |11         (8)    \\40   |140   (4)");
	printf("\n                \\   |        /  |       \\    |     /");
    printf("\n               80\\  |   70/     |60      \\   |    /10");
	printf("\n                  \\ |   /       |         \\  |  /");
	printf("\n                    (7)----10--(6)----20---(5)");
	printf("\n1-->Poorvika mobiles");
	printf("\n2-->Puma");
	printf("\n3-->Raymonds");
	printf("\n4-->Samsung Smart Cafe");
	printf("\n5-->Theatre");
	printf("\n6-->Kookaburra");
	printf("\n7-->iPlanet");
	printf("\n8-->KFC");
	printf("Enter the destination to be reached");
	printf("\n\n Enter the destination to be reached : ") ;
    scanf("%d",&ch);
    while(ch>8||ch<0)
    {
    	printf("\tRenter the destination : ");
    	scanf("%d",&ch);
	}
    int graph[V][V] = {{0, 40, 0, 0, 0, 0, 0, 80, 0},
                       {40, 0, 80, 0, 0, 0, 0, 110, 0},
                       {0, 80, 0, 70, 0, 40, 0, 0, 20},
                       {0, 0, 70, 0, 90, 140, 0, 0, 0},
                       {0, 0, 0, 90, 0, 100, 0, 0, 0},
                       {0, 0, 40, 0, 100, 0, 20, 0, 0},
                       {0, 0, 0, 140, 0, 20, 0, 10, 60},
                       {80, 110, 0, 0, 0, 0, 10, 0, 70},
                       {0, 0, 20, 0, 0, 0, 60, 70, 0}
                      };
 
    route(graph, 0);
    printf("\nEnter 1 to  continue : ");
	scanf("%d",&r);
	printf("\n\n\n\n\n");
}
while(r==1);
}
