#include<iostream>
using namespace std;
int main(){
    int students[]={1,1,0,0};
    int sandwiches[]={0,1,0,1};
    int q[100];
    int n=4,f=0,r=n;
    int top=0,count=0;
    for(int i=0;i<n;i++){
        q[i]=students[i];
    }
    while(f<r && count<r-f){
        if(q[f]==sandwiches[top]){
            f++;
            top++;
            count=0;
        }
        else{
            q[r++]=q[f];
            f++;
            count++;
        }
    }
    cout<<r-f;
    return 0;
}
