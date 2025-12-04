#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
const int SIZE=100;
struct HashSet{
    Node* table[SIZE];
    HashSet(){
        for(int i=0;i<SIZE;i++)table[i]=NULL;
    }
    int hashF(Node* p){
        long long v=(long long)p;
        return (v%SIZE+SIZE)%SIZE;
    }
    bool contains(Node* p){
        int idx=hashF(p);
        int start=idx;
        while(table[idx]!=NULL){
            if(table[idx]==p){
                return true;
            }
            idx=(idx+1)%SIZE;
            if(idx==start){
                return false;
            }
        }
        return false;
    }
    void insertPtr(Node* p){
        int idx=hashF(p);
        while(table[idx]!=NULL){
            idx=(idx+1)%SIZE;
        }
        table[idx]=p;
    }
};
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    HashSet hs;
    Node* temp=a;
    while(temp!=NULL){
        if(hs.contains(temp)){
            cout<<"true";
            return 0;
        }
        hs.insertPtr(temp);
        temp=temp->next;
    }
    cout<<"false";
}
