// Problem statement
// Sam is curious about Alpha-Ramp, so he decided to create Alpha-Ramp of different sizes.
// An Alpha-Ramp is represented by a triangle, where alphabets are filled from the top in order.
// For every value of ‘N’, help sam to return the corresponding Alpha-Ramp.

// Example:
// Input: ‘N’ = 3

// Output: 
// A
// B B
// C C C
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1  <= N <= 25
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// A
// B B
// C C C
// Sample Input 2 :
// 1
// Sample Output 2 :
// A
// Sample Input 3 :
// 4
// Sample Output 3 :
// A
// B B
// C C C
// D D D D


#include<iostream>
using namespace std;
void alphaRamp(int n) {
    // Write your code here.
    
    for(int i=n; i>=1; i--){
        char letter='A';
        for(int j=1; j<=i; j++){
            cout<<letter<<" ";
            letter++;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    alphaRamp(n);

}