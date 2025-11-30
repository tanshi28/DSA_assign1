#include <iostream>
using namespace std;
#define MAX 100   
int adj[MAX][MAX];   
int adjSize[MAX];    
int arr[MAX];
int front=0,rear=-1;
void enqueue(int x){
    arr[++rear]=x;
}
int dequeue(){
    return arr[front++];
}
bool isEmpty(){
    return front>rear;
}
void BFS(int s, int v){
    bool visited[MAX]={false};
    enqueue(s);
    visited[s]=true;
    cout<<"BFS Traversal: ";
    while(!isEmpty()){
        int node=dequeue();
        cout<<node<<" ";
        for(int i=0;i<adjSize[node];i++) {
            int n=adj[node][i];
            if(!visited[n]){
                visited[n]=true;
                enqueue(n);
            }
        }
    }
}
int main() {
    int v, e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;
    for(int i=0;i<v;i++){
        adjSize[i]=0;
    }
    cout<<"Enter edges:"<<endl;
    for(int i=0;i<e;i++) {
        int u, y;
        cin>>u>>y;
        adj[u][adjSize[u]++] = y;
        adj[y][adjSize[y]++] = u;
    }
    int s;
    cout<<"Enter starting node: ";
    cin>>s;
    BFS(s,v);
    return 0;
}