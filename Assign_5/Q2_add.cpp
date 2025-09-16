#include<iostream>
using namespace std;
struct Node{
    int d;
    Node* t;
    Node(int x){
        d=x;
        t=NULL;
    }
};
Node* revK(Node* h,int k){
    if(h==NULL){
        return NULL;
    }
    Node* c=h;
    Node* p=NULL;
    Node* t=NULL;
    int count=0;
    Node* temp=h;
    int check=0;
    while(temp!=NULL && check<k){
        temp=temp->t;
        check++;
    }
    if(check<k){
        return h;
    }
    while(c!=NULL && count<k){
        t=c->t;
        c->t=p;
        p=c;
        c=t;
        count++;
    }
    if(t!=NULL){
        h->t=revK(t,k);
    }
    return p;
}
void insE(Node*& h,int x){
    Node* n=new Node(x);
    if(h==NULL){
        h=n;
        return;
    }
    Node* t=h;
    while(t->t!=NULL){
        t=t->t;
    }
    t->t=n;
}
void display(Node* h){
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
    Node* h=NULL;
    int arr[]={1,2,3,4,5,6,7,8,9};
    for(int x:arr) insE(h,x);
    cout<<"Original: ";
    display(h);
    int k=3;
    h=revK(h,k);
    cout<<"Reversed in groups of "<<k<<": ";
    display(h);
    return 0;
}
