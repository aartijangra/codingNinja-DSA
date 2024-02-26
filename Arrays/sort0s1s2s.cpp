// Problem statement
// You have been given an array/list 'arr' consisting of 'n' elements.
// Each element in the array is either 0, 1 or 2.
// Sort this array/list in increasing order.
// Do not make a new array/list. Make changes in the given array/list.
// Example :
// Input: 'arr' = [2, 2, 2, 2, 0, 0, 1, 0]

// Output: Final 'arr' = [0, 0, 0, 1, 2, 2, 2, 2]

// Explanation: The array is sorted in increasing order.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 8
// 2 2 2 2 0 0 1 0
// Sample Output 1:
// 0 0 0 1 2 2 2 2
// Explanation of sample input 1 :
// The initial array 'arr' is [2, 2, 2, 2, 0, 0, 1, 0].

// After sorting the array in increasing order, 'arr' is equal to:
// [0, 0, 0, 1, 2, 2, 2, 2]

// Sample Input 2:
// 5
// 1 1 1 1 1

// Sample Output 2:
// 1 1 1 1 1

// Expected time complexity :
// The expected time complexity is O(n).
// Constraints:
// 1 <= 'n' <= 10 ^ 4
// 0 <= 'arr[i]' <= 2

// Time limit: 1 second
//brute force approach

// #include <bits/stdc++.h> 
// void sortArray(vector<int>& arr, int n)
// {
//     // Write your code here
//     int c1=0, c2=0, c3=0;
//     for(int i=0; i<n; i++){
//         if(arr[i] == 0) c1++;
//         else if(arr[i] == 1) c2++;
//         else if(arr[i] == 2) c3++;
//     }
//     for(int i=0; i<c1; i++){
//         arr[i] = 0;
//     }
//     for(int i=c1; i<c1+c2; i++){
//         arr[i] = 1;
//     }
//     for(int i=c1+c2; i<c1+c2+c3; i++){
//         arr[i] = 2;
//     }
// }

//optimal approach

#include <bits/stdc++.h> 
using namespace std;
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int low=0, mid=0, high=n-1;
    while(mid <= high){
        if(arr[mid] == 0){
        swap(arr[low] , arr[mid]);
        low++;
        mid++;
    }
    else if(arr[mid] == 1){
        mid++;
    }
    else if(arr[mid] == 2){
        swap(arr[mid] , arr[high]);
        high--;
    }

    }
    
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

