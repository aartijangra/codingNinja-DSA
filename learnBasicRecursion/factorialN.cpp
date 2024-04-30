//factorial of a number using recursion

#include<bits/stdc++.h>
using namespace std;


long long factorial(long long n){
     if(n==0 || n==1) return 1;
    return n*factorial(n-1);
}

int main(){
    int n;
    cout<<"enter the number ";
    cin>>n;
    cout<<"factorial is: "<<factorial(n);

}