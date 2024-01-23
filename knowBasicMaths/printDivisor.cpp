//print all divisors 

//first approach its time complexity is O(n)
/*

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    return 0;
    
}


*/


//second approach 

#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> ls;

    //for(int i=1; i<=sqrt(n); i++)    sqrt is a mathematical function which will call and take more time 
    // 6*6<=36
    // 7*7<=36 false
    
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            ls.push_back(i);
            if((n/i)!=i){
                ls.push_back(n/i);
            }
        }
    }

    sort(ls.begin(), ls.end());
    for(auto it: ls){
        cout<<it<<" ";
    }


}
