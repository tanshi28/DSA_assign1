#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
const int SIZE=100;
struct HashSet{
    int table[SIZE];
    HashSet(){
        for(int i=0;i<SIZE;i++){
            table[i]=0;
        }
    }
    int hashF(int key){
        return (key%SIZE+SIZE)%SIZE;
    }
    bool contains(int key){
        int idx=hashF(key);
        int start=idx;
        while(table[idx]!=0){
            if(table[idx]==key){
                return true;
            }
            idx=(idx+1)%SIZE;
            if(idx==start){
                return false;
            }
        }
        return false;
    }
    void insertKey(int key){
        int idx=hashF(key);
        while(table[idx]!=0){
            idx=(idx+1)%SIZE;
        }
        table[idx]=key;
    }
};

bool check(Node* root,HashSet& hs){
    if(root==NULL){
        return false;
    }
    if(hs.contains(root->data)){
        return true;
    }
    hs.insertKey(root->data);
    return (check(root->left,hs) || check(root->right,hs));
}

int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(3);
    HashSet hs;
    if(check(root,hs)){
        cout<<"Duplicates Found";
    }
    else{
        cout<<"No Duplicates";
    }
}
