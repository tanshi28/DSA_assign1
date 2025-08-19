#include<iostream>
using namespace std;
void remove(int n){
    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    cout<<"Updated array:"<<endl;
    for(int j=0;j<n;j++){
        cout<<arr[j]<<endl;
    }
}
int main(){
    remove(5);
}