#include<iostream>
using namespace std;
struct Node{
    int c,p;
    Node* t;
    Node(int x,int y){
        c=x;
        p=y;
        t=NULL;
    }
};
void insE(Node*& h,int c,int p){
    Node* n=new Node(c,p);
    if(h==NULL){
        h=n;
        return;
    }
    Node* cur=h;
    while(cur->t!=NULL){
        cur=cur->t;
    }
    cur->t=n;
}
void display(Node* h){
    Node* c=h;
    while(c!=NULL){
        cout<<"["<<c->c<<","<<c->p<<"]";
        if(c->t!=NULL) cout<<"->";
        c=c->t;
    }
    cout<<endl;
}
Node* add(Node* h1,Node* h2){
    Node* r=NULL;
    while(h1!=NULL&&h2!=NULL){
        if(h1->p==h2->p){
            insE(r,h1->c+h2->c,h1->p);
            h1=h1->t;
            h2=h2->t;
        }else if(h1->p>h2->p){
            insE(r,h1->c,h1->p);
            h1=h1->t;
        }else{
            insE(r,h2->c,h2->p);
            h2=h2->t;
        }
    }
    while(h1!=NULL){
        insE(r,h1->c,h1->p);
        h1=h1->t;
    }
    while(h2!=NULL){
        insE(r,h2->c,h2->p);
        h2=h2->t;
    }
    return r;
}
int main(){
    Node* h1=NULL;
    Node* h2=NULL;
    insE(h1,5,2);
    insE(h1,4,1);
    insE(h1,2,0);
    insE(h2,5,1);
    insE(h2,5,0);
    cout<<"Poly1: ";
    display(h1);
    cout<<"Poly2: ";
    display(h2);
    Node* sum=add(h1,h2);
    cout<<"result: ";
    display(sum);
    return 0;
}
