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
Node* insertBST(Node* root,int v){
    if(root==NULL){
        return createNode(v);
    }
    if(v<root->data){
        root->left=insertBST(root->left,v);
    }
    else if(v>root->data){
        root->right=insertBST(root->right,v);
    }
    return root;
}
Node* Rec(Node* root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return Rec(root->left,key);
    }
    return Rec(root->right,key);
}

Node* NonRec(Node* root,int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* findMax(Node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
Node* inorderSuccessor(Node* root,int key){
    Node* curr=Rec(root,key);
    if(curr==NULL){
        return NULL;
    }
    if(curr->right!=NULL){
        return findMin(curr->right);
    }
    Node* succ=NULL;
    Node* a=root;
    while(a!=curr){
        if(curr->data<a->data){
            succ=a;
            a=a->left;
        } else a=a->right;
    }
    return succ;
}
Node* inorderPredecessor(Node* root,int key){
    Node* curr=Rec(root,key);
    if(curr==NULL){
        return NULL;
    }
    if(curr->left!=NULL){
        return findMax(curr->left);
    }
    Node* pred=NULL;
    Node* a=root;
    while(a!=curr){
        if(curr->data>a->data){
            pred=a;
            a=a->right;
        } else a=a->left;
    }
    return pred;
}
int main(){
    Node* root=NULL;
    int n,v;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter values:";
    for(int i=0;i<n;i++){
        cin>>v;
        root=insertBST(root,v);
    }
    int key;
    cout<<"Enter search value:";
    cin>>key;
    Node* r=Rec(root,key);
    Node* q=NonRec(root,key);
    if(r){
        cout<<"Found(rec)";
    }
    else{
        cout<<"Not found(rec)";
    }
    if(q){
        cout<<"\nFound(nonrec)";
    }
    else{
        cout<<"\nNot found(nonrec)";
    }
    cout<<"\nMin:"<<findMin(root)->data;
    cout<<"\nMax:"<<findMax(root)->data;
    Node* s=inorderSuccessor(root,key);
    if(s){
        cout<<"\nSuccessor:"<<s->data;
    }
    else{
        cout<<"\nSuccessor:None";
    }
    Node* p=inorderPredecessor(root,key);
    if(p){
        cout<<"\nPredecessor:"<<p->data;
    }
    else{
        cout<<"\nPredecessor:None";
    }
    return 0;
}
