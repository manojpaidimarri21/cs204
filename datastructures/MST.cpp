  
/*
Minimum Spanning Tree
Question: 
Given a Graph, with weighted edges, find the total cost of the minimal spanning tree
*/
// ****KRUSKAL'S ALGO****
/*
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
If cycle is not formed, include this edge. Else, discard it.
3. Repeat step#2 until there are (V-1) edges in the spanning tree.
*/
#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
	 int src,dest,weight;
	
};
class Graph
{
public:
	int V,E;
	Edge* edge;
};
Graph* createGraph(int V,int E)
{  
	Graph* graph=new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;

}
class subset
{
public:
	int parent;
	int rank;
};
int find(subset subsets[],int i)
{
	if(subsets[i].parent!=i)
	{
		subsets[i].parent=find(subsets,subsets[i].parent);
	}
	return subsets[i].parent;
}
void Union(subset subsets[],int x,int y)
{
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);

	if(subsets[xroot].rank<subsets[yroot].rank)
	{
		subsets[xroot].parent=yroot;
		return;
	}
	else if(subsets[xroot].rank>subsets[yroot].rank)
	{
		subsets[yroot].parent=xroot;
		return;
	}
	else if(subsets[xroot].rank==subsets[yroot].rank)
	{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
		return;
	}


}
int myComp(const void* a,const void* b)
{
	Edge* a1=(Edge*)a;
	Edge* b1=(Edge*)b;
	return a1->weight>b1->weight;
}
void KrushkalMSt(Graph* graph,Edge* k)
{
	int V=graph->V;
	Edge result[V];
	qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);
	subset* subsets=new subset[(V*sizeof(subset))];
	for(int v=0;v<V;++v)
	{
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	int e=0;
	int i=0;
	while(e<V-1&&i<graph->E)
	{
		Edge next_edge=graph->edge[i++];
		int x=find(subsets,next_edge.src);
		int y=find(subsets,next_edge.dest);
		if(x!=y)
		{
			result[e++]=next_edge;
			Union(subsets,x,y);
		}
	}
	for (int i = 0; i < e; ++i)  
		k[i]=result[i];
 
	return ;


}

int main()
{
	/* code */
	int V ; // Number of vertices in graph  
    int E ; // Number of edges in graph 
    cin>>V;
    cin>>E; 
    Edge k[V];
    Graph* graph = createGraph(V, E);  

    int x,y,w;
    for(int i=0;i<E;i++)
    {   
    	cin>>x;
    	cin>>y;
    	cin>>w;
    	// add edge 0-1  
        graph->edge[i].src = x;  
        graph->edge[i].dest = y;  
        graph->edge[i].weight = w;  
    }

  
    int sum=0;
   KrushkalMSt(graph,k); 
   			for (int i = 0; i < V-1; ++i)
   			{
   			   sum=sum+k[i];
   			}

		       cout<<sum;
	
	
	return 0;
   			
}