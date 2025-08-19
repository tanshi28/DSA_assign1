#include<iostream>
using namespace std;
int n;
int arr[100];
void create(){
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void display(){
    cout<<"Entered array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
void insert(){
    int p,a;
    cout<<"Enter position of elements:"<<endl;
    cin>>p;
    cout<<"Enter element:"<<endl;
    cin>>a;
    for(int i=n-1;i>=p-1;i--){
        arr[i+1]=arr[i];
    }
    arr[p-1]=a;
    n++;
}
void Delete(){
    int p;
    cout<<"Enter position of elements:"<<endl;
    cin>>p;
    for(int i=p-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;  
}
void linearSearch(){
    int e;
    cout<<"Enter element to search:"<<endl;
    cin>>e;
    bool ans=false;
    for(int i=0;i<n;i++){
        if(arr[i]==e){
            cout<<"Element found with position "<<i+1<<endl;
            ans=true;
            break;
        }
    }
    if(ans!=true){
        cout<<"Element not found "<<endl;
    }
}
int main(){
int num;
char c;
cout<<"Enter (Y/N):"<<endl;
cin>>c;
while(c=='Y' || c=='y'){
    cout<<"MENU"<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>num;
    switch(num){
        case 1:
        create();
        break;
        case 2:
        display();
        break;
        case 3:
        insert();
        break;
        case 4:
        Delete();
        break;
        case 5:
        linearSearch();
        break;
        case 6:
        cout<<"Exit Done"<<endl;
        break;
        default:
        cout<<"Invalid output!";
        break;
    }
cout<<"Enter (Y/N):"<<endl;
cin>>c;
}
return 0;
}