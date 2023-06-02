#include<cstring>
#include<iostream>
using namespace std;

#define INF 9999999

//number of vertices in graph
#define V 5

//for adjacency matrix to represent graph
int G[V][V];

int main(){
    int no_edge; //number of edge
    int cost_path = 0;
    int selected[V];

    //set selected false initially
    memset(selected,false,sizeof(selected));

    //set number of edge to 0
    no_edge = 0;

    int i,j;
    cout<<"Enter value of the total number of vertices : ";
    int V1;
    cin>>V1;
    cout<<"enter the adjacency matrix: "<<endl;
    for(i=0;i<V1;i++)
	{
        for(j=0;j<V1;j++){
            cin>>G[i][j];
        }
    }
    //choose 0th vertex and make it true
    selected[0] = true;

    int x; //row np
    int y; //colomn no
	//print for edge and weight
    cout<<"Edge"<<" : "<<"Weight";
    cout<<endl;

    while(no_edge < V1-1)
	{
        int min = INF;
        x=0;
        y=0;
        for(int i=0;i<V1;i++){
            if(selected[i]){
                for(int j=0;j<V1;j++){
                    if(selected[j]==false && G[i][j])
					{
                        if(min > G[i][j])
						{
                            min = G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" - "<<y<<" : "<<G[x][y];
        cout<<endl;
        cost_path = cost_path + G[x][y];
        selected[y] = true;
        no_edge++;
    }
    cout<<"Minimum cost of path : "<<cost_path<<endl;
    return 0;

}

