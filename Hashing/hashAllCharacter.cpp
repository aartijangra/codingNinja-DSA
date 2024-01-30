#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    
    //pre compute
    int hash[256]={0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]+=1;
    }
    
    //fetch
    int q;   //how many numbers we'll fetch
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c];
    }

    return 0;
}