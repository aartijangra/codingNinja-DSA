// Longest Substring Without Repeating Characters
// Problem statement
// Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.

// Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
//  1<= n <=10^5

// Time Limit: 1 sec
// Sample Input 1:
//  abcabcbb 
// Sample Output1:
//  3
// Explanation For Sample Input 1:
// Substring "abc" has no repeating character with the length of 3.
// Sample Input 2:
//  aaaa
// Sample Output 2:
// 1


//optimal sol 1  TC=O(2N) SC=O(N)
#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    int l = 0;
    unordered_set<int> st;
    int maxlen = INT_MIN;
    for(int r=0; r<n; r++){
        if(st.find(input[r]) != st.end()){
            while(l<r && st.find(input[r]) != st.end()){
                st.erase(input[l]);
                l++;
            }
        }
        st.insert(input[r]);
        maxlen = max(maxlen, r-l+1);
    }

    return maxlen;
}

//optimal sol 2 ---  TC = O(N)
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    vector<int> mpp(256, -1);
    int left = 0; int right = 0;
    int len = 0;

    while(right < n){
        if(mpp[input[right]] != -1)
            left = max(left, mpp[input[right]]+1 );
        mpp[input[right]] = right;
        len = max(len, right-left+1);
        right++;
        
    }

    return len;
}

 
      