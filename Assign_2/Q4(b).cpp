#include<iostream>
using namespace std;
int main(){
    char s[100];
    cout<<"Enter name:"<<endl;
    cin.getline(s,100);
    int l=0;
    while(s[l]!=0){
        l++;
    }
    cout<<"Reversed string:";
    for(int i=l;i>=0;i--){
        cout<<s[i];
    }
    return 0;
}