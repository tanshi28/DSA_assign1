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
    int getFreq(int key){
        int idx=hashF(key);
        int start=idx;
        while(table[idx].used){
            if(table[idx].key==key){
                return table[idx].freq;
            }
            idx=(idx+1)%SIZE;
            if(idx==start){
                return 0;
            }
        }
        return 0;
    }
};
int main(){
    int arr[]={4,5,1,2,0,4};
    int n=6;
    HashMap mp;
    for(int i=0;i<n;i++){
        mp.put(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(mp.getFreq(arr[i])==1){
            cout<<arr[i];
            return 0;
        }
    }
}
