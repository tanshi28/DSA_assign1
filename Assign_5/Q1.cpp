#include<iostream>
using namespace std;
struct Node{
    int d;
    Node* t;
};
Node* h=NULL;
void insert(int x){
    Node* n=new Node();
    n->d=x;
    n->t=h;
    h=n;
    cout<<x<<" inserted at beg"<<endl;
}
void insertEnd(int x){
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
    cout<<x<<" inserted at end"<<endl;
}
void insB(int v,int x){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    if(h->d==v){
        insert(x);
        return;
    }
    Node* t=h;
    while(t->t!=NULL && t->t->d!=v){
        t=t->t;
    }
    if(t->t==NULL){
        cout<<"Value not found"<<endl;
    }
    else{
        Node* n=new Node();
        n->d=x;
        n->t=t->t;
        t->t=n;
        cout<<x<<" inserted before "<<v<<endl;
    }
}
void insA(int v,int x){
    Node* t=h;
    while(t!=NULL && t->d!=v){
        t=t->t;
    }
    if(t==NULL){
        cout<<"Vue not found"<<endl;
    }
    else{
        Node* n=new Node();
        n->d=x;
        n->t=t->t;
        t->t=n;
        cout<<x<<" inserted after "<<v<<endl;
    }
}
void delB(){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    Node* t=h;
    h=h->t;
    cout<<"Deleted "<<t->d<<" from beg"<<endl;
    delete t;
}
void delA(){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    if(h->t==NULL){
        cout<<"Deleted "<<h->d<<" from end"<<endl;
        delete h;
        h=NULL;
        return;
    }
    Node* t=h;
    while(t->t->t!=NULL){
        t=t->t;
    }
    cout<<"Deleted "<<t->t->d<<" from end"<<endl;
    delete t->t;
    t->t=NULL;
}
void delV(int x){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    if(h->d==x){
        delB();
        return;
    }
    Node* t=h;
    while(t->t!=NULL && t->t->d!=x){
        t=t->t;
    }
    if(t->t==NULL){
        cout<<"Value not found"<<endl;
    }
    else{
        Node* d=t->t;
        t->t=d->t;
        cout<<"Deleted "<<x<<endl;
        delete d;
    }
}
void search(int x){
    Node* t=h;
    int p=1;
    while(t!=NULL){
        if(t->d==x){
            cout<<x<<" found at p "<<p<<endl;
            return;
        }
        t=t->t;
        p++;
    }
    cout<<"Not found"<<endl;
}
void display(){
    if(h==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    Node* t=h;
    cout<<"List: ";
    while(t!=NULL){
        cout<<t->d<<"->";
        t=t->t;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int ch,x,v;
    cout<<"\n1.Insert Beg\n2.Insert End\n3.Insert Bef\n4.Insert After\n5.Del Beg\n6.Del End\n7.Del V\n8.Search\n9.Display\n0.Exit\n";
    do{
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch){
            case 1: 
            cout<<"Enter v:";
            cin>>x;
            insert(x);
            break;
            case 2: 
            cout<<"Enter v:";
            cin>>x;
            insertEnd(x);
            break;
            case 3: 
            cout<<"Enter target:";
            cin>>v;
            cout<<"Enter v:";
            cin>>x;
            insB(v,x);
            break;
            case 4: 
            cout<<"Enter target:";
            cin>>v;
            cout<<"Enter v:";
            cin>>x;
            insA(v,x);
            break;
            case 5: 
            delB();
            break;
            case 6: 
            delA();
            break;
            case 7: 
            cout<<"Enter v:";
            cin>>x;
            delV(x);
            break;
            case 8: 
            cout<<"Enter v:";
            cin>>x;
            search(x);
            break;
            case 9: 
            display();
            break;
            case 0: 
            cout<<"Exit"<<endl;
            break;
            default: 
            cout<<"Wrong choice"<<endl;
        }
    }while(ch!=0);
    return 0;
}
