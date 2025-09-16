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
Node* get(Node* h1, Node* h2){
    if(h1==NULL || h2==NULL){
        return NULL;
    }
    Node* p1=h1;
    Node* p2=h2;
    while(p1!=p2){
        p1=(p1==NULL)?h2:p1->t;
        p2=(p2==NULL)?h1:p2->t;
    }
    return p1;
}
int main(){
    Node* h1=new Node(4);
    h1->t=new Node(1);
    Node* i=new Node(8);
    h1->t->t=i;
    i->t=new Node(5);
    Node* h2=new Node(5);
    h2->t=new Node(6);
    h2->t->t=new Node(1);
    h2->t->t->t=i;
    Node* ans=get(h1,h2);
    if(ans){
        cout<<"Intersected at "<<ans->d<<endl;
    }
    else{
        cout<<"No "<<endl;
    }
    return 0;
}
