// Problem statement
// Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Increasing Number Triangle.
// Example:
// Input: ‘N’ = 3
// Output: 
// 1
// 2 3
// 4 5 6
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1  <= T <= 10
// 1  <= N <= 20
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 1
// 2 3
// 4 5 6
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1
// 2 3
// 4 5 6 
// 7 8 9 10
// Sample Input 3 :
// 7
// Sample Output 3 :
// 1
// 2 3
// 4 5 6 
// 7 8 9 10
// 11 12 13 14 15 
// 16 17 18 19 20 21 
// 22 23 24 25 26 27 28

#include<iostream>
using namespace std;
void nNumberTriangle(int n) {
    // Write your code here.
    int num=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    nNumberTriangle(n);
}