// Find X raised to power N
// Problem statement
// You are given two numbers ’x’(it’s a float), and ’n’(it’s a integer).



// Your task is to calculate ‘x’ raised to power ‘n’, and return it.



// The expected time complexity is ’O(logn)’, and the expected space complexity is ’O(1)’, where ‘n’ is the power to which the number should be raised.



// Note:
// In the output, you will see the number returned by you upto 6 decimal places.

// Example:
// Input: ‘x’ = 10, ‘n’ = 4

// Output: 10000.000000

// Explanation: On raising ‘x’ to the power of ‘n’, the result is 10000.
//  <br> 
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 10 4

// Sample Output 1 :
// 10000.000000

// Explanation Of Sample Input 1:
// Input: ‘x’ = 10, ‘n’ = 4

// Output: 10000.000000

// Explanation: On raising ‘x’ to the power of ‘n’, the result is 10000.
// <br> 
// Sample Input 2:
// 3.7 3

// Sample Output 2:
// 50.653000

// Explanation Of Sample Input 2:
// Input: ‘x’ = 3.7, ‘n’ = 3

// Output: 50.653000

// Explanation: On raising ‘x’ to the power of ‘n’, the result is 50.653.

// Constraints:
// -9 <= n <= 9
// 1 <= x <= 50

// Time Limit: 1-sec

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    // Write Your Code Here
    double ans = 1.0;
    long long nn = n;
    if(nn<0) nn = -1 * nn;

    while(nn){
        if(nn%2==0){
            //even
            x = x*x;
            nn = nn/2;
        }
        else{
            //odd
            ans = ans*x;
            nn = nn-1;
        }
    }
    if(n<0) ans = (double)(1.0) / (double)(ans);
    return ans;
}