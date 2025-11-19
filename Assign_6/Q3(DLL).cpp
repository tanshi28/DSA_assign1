#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head=NULL;
void insertEnd(int v){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL) {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
int sizeDLL(){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    cout<<"Size of Doubly Linked List:"<<sizeDLL()<<endl;
    return 0;
}