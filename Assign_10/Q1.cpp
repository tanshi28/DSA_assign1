#include <iostream>
using namespace std;
const int SIZE=100;
struct HashSet{
    int table[SIZE];
    HashSet(){
        for(int i=0;i<SIZE;i++){
            table[i]=0;
        }
    }
    int hashF(int key){
        return (key%SIZE+SIZE)%SIZE;
    }
    bool contains(int key){
        int idx=hashF(key);
        int start=idx;
        while(table[idx]!=0){
            if(table[idx]==key){
                return true;
            }
            idx=(idx+1)%SIZE;
            if(idx==start){
                return false;
            }
        }
        return false;
    }
    void insertKey(int key){
        int idx=hashF(key);
        while(table[idx]!=0){
            idx=(idx+1)%SIZE;
        }
        table[idx]=key;
    }
};
int main(){
    int nums[]={1,2,3,1};
    int n=4;
    HashSet hs;
    for(int i=0;i<n;i++){
        if(hs.contains(nums[i])){
            cout<<"true";
            return 0;
        }
        hs.insertKey(nums[i]);
    }
    cout<<"false";
}
