#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int v){
    Node* n=new Node;
    n->data=v;
    n->left=NULL;
    n->right=NULL;
    return n;
}
Node* ins(Node* root,int v){
    if(root==NULL){
        return createNode(v);
    }
    if(v<root->data){
        root->left=ins(root->left,v);
    }
    else{
        root->right=ins(root->right,v);
    }
    return root;
}
bool checkBST(Node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    return checkBST(root->left,min,root->data-1)&&checkBST(root->right,root->data+1,max);
}
bool isBST(Node* root){
    return checkBST(root,-1000000,1000000);
}
int main(){
    Node* root=NULL;
    int n,v;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter values:";
    for(int i=0;i<n;i++){
        cin>>v;
        root=ins(root,v);
    }
    if(isBST(root)){
        cout<<"BST";
    }
    else{
        cout<<"Not BST";
    }
    return 0;
}
