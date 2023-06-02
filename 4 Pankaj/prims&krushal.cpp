// Write a C++ menu driven program to implement prims and krushal algorithms

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int weight[20][20], visited[20], d[20], p[20];

const int MAX = 20;

int parent[MAX], rank[MAX];
int v, e;

void creategraph()
{
  int i, j, a, b, w;
  cout << "\nEnter number of vertices: ";
  cin >> v;
  cout << "\nEnter number of edges: ";
  cin >> e;
  for (i = 1; i <= v; i++)
    for (j = 1; j <= v; j++)
      weight[i][j] = 0;
  for (i = 1; i <= v; i++)
  {
    p[i] = visited[i] = 0;
    d[i] = 32767;
  }
  for (i = 1; i <= e; i++)
  {
    cout << "\nEnter edge a,b and weight w:";
    cin >> a >> b >> w;
    weight[a][b] = weight[b][a] = w;
  }
}

void prim()
{
  int current, totalvisited, mincost, i;
  current = 1;
  d[current] = 0;
  totalvisited = 1;
  visited[current] = 1;
  while (totalvisited != v)
  {
    for (i = 1; i <= v; i++)
    {
      if (weight[current][i] != 0)
        if (visited[i] == 0)
          if (d[i] > weight[current][i])
          {
            d[i] = weight[current][i];
            p[i] = current;
          }
    }
    mincost = 32767;
    for (i = 1; i <= v; i++)
    {
      if (visited[i] == 0)
        if (d[i] < mincost)
        {
          mincost = d[i];
          current = i;
        }
    }
    visited[current] = 1;
    totalvisited++;
  }
  mincost = 0;
  for (i = 1; i <= v; i++)
    mincost += d[i];
  cout << "\nMinimum cost=" << mincost;
  cout << "\nMinimum span tree is: ";
  for (i = 1; i <= v; i++)
    cout << "\nVertex " << i << " is connected to " << p[i];
}


int find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return find(parent[x]);
  }
}

void unionSet(int x, int y) {
  int rootX = find(x);
  int rootY = find(y);

  if (rootX == rootY) {
    return;
  }

  if (rank[rootX] < rank[rootY]) {
    parent[rootX] = rootY;
  } else if (rank[rootX] > rank[rootY]) {
    parent[rootY] = rootX;
  } else {
    parent[rootY] = rootX;
    rank[rootX]++;
  }
}

void kruskal() {
  int a, b, minWeight, totalWeight = 0;

  for(int i = 0; i < v - 1; i++) {
    minWeight = 32767;

    for(int j = 0; j < v; j++) {
      for(int k = 0; k < v; k++) {
        if(weight[j][k] != 0) {
          int rootJ = find(j);
          int rootK = find(k);

          if(rootJ != rootK) {
            if(weight[j][k] < minWeight) {
              minWeight = weight[j][k];
              a = j;
              b = k;
            }
          }
        }
      }
    }

    unionSet(a, b);
    totalWeight += minWeight;

    cout << "Edge " << a << " - " << b << " : " << minWeight << "\n";
  }

  cout << "\nTotal minimum weight of the MST: " << totalWeight;
}


int main()
{
	int ch;
	int flag=1;
	creategraph();
	do{
	cout<<"1.Prim's Algorithm\n2.Krushal's Algorithm"<<endl;
	cin>>ch;
	switch(ch){
		
		case 1: prim();
				break;
		case 2: kruskal();
				break;
	}
	cout<<"\nPress 1 for continue or 0 for exit : ";
	cin>>flag;
	}while(flag==1);
  return (0);
}
