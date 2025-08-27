#include<iostream>
using namespace std;
int main(){
    char s[100];
    cout<<"Enter string:"<<endl;
    cin.getline(s,100);
    int l=0;
    int i = 0;
    while (s[i]!='\0'){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
        i++;
    }
    cout<<"Updated string:"<<s<<endl;
    return 0;
}