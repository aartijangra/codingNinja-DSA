// Problem statement
// You are given an array 'a' of size 'n' and an integer 'k'.



// Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



// Example :
// Input: ‘n’ = 7 ‘k’ = 3
// ‘a’ = [1, 2, 3, 1, 1, 1, 1]

// Output: 3

// Explanation: Subarrays whose sum = ‘3’ are:

// [1, 2], [3], [1, 1, 1] and [1, 1, 1]

// Here, the length of the longest subarray is 3, which is our final answer.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 7 3
// 1 2 3 1 1 1 1


// Sample Output 1 :
// 3


// Explanation Of Sample Input 1 :
// Subarrays whose sum = ‘3’ are:
// [1, 2], [3], [1, 1, 1] and [1, 1, 1]
// Here, the length of the longest subarray is 3, which is our final answer.


// Sample Input 2 :
// 4 2
// 1 2 1 3


// Sample Output 2 :
// 1


// Sample Input 3 :
// 5 2
// 2 2 4 1 2 


// Sample Output 3 :
// 1


// Expected time complexity :
// The expected time complexity is O(n).


// Constraints :
// 1 <= 'n' <= 5 * 10 ^ 6
// 1 <= 'k' <= 10^18
// 0 <= 'a[i]' <= 10 ^ 9

// Time Limit: 1-second

//brute force approach with TC O(n2)

#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    int len = 0;
    for(int i=0; i<n; i++){
        long long sum = 0;
        for(int j=i; j<n; j++){
            sum+=a[j];
            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

//better ----hashing
#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    unordered_map <int,int>  mpp;
    int len = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == k){
            len = max(len,i+1);
        }
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len2 = i - mpp[rem];
            len = max(len,len2);
        }
        if(mpp.find(sum) == mpp.end()) mpp[sum] = i;
    }
    return len;
}


//optimal approach
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int left = 0, right=0;
    long long sum = a[0];
    int len = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            len = max(len, right-left+1);
        }
        right++;
        if(right<n) sum+=a[right];
    }
    return len;
}