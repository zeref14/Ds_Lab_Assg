#include<iostream> 
#include<list> 
#include <bits/stdc++.h> 
#include <vector>
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
	void DFSUtil(int v, bool visited[],unordered_map<int,int>umap); 
	bool cyclic_util(int v, bool visited[], bool *rs);
	void dfs(int node,int& maximum_count);
	void dfsUtil(int node, int count, bool visited[],int& maximum_count);
public: 
	Graph(int V); 
	void adding_edge(int v, int w);  
	void DFS(unordered_map<int,int>umap);  
	void BFS(int s,unordered_map<int,int>umap); 
	bool cyclic();
	int find_diameter(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::adding_edge(int v, int w) 
{ 
	adj[v].push_back(w);
	adj[w].push_back(v);  
} 

void Graph::DFSUtil(int v, bool visited[],unordered_map<int,int>umap) 
{ 
	 
	visited[v] = true; 
	cout << (char)umap[v] << " "; 
	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visited[*i]) 
			DFSUtil(*i, visited,umap); 
} 

 
void Graph::DFS(unordered_map<int,int>umap) 
{ 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false;  
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			DFSUtil(i, visited,umap); 
} 







void Graph::BFS(int s,unordered_map<int,int>umap) 
{ 
    
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    
    list<int> queue; 
  
    
    visited[s] = true; 
    queue.push_back(s); 
  
     
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
         
        s = queue.front(); 
        cout << (char)umap[s] << " "; 
        queue.pop_front(); 
  
        
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 




bool Graph::cyclic_util(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
         
        visited[v] = true; 
        recStack[v] = true; 
  
       
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && cyclic_util(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;   
    return false; 
} 
  

bool Graph::cyclic() 
{ 
     
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    
    for(int i = 0; i < V; i++) 
        if (cyclic_util(i, visited, recStack)) 
            return true; 
  
    return false; 
} 




int x;

void Graph:: dfsUtil(int node, int count, bool visited[], 
                   int& maximum_count) 
{ 
    visited[node] = true; 
    count++; 
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) { 
        if (!visited[*i]) { 
            if (count >= maximum_count) { 
                maximum_count = count; 
                x = *i; 
            } 
            dfsUtil(*i, count, visited, maximum_count); 
        } 
    } 
} 





void Graph::dfs(int node,int& maximum_count) 
{ 
    bool visited[V]; 
    int count = 0; 
  
    for (int i = 0; i <= V; ++i) 
        visited[i] = false; 
  
   
    dfsUtil(node, count + 1, visited, maximum_count); 
} 




int Graph::find_diameter() 
{ 
    int maximum_count = INT_MIN; 
  
    
    dfs( 0,maximum_count); 
  
    dfs(x ,maximum_count); 
  
    return maximum_count; 
}

vector<int> dic;
void insert_edge(int);
int check_present(int);
int main() 
{ 
	int ch;
	
	
	cout<<"1. Inset edge\n"<<"2. DFS traversal\n"<<"3. BFS traversal\n"<<"4. Cycle finding in the graph\n"<<"5. Calculate diameter of the graph\n"<<"6. Exit"<<endl;	
	cin>>ch;
	switch(ch)
	{
	case 1:
	insert_edge(ch);
	break;
	case 2:
	insert_edge(ch);
	break;
	case 3:
	insert_edge(ch);
	break;
	case 4:
	insert_edge(ch);
	break;
	case 5:
	insert_edge(ch);
	break;
	}
	
return 0; 
} 


void insert_edge(int ch)
{
	FILE *fp;
    fp=fopen("q1.txt","r");
    char src[1024],des[1024];
	
	int co=0;
	int ver_num=0;
	int f=-1;

	unordered_map<int,int>umap;
	unordered_map<int,int>umap1;
	if (fp == NULL)
    {
        cout<<"Cannot open file"<<endl;
        exit(0);
    }
	else
	{
		
     while( fscanf(fp,"%c %c\n",&src[co],&des[co]) != EOF )
    {
        co++;
    }

	  for(int i=0;i<co;i++)
    {
        cout<<src[i]<<"\t"<<des[i]<<endl;
    }
	

	

	for(int i=0;i<co;i++)
	{
		 f=check_present((int)src[i]);

		if(f==-1)
		{
			ver_num++;
		}

		f=check_present((int)des[i]);

		if(f==-1)
		{
			ver_num++;
		}
		
	}

	cout<<ver_num<<endl;

	 sort(dic.begin(), dic.end()); 
	 for(int i=0;i<dic.size();i++)
		{
			umap[i]=dic.at(i);
			umap1[dic.at(i)]=i;
		}




	Graph g(ver_num); 

	for(int i=0;i<co;i++)
	{
	g.adding_edge(umap1[(int)(src[i])],umap1[(int)(des[i])]);
	}
	
	
	if(ch ==2)
	{
		g.DFS(umap);
		cout<<endl;

	}

	if(ch==3)
	{
		g.BFS(0,umap);
		cout<<endl;
	}

	if(ch==4)
	{
		 if(g.cyclic()) 
        cout << "Graph contains cycle"<<endl; 
    else
        cout << "Graph doesn't contain cycle"<<endl;
	}

	if(ch==5)
	{
		cout << "Diameter of the given tree is "
        << g.find_diameter() << endl;
	}
	}

}

int check_present(int a)
{
	int f=-1;
	for(int i=0;i<dic.size();i++)
	{
		if(a==dic.at(i))
		{
			f=1;
			break;
		
		}
	}

	if(f==-1)
	{
	dic.push_back(a);
	}

	return f;
}