#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class PrimAlgo
{
    int v, matrix[MAX][MAX];

public:
    PrimAlgo(int vertices)
    {
        v = vertices;

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void addedge(int u, int v, int weight)
    {
        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }

    int minkey(int key[], bool set[])
    {
        int min_i, min = INT_MAX;
        for (int i = 0; i < v; i++)
        {
            if (set[i] == false && key[i] < min)
            {
                min = key[i];
                min_i = i;
            }
        }

        return min_i;
    }

    void primMST() {
        int parent[v];
        int key[v];
        bool set[v];

        for (int i = 0; i < v; i++) {
            key[i] = INT_MAX;
            set[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < v-1; count++) {
            int u = minkey(key, set);
            set[u] = true;
            for (int x = 0; x < v; x++) {
                if (matrix[u][x] && set[x] == false && matrix[u][x] < key[x]) {
                    parent[x] = u;
                    key[x] = matrix[u][x];
                }
            }
        }

        cout << "Minimum Spanning Tree: " << endl;
        for (int i = 1; i < v; i++) {
            cout << parent[i] << " - " << i << " : " << matrix[i][parent[i]] << endl;
        }
    }
};

int main()
{
    int var;
    cout<<"Enter the No of Nodes you want: ";
    cin>>var;
    int edges;
    cout<<"Enter the no of edges you want:";
    cin>>edges;

    
    PrimAlgo obj(var);
    for (int i = 0; i < edges; i++)
    {
        int x,y,z;
        cout<<"Enter Starting point of Edge: ";
        cin>>x;
        cout<<"Enter Ending point of Edge: ";
        cin>>y;
        cout<<"Enterr weight of the Edge: ";
        cin>>z;
        obj.addedge(x,y,z);
    }
    obj.primMST();
    return 0;
}
