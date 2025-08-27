#include<iostream>
using namespace std;
void transpose(){
    int r1,c1;
    cout<<"Enter number of rows:"<<endl;
    cin>>r1;
    cout<<"Enter number of columns:"<<endl;
    cin>>c1;
    int a1[r1][c1];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<r1;i++){
       for(int j=0;j<c1;j++){
           cin>>a1[i][j];
        }
    }
    int trans[c1][r1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            trans[j][i]=a1[i][j];
        }
    }
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            cout<<trans[i][j]<<" ";
        }
    }
}
int main(){
    transpose();
    return 0;
}