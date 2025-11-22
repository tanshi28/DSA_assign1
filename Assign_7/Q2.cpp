#include<iostream>
using namespace std;
void sort(int arr[],int n){
    int left=0,right=n-1;
    while(left<right){
        int min=left,max=right;
        for(int i=left;i<=right;i++){
            if(arr[i]<arr[min]){
                min=i;
            }
            if(arr[i]>arr[max]){
                max=i;
            }
        }
        int temp=arr[left];
        arr[left]=arr[min];
        arr[min]=temp;
        if(max==left){
            max=min;
        }
        temp=arr[right];
        arr[right]=arr[max];
        arr[max]=temp;
        left++;
        right--;
    }
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}