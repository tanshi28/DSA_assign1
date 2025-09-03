#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    public:
    char arr[MAX];
    int top=-1;
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void isFull(){
        if(top==MAX-1){
            cout<<"Stack is full"<<endl;
        }
        else{
            cout<<"Stack is not full"<<endl;
        }
    }
    void push(char c){
        if(top==MAX-1){
            cout<<"Stack is full"<<endl;
        }
        else{
            top++;
            arr[top]=c;
        }
    }
    char pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<arr[top];
            top--;
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    string t;
    cout<<"Enter a string:"<<endl;
    getline(cin,t);
    int l=t.length();
    Stack s;
    for(int i=0;i<l;i++){
        s.push(t[i]);
    }
    string reversed="";
    while(!s.isEmpty()){
        reversed+=s.pop();
    }
    return 0;
}