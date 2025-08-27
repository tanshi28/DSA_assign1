#include<iostream>
using namespace std;
void matrix(){
    int r1,c1,r2,c2;
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
    cout<<"Enter number of rows:"<<endl;
    cin>>r2;
    cout<<"Enter number of columns:"<<endl;
    cin>>c2;
    int a2[r2][c2];
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>a2[i][j];
        }
    }
    int ans[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++){
                ans[i][j]+=a1[i][k]*a2[k][j];
            }
        }
    }
    cout<<"Matrix multiplication:"<<endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<ans[i][j]<<" ";
        }
    }
}
int main(){
    matrix();
    return 0;
}