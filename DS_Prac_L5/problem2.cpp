

/**
 * @file problem2.cpp
 * @author your name (ritesh@domain.com)
 * @brief program for Kruskal's algorithm to find Minimum Spanning Tree
 * @version 0.1
 * @date 2019-10-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 


/**
 * @brief structure to represent a weighted edge in graph
 * 
 */
class Edge 
{ 
	public: 
	int src, dest, weight; 
}; 



/**
 * @brief tructure to represent a connected, undirected and weighted graph 

 * 
 */
class Graph 
{ 
	public: 
	
	int V, E; 

	Edge* edge; 
}; 


/**
 * @brief graph with V vertices and E edges 
 * 
 * @param V vertices
 * @param E edges
 * @return Graph* return graph
 */
Graph* creating_graph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 
  
/**
 * @brief structure to represent a subset for union-find
 * 
 */
class subset 
{ 
	public: 
	int parent; 
	int rank; 
}; 


/**
 * @brief function to find set of an element i 
 * 
 */
int find_subset(subset subsets[], int i) 
{ 
	if (subsets[i].parent != i) 
		subsets[i].parent = find_subset(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 


/**
 * @brief function that does union of two sets of x and y 
 */
void union_subset(subset subsets[], int x, int y) 
{ 
	int xroot = find_subset(subsets, x); 
	int yroot = find_subset(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

/**
 * @brief Compare two edges according to their weights

 */
int comparison(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 



/**
 * @brief function to construct MST using Kruskal's algorithm 
 * 
 * @param graph 
 */
void Kruskal(Graph* graph) 
{ 
	int V = graph->V; 
	Edge result[V]; 
	int e = 0; 
	int i = 0; 

	
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comparison); 

	subset *subsets = new subset[( V * sizeof(subset) )]; 

	 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	while (e < V - 1 && i < graph->E) 
	{ 
		
		Edge next_edge = graph->edge[i++]; 

		int x = find_subset(subsets, next_edge.src); 
		int y = find_subset(subsets, next_edge.dest); 

	
		if (x != y) 
		{ 
			result[e++] = next_edge; 
			union_subset(subsets, x, y); 
		} 
		
	} 

	
    FILE *fw1;
    fw1=fopen("output_digram.txt","w");

    fprintf(fw1,"digraph G {\n");
    cout<<"The edges in the MST are"<<endl; 
	for (i = 0; i < e; ++i)
    { 
		fprintf(fw1," %c -> ",(char)(result[i].src+65));
        fprintf(fw1," %c ",(char)(result[i].dest+65));
		fprintf(fw1," [label= \"%d\"];\n",(result[i].weight));
        cout<<(char)(result[i].src+65)<<"\t"<<(char)(result[i].dest+65)<<"\t"<<result[i].weight<<endl;
    }
    fprintf(fw1,"}");
    fclose(fw1); 
	return; 
} 

int main() 
{ 
	
    FILE *fp;
    fp=fopen("graph_input.csv","r");
    char src[1024],des[1024];
    int weigh[1024];
    int co=0;
    int max;
    
    if (fp == NULL)
    {
        cout<<"Cannot open file"<<endl;
        exit(0);
    }


     while( fscanf(fp,"%c,%c,%d\n",&src[co],&des[co],&weigh[co]) != EOF )
    {
        co++;
    }
    
    fclose(fp);

    for(int i=0;i<co;i++)
    {
        cout<<src[i]<<"\t"<<des[i]<<"\t"<<weigh[i]<<endl;
    }

    
    
    for(int i=0;i<co;i++)
    {
        
        max=((int)src[i]<(int)des[i])?(int)des[i]:(int)src[i];
    }
    
    max=max-64;


    FILE *fw;
    fw=fopen("input_digram.txt","w");

    
    fprintf(fw,"digraph G {\n");
    for(int i=0;i<co;i++)
    {
        fprintf(fw," %c -> ", src[i]);
        fprintf(fw," %c", des[i]);
		fprintf(fw," [label= \"%d\"];\n",weigh[i]);


    }
    fprintf(fw,"}");

    fclose(fw);
    
    
    int V = max; 
	int E = co; 
	Graph* graph = creating_graph(V, E); 


    for(int i=0;i<co;i++)
    {
        graph->edge[i].src =(int)src[i]-65;
        
	    graph->edge[i].dest = (int)des[i]-65;
         
	    graph->edge[i].weight = weigh[i];
       
    }



	Kruskal(graph); 

	return 0; 
} 


//dot -Tps output_digram.txt -o output_digram.pdf command to draw graph
