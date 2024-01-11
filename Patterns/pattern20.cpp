// Problem statement

// Sam is curious about symmetric patterns, so he decided to create one.

// For every value of ‘N’, return the symmetry as shown in the example.

// Example:
// Input: ‘N’ = 3

// Output: 
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1  <= N <= 25
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *
// Sample Input 2 :
// 1
// Sample Output 2 :
// *

#include<iostream>
using namespace std;
void symmetry(int n) {
    // Write your code here.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        int space = 2*n - 2*i ;
        for(int j=1; j<=space; j++){
            cout<<"  ";
        }

        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        int space = 2*n - 2*i ;
        for(int j=1; j<=space; j++){
            cout<<"  ";
        }

        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    symmetry(n);

}
