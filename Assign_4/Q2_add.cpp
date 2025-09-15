#include<iostream>
using namespace std;
class Queue{
    int arr[100];
    int f,r;
public:
    Queue(){
        f=0;r=0;
    }
    bool isEmpty(){
        return f==r;
    }
    void enqueue(int x){
        arr[r++]=x;
    }
    void dequeue(){
        if(!isEmpty()) 
        f++;
    }
    int front(){
        return arr[f];
    }
    int size(){
        return r-f;
    }
};
int Min(Queue &q,int n){
    int size=q.size(),v=1e9;
    for(int i=0;i<size;i++){
        int c=q.front();
        q.dequeue();
        if(i<n && c<v){
            v=c;
        }
        q.enqueue(c);
    }
    return v;
}
void move(Queue &q,int n,int v){
    int size=q.size();
    bool moved=false;
    for(int i=0;i<size;i++){
        int c=q.front();
        q.dequeue();
        if(i<n && c==v && !moved){
            moved=true;
        }
        else{
            q.enqueue(c);
        }
    }
    q.enqueue(v);
}
void sortQueue(Queue &q){
    int n=q.size();
    for(int i=0;i<n;i++){
        int v=Min(q,n-i);
        move(q,n-i,v);
    }
}
int main(){
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);
    sortQueue(q);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }
    return 0;
}
