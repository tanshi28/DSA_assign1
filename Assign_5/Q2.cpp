#include<iostream>
using namespace std;
struct Node{
    int d;
    Node* t;
};
Node* h=NULL;
void insE(int x){
    Node* n=new Node();
    n->d=x;
    n->t=NULL;
    if(h==NULL){
        h=n;
    }
    else{
        Node* t=h;
        while(t->t!=NULL){
            t=t->t;
        }
        t->t=n;
    }
}
int del(int key){
    int count=0;
    while(h!=NULL && h->d==key){
        Node* temp=h;
        h=h->t;
        delete temp;
        count++;
    }
    Node* t=h;
    while(t!=NULL && t->t!=NULL){
        if(t->t->d==key){
            Node* temp=t->t;
            t->t=temp->t;
            delete temp;
            count++;
        }else{
            t=t->t;
        }
    }
    return count;
}

void display(){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    Node* t=h;
    while(t!=NULL){
        cout<<t->d;
        if(t->t!=NULL){
            cout<<"->";
        }
        t=t->t;
    }
    cout<<endl;
}

int main(){
    insE(1);
    insE(2);
    insE(1);
    insE(2);
    insE(1);
    insE(3);
    insE(1);
    cout<<"Original List: ";
    display();
    int key=1;
    int c=del(key);
    cout<<"Count: "<<c<<endl;
    cout<<"Updated List: ";
    display();
    return 0;
}
