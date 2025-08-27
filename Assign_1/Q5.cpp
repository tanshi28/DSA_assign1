#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter number of rows:"<<endl;
    cin>>r;
    cout<<"Enter number of columns:"<<endl;
    cin>>c;
    int a[r][c];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++){
        int sumR=0;
        for(int j=0;j<c;j++){
            sumR=sumR+a[i][j];
        }
        cout<<"Sum of row "<<i+1<<" elements:"<<sumR<<endl;
    }
    for(int i=0;i<c;i++){
        int sumC=0;
        for(int j=0;j<r;j++){
            sumC=sumC+a[j][i];
        }
        cout<<"Sum of column "<<i+1<<" elements:"<<sumC<<endl;
    }
    return 0;
}