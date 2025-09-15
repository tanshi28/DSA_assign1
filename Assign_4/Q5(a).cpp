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
    Queue q1,q2;
public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.getF());
            q1.pop();
        }
        Queue temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        if(q1.empty()){
            cout<<"Empty"<<endl;
        }else{
            cout<<q1.getF()<<" removed"<<endl;
            q1.pop();
        }
    }
    void top(){
        if(q1.empty()){
            cout<<"Empty"<<endl;
        }else{
            cout<<"Top="<<q1.getF()<<endl;
        }
    }
    void display(){
        Queue t=q1;
        while(!t.empty()){
            cout<<t.getF()<<" ";
            t.pop();
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    s.push(10);s.push(20);s.push(30);
    s.display();
    s.pop();
    s.top();
    s.display();
    return 0;
}
