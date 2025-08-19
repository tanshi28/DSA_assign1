#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Reversed array:"<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<endl;
    }
    return 0;
}