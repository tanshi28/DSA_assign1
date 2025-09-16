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
void insE(Node*& h,int x){
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
void rmLoop(Node* h){
    if(h==NULL||h->t==NULL){
        return;
    }
    Node* s=h;
    Node* f=h;
    bool loop=false;
    while(f!=NULL&&f->t!=NULL){
        s=s->t;
        f=f->t->t;
        if(s==f){
            loop=true;
            break;
        }
    }
    if(loop){
        s=h;
        if(s==f){ 
            while(f->t!=s){
                f=f->t;
            }
        }else{
            while(s->t!=f->t){
                s=s->t;
                f=f->t;
            }
        }
        f->t=NULL;
    }
}
int main(){
    Node* h=NULL;
    insE(h,1);
    insE(h,7);
    insE(h,3);
    insE(h,6);
    h->t->t->t->t=h->t;
    rmLoop(h);
    display(h);
    return 0;
}
