#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head=NULL;
void insertBeg(int v){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    } 
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
    return;
}
void insertEnd(int v){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    } 
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
}
void insertAft(int v,int p){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL && count<p){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        cout<<"Position invalid"<<endl;
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev=newNode;
        newNode->next=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void insertBef(int v,int p){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    if(p==0){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL && count<p-1){
        temp=temp->next;
        count++;
    }
    temp->prev->next=newNode;
    newNode->prev=temp->prev;
    temp->prev=newNode;
    newNode->next=temp;
}
void del(int v){
    if(head==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL && temp->data!=v){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Value not found"<<endl;
        return;
    }
    if(head->data==v){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        delete temp;
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    delete temp;
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int n,v,p;
    cout<<"MENU:\n1.Insertion at begginning\n2.Insertion at end\n3.Insertion after a position\n4.Insertion before a position\n5.Deletion of a node\n6.Display list"<<endl;
    do{
        cout<<"Enter choice:"<<endl;
        cin>>n;
        switch(n){
            case 1:
            cout<<"Enter value:"<<endl;
            cin>>v;
            insertBeg(v);
            break;
            case 2:
            cout<<"Enter value:"<<endl;
            cin>>v;
            insertEnd(v);
            break;
            case 3:
            cout<<"Enter value:"<<endl;
            cin>>v;
            cout<<"Enter position:"<<endl;
            cin>>p;
            insertAft(v,p);
            break;
            case 4:
            cout<<"Enter value:"<<endl;
            cin>>v;
            cout<<"Enter position:"<<endl;
            cin>>p;
            insertBef(v,p);
            break;
            case 5:
            cout<<"Enter value:"<<endl;
            cin>>v;
            del(v);
            break;
            case 6:
            display();
            break;
            default:
            cout<<"Enter a choice"<<endl;
            break;
        }
    }while(true);
    return 0;
}