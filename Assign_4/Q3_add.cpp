#include<iostream>
using namespace std;
class Queue{
    int arr[100],f,r;
public:
    Queue(){
        f=0;
        r=0;
    }
    bool empty(){
        return f==r;
    }
    void enqueue(int x){
        arr[r++]=x;
    }
    void dequeue(){
        if(!empty()){
            f++;
        }
    }
    int front(){
        return arr[f];
    }
};
class stack{
    int arr[100],t;
public:
    stack(){
        t=-1;
    }
    bool empty(){
        return t==-1;
    }
    void push(int x){
        arr[++t]=x;
    }
    void pop(){
        if(!empty()){
            t--;
        }
    }
    int peek(){
        return arr[t];
    }
};
bool check(Queue &q,int total){
    stack s;
    int r=1;
    while(!q.empty()){
        int cur=q.front();q.dequeue();
        if(cur==r){
            r++;
        }
        else{
            while(!s.empty()&&s.peek()==r){
                s.pop();
                r++;
            }
            if(!s.empty()&&s.peek()<cur){
                return false;
            }
            s.push(cur);
        }
    }
    while(!s.empty()&&s.peek()==r){
        s.pop();
        r++;
    }
    return r==total+1;
}
int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    int n=5;
    if(check(q,n)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
