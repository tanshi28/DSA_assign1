#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter sorted array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    int start=0;
    cout<<"Enter element to search:"<<endl;
    cin>>key;
    int end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid<key){
            start=mid+1;
        }
        else if(mid>key){
            end=mid-1;
        }
        else{
            cout<<"Element found at position "<<mid<<endl;
            break;
        }
    }
    return 0;
}