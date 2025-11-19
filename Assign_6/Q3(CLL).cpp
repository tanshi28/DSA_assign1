#include<iostream>
using namespace std;
struct Node {
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
    temp->next=newNode;
    newNode->next=head;
}
int sizeCLL(){
    if(head==NULL)
        return 0;
    int count=0;
    Node* temp=head;
    do{
        count++;
        temp = temp->next;
    }while(temp!=head);
    return count;
}
int main() {
    insertEnd(5);
    insertEnd(15);
    insertEnd(25);
    insertEnd(35);
    insertEnd(45);
    cout << "Size of Circular Linked List:"<<sizeCLL()<<endl;
    return 0;
}