// Problem statement
// You are given an integer ‘n’.
// Your task is to return an array containing integers from 1 to ‘n’ (in increasing order) without using loops.
// Example:
// Input: ‘n’ = 5
// Output: 1 2 3 4 5
// Explanation: An array containing integers from ‘1’ to ‘n’ is [1, 2, 3, 4, 5].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1 :
// 1 2 3 4 5
// Explanation Of Sample Input 1:
// The array contains all integers from 1 to 5 in ascending order.
// Sample Input 2:
// 2
// Sample Output 2:
// 1 2
// Explanation Of Sample Input 2:
// The array contains all integers from 1 to 2 in ascending order.
// Expected Time Complexity:
// The expected time complexity is O(n), where 'n' is the given integer.
// Constraints:
// 1 <= n <= 10^6

// Time Limit: 1-sec


#include<bits\stdc++.h>
using namespace std;

vector<int> printNos(int x) {
   if (x == 1) {
       // Base case: When x reaches 1, return 1 in vector
       return {1};
   } 
       // Recursive case:

       // 1. Get the numbers from x-1 recursively
       vector<int> result = printNos(x - 1);
       result.push_back(x);

       return result;
   
}

int main() {
   int n;
   cin >> n;
   vector<int> numbers = printNos(n);
   for (int num : numbers) {
       cout << num << " ";
   }
   cout << endl;

   return 0;
}


