#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertBeg(int v) {
    Node* newNode=new Node;
    newNode->data = v;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
    head=newNode;
}
void insertEnd(int v) {
    Node* newNode=new Node;
    newNode->data=v;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void insertAft(int v,int p) {
    if(head==NULL){
        cout<<"List is empty"<<endl;;
        return;
    }
    Node* temp=head;
    do{
        if(temp->data==p){
            Node* newNode=new Node;
            newNode->data=v;
            newNode->next=temp->next;
            temp->next=newNode;
            return;
        }
        temp=temp->next;
    } while(temp!=head);
    cout<<"Key not found"<<endl;
}
void insertBef(int v,int p) {
    if(head==NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    if (head->data==p) {
        insertBeg(v);
        return;
    }
    Node* temp=head;
    Node* prev=NULL;
    do{
        prev=temp;
        temp=temp->next;
        if(temp->data==p){
            Node* newNode=new Node;
            newNode->data=v;
            newNode->next=temp;
            prev->next=newNode;
            return;
        }
    } while(temp!=head);
    cout<<"Key not found"<<endl;
}
void del(int p) {
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    Node* prev=NULL;
    if(head->data==p){
        if(head->next==head){
            delete head;
            head=NULL;
            return;
        }
        Node* last=head;
        while(last->next!=head){
            last=last->next;
        }
        last->next=head->next;
        temp=head;
        head=head->next;
        delete temp;
        return;
    }
    do{
        prev=temp;
        temp=temp->next;
        if(temp->data==p){
            prev->next=temp->next;
            delete temp;
            return;
        }
    }while(temp!=head);
    cout<<"Node not found"<<endl;
}
void display(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
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
            cout<<"Enter position:"<<endl;
            cin>>v;
            del(p);
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
