#include <iostream>
using namespace std;
const int SIZE=100;
struct Node{
    int key;
    int freq;
    bool used;
    Node(){
        key=0;
        freq=0;
        used=false;
    }
};
struct HashMap{
    Node table[SIZE];
    int hashF(int key){
        return (key%SIZE+SIZE)%SIZE;
    }
    void put(int key){
        int idx=hashF(key);
        while(table[idx].used && table[idx].key!=key){
            idx=(idx+1)%SIZE;
        }
        if(!table[idx].used){
            table[idx].key=key;
            table[idx].freq=1;
            table[idx].used=true;
        }
        else{
            table[idx].freq++;
        }
    }
    void printAll(){
        for(int i=0;i<SIZE;i++){
            if(table[i].used){
                cout<<table[i].key<<" -> "<<table[i].freq<<" times"<<endl;
            }
        }
    }
};
int main(){
    int nums[]={2,3,2,4,3,2};
    int n=6;
    HashMap mp;
    for(int i=0;i<n;i++){
        mp.put(nums[i]);
    }
    mp.printAll();
}
