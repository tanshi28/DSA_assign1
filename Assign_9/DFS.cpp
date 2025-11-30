#include <iostream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];     
int adjSize[MAX];      
bool visited[MAX];     
void DFS(int node){
    visited[node]=true;
    cout<<node<<" ";
    for(int i=0;i<adjSize[node];i++){
        int n=adj[node][i];
        if(!visited[n]){
            DFS(n);
        }
    }
}
int main() {
    int v,e;
    cout<<"Enter vertices: ";
    cin>>v;
    cout<<"Enter edges: ";
    cin>>e;
    for(int i=0;i<v;i++){
        adjSize[i]=0;
        visited[i]=false;
    }
    cout<<"Enter edges:"<<endl;
    for (int i=0;i<e;i++) {
        int u,y;
        cin>>u>>y;
        adj[u][adjSize[u]++]=y;
        adj[y][adjSize[y]++]=u;
    }
    int start;
    cout<<"Enter starting node for DFS: ";
    cin>>start;
    cout<<"DFS Traversal: ";
    DFS(start);
    return 0;
}