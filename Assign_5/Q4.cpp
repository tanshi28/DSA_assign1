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
void revList(){
    Node* p=NULL;
    Node* c=h;
    Node* t=NULL;
    while(c!=NULL){
        t=c->t;   
        c->t=p;   
        p=c;         
        c=t;         
    }
    h=p; 
}
void display(){
    Node* t=h;
    while(t!=NULL){
        cout<<t->d<<"->";
        t=t->t;
    }
    cout<<"NULL"<<endl;
}
int main(){
    insE(1);
    insE(2);
    insE(3);
    insE(4);
    cout<<"Original: ";
    display();
    revList();
    cout<<"Reversed: ";
    display();
    return 0;
}
