#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head=NULL;
void insert(int v,int p){
    Node* newNode=new Node;
    newNode->data=v;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    if(head->next==NULL){
        head->next=newNode;
        newNode->prev=head;
        return;
    }
    if(p==1){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    Node* temp=head;
    int count=1;
    while(temp!=NULL && count<p-1){
        temp=temp->next;
        count++;
    }
    if(count==p-1){
        if(temp->next==NULL){
            temp->next=newNode;
            newNode->prev=temp;
            return;
        }
        else{
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
            return;
        }
    }
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
    insert(2,1);
    insert(3,2);
    insert(4,3);
    insert(0,2);
    display();
    return 0;
}