#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements of sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        while(a[i+1]-a[i]>1){
            cout<<a[i]+1<<endl;
            a[i]++;
        }
    }
    return 0;
}