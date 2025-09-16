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
void insE(Node* &h,int x){
    Node* n=new Node(x);
    if(h==NULL){
        h=n;
        return;
    }
    Node* c=h;
    while(c->t!=NULL){
        c=c->t;
    }
    c->t=n;
}
void display(Node* h){
    Node* c=h;
    while(c!=NULL){
        cout<<c->d;
        if(c->t!=NULL){
            cout<<"->";
        }
        c=c->t;
    }
    cout<<endl;
}
Node* rotL(Node* h,int k){
    if(h==NULL||h->t==NULL||k==0){
        return h;
    }
    int len=1;
    Node* e=h;
    while(e->t!=NULL){
        e=e->t;
        len++;
    }
    k=k%len;
    if(k==0){
        return h;
    }
    Node* c=h;
    for(int i=1;i<k;i++){
        c=c->t;
    }
    Node* newH=c->t;
    c->t=NULL;
    e->t=h;
    return newH;
}
int main(){
    Node* h=NULL;
    int arr[]={10,20,30,40,50};
    for(int x:arr){
        insE(h,x);
    }
    cout<<"Original: ";
    display(h);
    int k=4;
    h=rotL(h,k);
    cout<<"Rotated left by "<<k<<": ";
    display(h);
    return 0;
}
