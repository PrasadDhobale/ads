#include<iostream>
#include<algorithm>
using namespace std;

// number of vertices in graph
#define V 5

// structure to represent an edge
class Edge 
{
    public:
        int src, dest, weight;
};

// function to compare two edges based on weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// for adjacency matrix to represent graph
int G[V][V];

// function to find the parent of a vertex
int find_parent(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find_parent(parent, parent[i]);
}

// function to perform union of two subsets
void perform_union(int parent[], int rank[], int x, int y) 
{
    int x_root = find_parent(parent, x);
    int y_root = find_parent(parent, y);
    if(rank[x_root] < rank[y_root])
        parent[x_root] = y_root;
    else if(rank[x_root] > rank[y_root])
        parent[y_root] = x_root;
    else 
	{
        parent[y_root] = x_root;
        rank[x_root]++;
	}
}

int main() 
{
    int cost_path = 0;
    Edge edges[V*V]; // to store all edges of the graph
    int edge_count = 0;

    int i,j;
    cout<<"Enter the adjacency matrix of the graph: "<<endl;
    for(i=0;i<V;i++) 
	{
        for(j=0;j<V;j++) 
		{
            cin>>G[i][j];
            if(G[i][j] != 0) 
			{
                edges[edge_count].src = i;
                edges[edge_count].dest = j;
                edges[edge_count].weight = G[i][j];
                edge_count++;
            }
        }
    }

    // sort the edges based on weight
    sort(edges, edges+edge_count, compare);

    int parent[V];
    
    int rank[V];

    // initialize the parent and rank arrays
    for(i=0;i<V;i++) 
	{
        parent[i] = i;
        rank[i] = 0;
    }

    cout<<"Edge : Weight"<<endl;
    for(i=0;i<edge_count;i++) 
	{
        int x = find_parent(parent, edges[i].src);
        int y = find_parent(parent, edges[i].dest);
		
		// check if adding the current edge creates a cycle or not
        if(x != y) 
		{
            cout<<edges[i].src<<" - "<<edges[i].dest<<" : "<<edges[i].weight<<endl;
            cost_path += edges[i].weight;
            perform_union(parent, rank, x, y);
        }
    }

    cout<<"Minimum cost of path : "<<cost_path<<endl;
    return 0;
}
