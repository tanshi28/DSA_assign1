#include<iostream>
using namespace std;
int main(){
    char s[100];
    cout<<"Enter string:"<<endl;
    cin.getline(s,100);
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-i-1;j++){
            if(s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    cout<<"Updated string:"<<s;
    return 0;
}