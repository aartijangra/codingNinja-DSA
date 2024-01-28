// Problem statement
// You are given an integer ‘n’.
// Your task is to return an array containing integers from ‘n’ to ‘1’ (in decreasing order) without using loops.
// Note:
// In the output, you will see the array returned by you.
// Example:
// Input: ‘n’ = 5
// Output: 5 4 3 2 1
// Explanation: An array containing integers from ‘n’ to ‘1’ is [5, 4, 3, 2, 1].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1 :
// 5 4 3 2 1
// Explanation Of Sample Input 1:
// Input: ‘n’ = 5

// Output: 5 4 3 2 1

// Explanation: An array containing integers from ‘5’ to ‘1’ is [5, 4, 3, 2, 1].
// Sample Input 2:
// 2
// Sample Output 2:
// 2 1
// Explanation Of Sample Input 2:
// Input: ‘n’ = 2

// Output: 2 1

// Explanation: An array containing integers from ‘2’ to ‘1’ is [2, 1].
// Expected Time Complexity:
// The expected time complexity is O(n), where 'n' is the given integer.
// Expected Space Complexity:
// The expected space complexity is O(n), where 'n' is the given integer.
// Constraints:
// 1 <= n <= 10^4

// Time Limit: 1-sec

#include<bits/stdc++.h>
using namespace std;
 vector<int> printNos(int x) {
    // Write Your Code Here
    if(x==0) return{};
        vector<int> res=printNos(x-1);
            res.insert(res.begin(),x);
                return res;
}
int main(){
    int x;
    cin>>x;
    vector<int> res= printNos(x);
    for(auto it: res){             //to print a vector
        cout<<it<<" ";
    }
}