#include<iostream>
using namespace std;
struct Sparse{
    int r,c,v;
};
void display(Sparse s[],int n){
    for(int i=0;i<n;i++){
        cout<<s[i].r<<" "<<s[i].c<<" "<<s[i].v<<endl;
    }
}
void transpose(Sparse a[],Sparse b[]){
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    int k=1;
    for(int i=0;i<a[0].c;i++){
        for(int j=1;j<=a[0].v;j++){
            if(a[j].c==i){
                b[k].r=a[j].c;
                b[k].c=a[j].r;
                b[k].v=a[j].v;
                k++;
            }
        }
    }
}
int main(){
    int r,c,v;
    Sparse a[100],b[100];
    cout<<"Enter number of rows for a:"<<endl;
    cin>>r;
    a[0].r=r;
    cout<<"Enter number of columns for a:"<<endl;
    cin>>c;
    a[0].c=c;
    cout<<"Enter number of values for a:"<<endl;
    cin>>v;
    a[0].v=v;
    cout<<"Enter rows,columns,values:"<<endl;
    for(int i=1;i<=v;i++){
        cin>>a[i].r;
        cin>>a[i].c;
        cin>>a[i].v;
    }
    transpose(a,b);
    display(b,v+1);
    return 0;
}