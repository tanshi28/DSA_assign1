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
    else root->right=ins(root->right,v);
    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    cout<<"Preorder:";
    preorder(root);
    cout<<"\nInorder:";
    inorder(root);
    cout<<"\nPostorder:";
    postorder(root);
    return 0;
}
