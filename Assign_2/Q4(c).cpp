#include<iostream>
using namespace std;
int main(){
    char s[100];
    cout<<"Enter name:"<<endl;
    cin.getline(s,100);
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    cout<<"Updated string:";
    for(int i=0;i<=l;i++){
        if(s[i]=='a' || s[i]=='e'|| s[i]=='i' ||s[i]=='o'||s[i]=='u'){
            continue;
        }
        else{
            cout<<s[i];
        }
    }
    return 0;
}