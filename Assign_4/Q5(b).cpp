#include<iostream>
using namespace std;
class Queue{
    int arr[100];
    int f,r;
public:
    Queue(){
        f=0;
        r=0;
    }
    bool empty(){
        return f==r;
    }
    int size(){
        return r-f;
    }
    void push(int x){
        arr[r++]=x;
    }
    void pop(){
        if(!empty()){
            f++;
        }
    }
    int getF(){
        if(!empty()){
            return arr[f];
        }
        return -1;
    }
};
class Stack{
    Queue q;
public:
    void push(int x){
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;i++){
            q.push(q.getF());
            q.pop();
        }
    }
    void pop(){
        if(q.empty()){
            cout<<"Empty"<<endl;
        }else{
            cout<<q.getF()<<" removed"<<endl;
            q.pop();
        }
    }
    void top(){
        if(q.empty()){
            cout<<"Empty"<<endl;
        }else{
            cout<<"Top="<<q.getF()<<endl;
        }
    }
    void display(){
        Queue temp=q;
        while(!temp.empty()){
            cout<<temp.getF()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.top();
    s.display();
    return 0;
}
