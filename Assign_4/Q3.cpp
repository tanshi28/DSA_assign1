#include<iostream>
#include<queue>
using namespace std;
void ilQueue(queue<int> &q){
    if(q.size()%2!=0){
        cout<<"Queue has odd no. of elements"<<endl;
        return;
    }
    int n=q.size()/2;
    queue<int> q1;
    for(int i=0;i<n;i++){
        q1.push(q.front());
        q.pop();
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
}
int main(){
    queue<int> q;
    int arr[]={4,7,11,20,5,9};
    int n=6;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    cout<<"Original Queue: ";
    queue<int> temp=q;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
    ilQueue(q);
    cout<<"Interleaved Queue:";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
