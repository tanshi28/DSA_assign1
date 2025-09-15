#include<iostream>
using namespace std;
class Queue{
    char arr[100];
    int f,r;
public:
    Queue(){
        f=0;
        r=0;
    }
    bool empty(){
        return f==r;
    }
    void push(char x){
        arr[r++]=x;
    }
    void pop(){
        if(!empty()){
            f++;
        }
    }
    char getF(){
        if(!empty()){
            return arr[f];
        }
        return '\0';
    }
};
int main(){
    string s="a a b c";
    Queue q;
    int f[256]={0};
    for(char ch:s){
        if(ch==' '){
            continue;
        }
        f[ch]++;
        q.push(ch);
        while(!q.empty() && f[q.getF()]>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1 ";
        }else{
            cout<<q.getF()<<" ";
        }
    }
    return 0;
}

