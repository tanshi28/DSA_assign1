#include<iostream>
using namespace std;
int main(){
    int n,s;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    s=n*(n+1)/2;
    int a[s];
    cout<<"Enter elements of matrix:"<<endl;
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    cout<<"Upper triangular matrix elements:"<<endl;
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}