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
void add(Sparse a[],Sparse b[],Sparse c[]){
    if(a[0].r!=b[0].r||a[0].c!=b[0].c){
        cout<<"Matrix cannot be added"<<endl;
    }
    int i=1,j=1,k=1;
    while(i<=a[0].v && j<=b[0].v){
        if(a[i].r<b[j].r||a[i].r==b[j].r && a[i].c<b[j].c){
            c[k]=a[i];
            k++;
            i++;
        }
        else if(b[j].r<a[i].r||b[j].r==a[i].r && b[j].c<a[i].c){
            c[k]=b[j];
            k++;
            j++;
        }
        else{
            c[k]=a[i];
            c[k++].v=a[i++].v+b[j++].v;
        }
    }
        while(i<=a[0].v){
            c[k++]=a[i++];
        }
        while(j<=b[0].v){
            c[k++]=b[j++];
        }
        c[0].r=a[0].r;
        c[0].c=a[0].c;
        c[0].v=k-1;
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
    add(a,b,d);
    display(d,d[0].v+1);
    return 0;
}