
/**
 * @file problem3.cpp
 * @author your name (ritesh@domain.com)
 * @brief Prim MST for adjacency list representation of graph
 * @version 0.1
 * @date 2019-10-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */


// 

#include<iostream>
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <cmath>
#include <cstdlib>
using namespace std;


/**
 * @brief structure to represent a node in adjacency list 
 * 
 */
struct AdjListNode { 
	int dest; 
	int weight; 
	struct AdjListNode* next; 
}; 



/**
 * @brief A structure to represent an adjacency list 
 * 
 */

struct AdjList { 
	struct AdjListNode* head; 
}; 




/**
 * @brief A structure to represent a graph
 * 
 */

struct Graph { 
	int V; 
	struct AdjList* array; 
}; 

 

/**
 * @brief function to create a new adjacency list node 
 * 
 * @param dest destination node
 * @param weight weight of node
 * @return struct AdjListNode* return node
 */

struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->weight = weight; 
	newNode->next = NULL; 
	return newNode; 
} 



/**
 * @brief Create a Graph object utility function that creates a graph of V vertices 
 * 
 * @param V no. of vertex
 * @return struct Graph* return graph
 */

struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
	graph->V = V; 

	
	graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)); 

	
	for (int i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 


/**
 * @brief Adds an edge to an undirected graph 
 * 
 * @param graph the graph
 * @param src source node
 * @param dest destination node
 * @param weight weight
 */

void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
	
	struct AdjListNode* newNode = newAdjListNode(dest, weight); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	
	newNode = newAdjListNode(src, weight); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 



struct node
{
    int n;
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
    char mark;
    char C;
};

class FibonacciHeap
{
    private:
        int nH;
        node *H;
    public:
        node* InitializeHeap();
        int Fibonnaci_link(node*, node*, node*);
        node *Create_node(int);
        node *Insert(node *, node *);
        node *Union(node *, node *);
        node *Extract_Min(node *);
        int Consolidate(node *);
        int Display(node *);
        node *Find(node *, int);
        int Decrease_key(node *, int, int);
        int Delete_key(node *,int);
        int Cut(node *, node *, node *);
        int Cascase_cut(node *, node *);
        FibonacciHeap()
        {
            H = InitializeHeap();
        }
};

/**
 * @brief intialize fibbonaci heap
 * 
 */
node* FibonacciHeap::InitializeHeap()
{
    node* np;
    np = NULL;
    return np;
}
/**
 * @brief create node
 * 
 */
node* FibonacciHeap::Create_node(int value)
{
    node* x = new node;
    x->n = value;
    return x;
}

/**
 * @brief insert node
 * 

 */
node* FibonacciHeap::Insert(node* H, node* x)
{
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';
    if (H != NULL)
    {
        (H->left)->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        if (x->n < H->n)
            H = x;
    }
    else
    {
        H = x;
    }
    nH = nH + 1;
    return H;
}
/**
 * @brief create link
 
 */
int FibonacciHeap::Fibonnaci_link(node* H1, node* y, node* z)
{
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (z->right == z)
        H1 = z;
    y->left = y;
    y->right = y;
    y->parent = z;
    if (z->child == NULL)
        z->child = y;
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;
    if (y->n < (z->child)->n)
        z->child = y;
    z->degree++;
}
/**
 * @brief make union
 * 
 */
node* FibonacciHeap::Union(node* H1, node* H2)
{
    node* np;
    node* H = InitializeHeap();
    H = H1;
    (H->left)->right = H2;
    (H2->left)->right = H;
    np = H->left;
    H->left = H2->left;
    H2->left = np;
    return H;
}

int FibonacciHeap::Consolidate(node* H1)
{
    int d, i;
    float f = (log(nH)) / (log(2));
    int D = f;
    node* A[D];
    for (i = 0; i <= D; i++)
        A[i] = NULL;
    node* x = H1;
    node* y;
    node* np;
    node* pt = x;
    do
    {
        pt = pt->right;
        d = x->degree;
        while (A[d] != NULL)
        {
            y = A[d];
            if (x->n > y->n)
            {
                np = x;
                x = y;
                y = np;
            }
            if (y == H1)
                H1 = x;
            Fibonnaci_link(H1, y, x);
            if (x->right == x)
                H1 = x;
                A[d] = NULL;
            d = d + 1;
        }
        A[d] = x;
        x = x->right;
    }
    while (x != H1);
    H = NULL;
    for (int j = 0; j <= D; j++)
    {
        if (A[j] != NULL)
        {
            A[j]->left = A[j];
            A[j]->right =A[j];
            if (H != NULL)
            {
                (H->left)->right = A[j];
                A[j]->right = H;
                A[j]->left = H->left;
                H->left = A[j];
                if (A[j]->n < H->n)
                H = A[j];
            }
            else
            {
                H = A[j];
            }
            if(H == NULL)
                H = A[j];
            else if (A[j]->n < H->n)
                H = A[j];
        }
    }
}



int FibonacciHeap::Cascase_cut(node* H1, node* y)
{
    node* z = y->parent;
    if (z != NULL)
    {
        if (y->mark == 'F')
        {
            y->mark = 'T';
	}
        else
        {
            Cut(H1, y, z);
            Cascase_cut(H1, z);
        }
    }
}

/**
 * @brief decrease key 
 */
int FibonacciHeap::Decrease_key(node*H1, int x, int k)
{
    node* y;
    if (H1 == NULL)
    {
        cout<<"The Heap is Empty"<<endl;
        return 0;
    }
    node* ptr = Find(H1, x);
    if (ptr == NULL)
    {
        cout<<"Node not found in the Heap"<<endl;
        return 1;
    }
    if (ptr->n < k)
    {
        cout<<"Entered key greater than current key"<<endl;
        return 0;
    }
    ptr->n = k;
    y = ptr->parent;
    if (y != NULL && ptr->n < y->n)
    {
        Cut(H1, ptr, y);
        Cascase_cut(H1, y);
    }
    if (ptr->n < H->n)
        H = ptr;
    return 0;
}

int FibonacciHeap::Cut(node* H1, node* x, node* y)
{
    if (x == x->right)
        y->child = NULL;
    (x->left)->right = x->right;
    (x->right)->left = x->left;
    if (x == y->child)
        y->child = x->right;
    y->degree = y->degree - 1;
    x->right = x;
    x->left = x;
    (H1->left)->right = x;
    x->right = H1;
    x->left = H1->left;
    H1->left = x;
    x->parent = NULL;
    x->mark = 'F';
}

node* FibonacciHeap::Find(node* H, int k)
{
    node* x = H;
    x->C = 'Y';
    node* p = NULL;
    if (x->n == k)
    {
        p = x;
        x->C = 'N';
        return p;
    }
    if (p == NULL)
    {
        if (x->child != NULL )
            p = Find(x->child, k);
        if ((x->right)->C != 'Y' )
            p = Find(x->right, k);
    }
    x->C = 'N';
    return p;
}

int FibonacciHeap::Delete_key(node* H1, int k)
{
    node* np = NULL;
    int t;
    t = Decrease_key(H1, k, -5000);
    if (!t)
        np = Extract_Min(H);
    if (np != NULL)
        cout<<"Key Deleted"<<endl;
    else
        cout<<"Key not Deleted"<<endl;
    return 0;
}

node* FibonacciHeap::Extract_Min(node* H1)
{
    node* p;
    node* ptr;
    node* z = H1;
    p = z;
    ptr = z;
    if (z == NULL)
        return z;
    node* x;
    node* np;
    x = NULL;
    if (z->child != NULL)
        x = z->child;
    if (x != NULL)
    {
        ptr = x;
        do
        {
            np = x->right;
            (H1->left)->right = x;
            x->right = H1;
            x->left = H1->left;
            H1->left = x;
            if (x->n < H1->n)
                H1 = x;
            x->parent = NULL;
            x = np;
        }
        while (np != ptr);
    }
    (z->left)->right = z->right;
    (z->right)->left = z->left;
    H1 = z->right;
    if (z == z->right && z->child == NULL)
        H = NULL;
    else
    {
        H1 = z->right;
        Consolidate(H1);
    }
    nH = nH - 1;
    return p;
}



struct MinHeapNode { 
	int v; 
	int key; 
}; 


struct MinHeap { 
	int size; 
	int capacity;  
	int* pos; 
	struct MinHeapNode** array; 
}; 


struct MinHeapNode* newMinHeapNode(int v, int key) 
{ 
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
	minHeapNode->v = v; 
	minHeapNode->key = key; 
	return minHeapNode; 
} 


struct MinHeap* createMinHeap(int capacity) 
{ 
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
	minHeap->pos = (int*)malloc(capacity * sizeof(int)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 


void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
	int smallest, left, right; 
	smallest = idx; 
	left = 2 * idx + 1; 
	right = 2 * idx + 2; 

	if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key) 
		smallest = left; 

	if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key) 
		smallest = right; 

	if (smallest != idx) { 
	
		MinHeapNode* smallestNode = minHeap->array[smallest]; 
		MinHeapNode* idxNode = minHeap->array[idx]; 

		minHeap->pos[smallestNode->v] = idx; 
		minHeap->pos[idxNode->v] = smallest; 

		 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 

		minHeapify(minHeap, smallest); 
	} 
} 

int isEmpty(struct MinHeap* minHeap) 
{ 
	return minHeap->size == 0; 
} 


struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	if (isEmpty(minHeap)) 
		return NULL; 
 
	struct MinHeapNode* root = minHeap->array[0]; 

	
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
	minHeap->array[0] = lastNode; 
 
	minHeap->pos[root->v] = minHeap->size - 1; 
	minHeap->pos[lastNode->v] = 0; 


	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return root; 
} 


/**
 * @brief Function to decrease key value of a given vertex v
 * 
 * 
 * @param v vertex
 * @param key the key
 */
void decreaseKey(struct MinHeap* minHeap, int v, int key) 
{ 
	
	int i = minHeap->pos[v]; 

	
	minHeap->array[i]->key = key; 


	while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) { 
		
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2; 
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i; 
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 

		i = (i - 1) / 2; 
	} 
} 


bool isInMinHeap(struct MinHeap* minHeap, int v) 
{ 
	if (minHeap->pos[v] < minHeap->size) 
		return true; 
	return false; 
} 


/**
 * @brief function used to print the constructed MST
 * 
 */
void printArr(int arr[], int n) 
{ 


FILE *fw1;
    fw1=fopen("output_digram_prim.txt","w");

    fprintf(fw1,"digraph G {\n");

	cout<<"The Mst Graph is:"<<endl;
    for (int i = 1; i < n; ++i) 
    {
		fprintf(fw1," %c -> ",(char)(arr[i]+65));
        fprintf(fw1," %c ;\n",(char)(i+65));
        printf("%c - %c\n", (char)(arr[i]+65), (char)(i+65)); 
    }

    fprintf(fw1,"}");
    fclose(fw1); 


} 


/**
 * @brief function that constructs Minimum Spanning Tree (MST) using Prim's algorithm 
 * 
 * @param graph the graph
 */
void PrimMST(struct Graph* graph) 
{ 
	int V = graph->V; 
	int parent[V]; 
	int key[V]; 

	struct MinHeap* minHeap = createMinHeap(V); 

	
	for (int v = 1; v < V; ++v) { 
		parent[v] = -1; 
		key[v] = INT_MAX; 
		minHeap->array[v] = newMinHeapNode(v, key[v]); 
		minHeap->pos[v] = v; 
	} 

	key[0] = 0; 
	minHeap->array[0] = newMinHeapNode(0, key[0]); 
	minHeap->pos[0] = 0; 

	minHeap->size = V; 

	 
	while (!isEmpty(minHeap)) { 
		
		struct MinHeapNode* minHeapNode = extractMin(minHeap); 
		int u = minHeapNode->v; 
		 
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) { 
			int v = pCrawl->dest; 

			if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) { 
				key[v] = pCrawl->weight; 
				parent[v] = u; 
				decreaseKey(minHeap, v, key[v]); 
			} 
			pCrawl = pCrawl->next; 
		} 
	} 

	printArr(parent, V); 
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

    cout<<"The input file is :"<<endl;

    for(int i=0;i<co;i++)
    {
        cout<<src[i]<<"\t"<<des[i]<<"\t"<<weigh[i]<<endl;
    }

    
    
    for(int i=0;i<co;i++)
    {
        
        max=((int)src[i]<(int)des[i])?(int)des[i]:(int)src[i];
    }
    
    max=max-64;

    int V = max;
    // int V = 9;
    struct Graph* graph = createGraph(V); 
	
    
       for(int i=0;i<co;i++)
    {
       addEdge(graph, (int)src[i]-65, (int)des[i]-65, weigh[i]); 
       
    }

	PrimMST(graph); 

	return 0; 
} 
