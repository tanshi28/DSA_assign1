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
int search(){
    if(h==NULL){
        return -1;
    }
    Node* s=h;
    Node* f=h;
    while(f!=NULL && f->t!=NULL){
        s=s->t;
        f=f->t->t;
    }
    return s->d;
}
void display(){
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
    insE(3);
    insE(4);
    insE(5);
    cout<<"List: ";
    display();
    int mid=search();
    cout<<"Middle: "<<mid<<endl;
    return 0;
}
