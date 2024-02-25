// Problem statement
// Sam want to read exactly ‘TARGET’ number of pages.

// He has an array ‘BOOK’ containing the number of pages for ‘N’ books.

// Return YES/NO, if it is possible for him to read any 2 books and he can meet his ‘TARGET’ number of pages.

// Example:
// Input: ‘N’ = 5, ‘TARGET’ = 5
// ‘BOOK’ = [4, 1, 2, 3, 1] 

// Output: YES
// Explanation:
// Sam can buy 4 pages book and 1 page book.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5 5
// 4 1 2 3 1
// Sample Output 1 :
// YES
// Explanation Of Sample Input 1:
// Sam can buy 4 pages book and 1-page book.
// Sample Input 2:
// 2 1
// 1 2
// Sample Output 2 :
// NO
// Expected Time Complexity:
// O( N ), Where N is the length of the array.
// Constraints:
// 1  <= N <= 10^3
// 1 <= BOOK[i], TARGET <= 10^6
// Time Limit: 1 sec

//bruteforce approach
#include<bits/stdc++.h>
using namespace std;
string read(int n, vector<int> book, int target)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            
            if(book[i]+book[j] == target){
                return "YES";
            }
            
        }
    
    }
    return "NO";   
    
}


//hash-map
#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}

//2pointer approach
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int left =0;
    int right = n-1;
    while(left<right){
        int sum = book[left]+book[right];
        if(sum==target){
            return "YES";
        }
        else if(sum<target) left++;
        else right--;
    }
    return "NO";
}

