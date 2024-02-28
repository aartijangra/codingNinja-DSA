// Problem statement
// You are given an array ‘a’ of ‘n’ integers.
// You have to return the lexicographically next to greater permutation.
// Note:

// If such a sequence is impossible, it must be rearranged in the lowest possible order.
// Example:

// Input: 'a' = [1, 3, 2]
// Output: 2 1 3
// Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of [1, 3, 2] is [2, 1, 3].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3
// 3 1 2
// Sample Output 1:
// 3 2 1
// Explanation Of Sample Input 1:
// Input:
// A = [3, 1, 2]
// Output:
// 3 2 1

// Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of [3, 1, 2] is [3, 2, 1].


// Sample Input 2:
// 3
// 3 2 1
// Sample Output 2:
// 1 2 3
// Constraints:
// 1 <= n <= 100
// 1 <= a[ i ] <= 100
// Time Limit: 1 sec

//by using STL
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

//optimal aproach
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n = A.size();
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin() , A.end());
        return A;
    } 
    else{
        for(int i=n-1; i>=ind; i--){
        if(A[i] > A[ind]){
            swap(A[i],A[ind]);
            break;
        }
    }
    //reverse(A,ind+1,n-1);
    reverse(A.begin()+ind+1 , A.end());

    }
    
    return A;
}

int main(){
    vector<int> A = {2,1,5,4,3,0,0};
    vector<int> Ans = nextGreaterPermutation(A);
    for(auto it: Ans){
        cout<<it;
    }
    return 0;
}