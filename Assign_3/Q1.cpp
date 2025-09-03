#include<iostream>
using namespace std;
#define MAX 100
class Stack{
    public:
    int arr[MAX];
    int top=-1;
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(top==MAX-1){
        return true;
    }
    else{
        return false;
    }
}
void push(int a){
    if(isFull()){
        cout<<"Stack is full"<<endl;
    }
    else{
        top++;
        arr[top]=a;
    }
}
void pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<arr[top]<<endl;
        top--;
    }
}
void peek(){
    cout<<arr[top]<<endl;
}
void display(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    Stack s;
    int c;
    do{
        cout<<"Enter choice:"<<endl;
        cin>>c;
        switch(c){
            case 1:
            int a;
            cout<<"Enter number:"<<endl;
            cin>>a;
            s.push(a);
            break;
            case 2:
            s.pop();
            break;
            case 3:
            s.peek();
            break;
            case 4:
            s.display();
            break;
            case 5:
            s.isEmpty();
            break;
            case 6:
            s.isFull();
            break;
            default:
            cout<<"Invalid input"<<endl;
        }
    }while(c!=7);
    return 0;
}