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
void multiply(Sparse a[],Sparse b[],Sparse p[]){
    if(a[0].c!=b[0].r){
        cout<<"Matrix cannot be multiplied"<<endl;
    }
    int temp[100][100]={0};
    for(int i=1;i<=a[0].v;i++){
        for(int j=1;j<=b[0].v;j++){
            if(a[i].c==b[j].r){
                temp[a[i].r][b[j].c]+=a[i].v*b[j].v;
            }
        }
    }
    p[0].r=a[0].r;
    p[0].c=b[0].c;
    int k=1;
    for(int i=0;i<a[0].r;i++){
        for(int j=0;j<b[0].c;j++){
            if(temp[i][j]!=0){
                p[k].r=i;
                p[k].c=j;
                p[k].v=temp[i][j];
                k++;
            }
        }
    }
    p[0].v=k-1;
}
int main(){
    int r,c,v;
    Sparse a[100],b[100],d[100];
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
    int r1,c1,v1;
    cout<<"Enter number of rows for b:"<<endl;
    cin>>r1;
    b[0].r=r1;
    cout<<"Enter number of columns for b:"<<endl;
    cin>>c1;
    b[0].c=c1;
    cout<<"Enter number of values for b:"<<endl;
    cin>>v1;
    b[0].v=v1;
    cout<<"Enter rows,columns,values:"<<endl;
    for(int i=1;i<=v1;i++){
        cin>>b[i].r;
        cin>>b[i].c;
        cin>>b[i].v;
    }
    multiply(a,b,d);
    display(d,d[0].v+1);
    return 0;
}
