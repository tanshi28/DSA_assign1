#include<iostream>
using namespace std;
int main(){
    int a[7]={64,34,25,12,22,11,90};
    for(int i=0;i<7-1;i++){
        for(int j=0;j<7-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"Sorted array:"<<endl;
    for(int j=0;j<7;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}