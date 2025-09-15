#include<iostream>
using namespace std;
class Queue{
    string arr[100];
    int f,r;
public:
    Queue(){
        f=0;
        r=0;
    }
    bool empty(){
        return f==r;
    }
    void push(string x){
        arr[r++]=x;
    }
    void pop(){
        if(!empty()){
            f++;
        }
    }
    string getF(){
        if(!empty()){
            return arr[f];
        }
        return "";
    }
};
void Binary(int n){
    Queue q;
    q.push("1");
    for(int i=1;i<=n;i++){
        string s=q.getF();
        cout<<s<<" ";
        q.pop();
        q.push(s+"0");
        q.push(s+"1");
    }
}
int main(){
    int n=2;
    Binary(n);
    return 0;
}
