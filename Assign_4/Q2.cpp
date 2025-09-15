#include<iostream>
using namespace std;
#define MAX 50   
class Queue{
    int arr[MAX];
    int f,r;
public:
    Queue(){
        f=-1;
        r=-1;
    }
    bool isEmpty(){
        if(f==-1 && r==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if((r+1)%MAX==f){
            return true;
        }
        return false;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Overflow"<<endl;
            return;
        }
        if(isEmpty()){
            f=r=0;
        }
        else{
            r=(r+1)%MAX;
        }
        arr[r]=x;
        cout<<x<<" inserted"<<endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        cout<<arr[f]<<" removed"<<endl;
        if(f==r){
            f=r=-1; 
        }
        else{
            f=(f+1)%MAX;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"Empty"<<endl;
        }
        else{
            cout<<"Front="<<arr[f]<<endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Empty"<<endl;
            return;
        }
        cout<<"Queue: ";
        int i=f;
        while(true){
            cout<<arr[i]<<" ";
            if(i==r){
                break;
            }
            i=(i+1)%MAX;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int ch,v;
    do{
        cout<<"Enter choice:(1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Is_Empty 6.Is_Full 7.Exit)"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter element:"<<endl;
            cin>>v;
            q.enqueue(v);
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.peek();
            break;
            case 4:
            q.display();
            break;
            case 5:
            if(q.isEmpty()){
                cout<<"Empty"<<endl;
            }
            else{
                cout<<"Not Empty"<<endl;
            }
            break;
            case 6:
            if(q.isFull()){
                cout<<"Full"<<endl;
            }
            else{
                cout<<"Not full"<<endl;
            }
            break;
            case 7:
            cout<<"Taking exit"<<endl;
            break;
            default:
            cout<<"Wrong choice"<<endl;
        }
    }while(ch!=7);
    return 0;
}

