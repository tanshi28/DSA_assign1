#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
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
void display(){
    if(head==NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<endl;
}
int main(){
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);
    cout<<"Circular List:"<<endl;
    display(); 
    return 0;
}