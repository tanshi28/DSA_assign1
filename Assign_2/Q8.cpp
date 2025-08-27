#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                break;
            }
        }
        if(j==i){
            count++;
        }
    }
    cout<<"Distinct elements:"<<count<<endl;
    return 0;
}