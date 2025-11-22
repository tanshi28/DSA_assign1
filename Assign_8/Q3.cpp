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
    else if(v>root->data){
        root->right=ins(root->right,v);
    }
    return root;
}
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* del(Node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=del(root->left,key);
    }
    else if(key>root->data){
        root->right=del(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* t=root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL){
            Node* t=root->left;
            delete root;
            return t;
        }
        Node* t=findMin(root->right);
        root->data=t->data;
        root->right=del(root->right,t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return (l>r?l:r)+1;
}
int minDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    if(l==0 || r==0){
        return l+r+1;
    }
    return (l<r?l:r)+1;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=NULL;
    int n,v;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter values:";
    for(int i=0;i<n;i++){
        cin>>v;
        root=ins(root,v);
    }
    cout<<"Inorder:"<<endl;
    inorder(root);
    cout<<"Max depth:"<<maxDepth(root)<<endl;
    cout<<"Min depth:"<<minDepth(root)<<endl;
    int d;
    cout<<"Enter value to delete:"<<endl;
    cin>>d;
    root=del(root,d);
    cout<<"Inorder after delete:"<<endl;
    inorder(root);
    return 0;
}
