#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head=NULL;
void insertEnd(int v) {
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}
bool isCircular(){
    if(head==NULL)
        return false;
    Node* temp=head->next;
    while(temp!=NULL && temp!=head) {
        temp=temp->next;
    }
    return(temp==head);
}
int main() {
    insertEnd(2);
    insertEnd(4);
    insertEnd(6);
    insertEnd(7);
    insertEnd(5);
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head;
    if (isCircular())
        cout<<"True";
    else
        cout<<"False";
    return 0;
}