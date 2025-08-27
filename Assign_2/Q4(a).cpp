#include<iostream>
using namespace std;
int main(){
    char s[100],s1[100];
    cout<<"Enter first name:"<<endl;
    cin.getline(s,100);
    cout<<"Enter last name:"<<endl;
    cin.getline(s1,100);
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    int j=0;
    while(s1[j]!='\0'){
        s[i]=s1[j];
        j++;
        i++;
    }
    s[i]='\0';
    cout<<"Updated string:"<<s<<endl;
    return 0;
}