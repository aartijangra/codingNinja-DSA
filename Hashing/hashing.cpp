#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    //pre compute
    int hash[13]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]+=1;
    }
    
    //fetch
    int q;   //how many numbers we'll fetch
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number];
    }

    return 0;
}