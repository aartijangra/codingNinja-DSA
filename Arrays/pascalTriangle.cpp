// Problem statement
// You are given an integer ‘N’. You need to return the first ‘N’ rows of Pascal’s triangle.

// Example:

// Input:
// N = 4
// Output:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// Explanation: The output matrix has the first four rows of Pascal’s Triangle. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 30
// Time Limit: 1 sec
// Sample Input 1:
// 5
// Sample Output 1:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// Explanation Of Sample Input 1:
// Input:
// N = 5

// Output:
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// Explanation: The output matrix has the first five rows of Pascal’s Triangle.
// Sample Input 2:
// 3
// Sample Output 2:
// 1 
// 1 1
// 1 2 1
// Sample Input 3:
// 4
// Sample Output 3:
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 

//optimal
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}