// Problem statement
// There is an integer array ‘A’ of size ‘N’.

// A sequence is successive when the adjacent elements of the sequence have a difference of 1.

// You must return the length of the longest successive sequence.

// Note:

// You can reorder the array to form a sequence.
// For example,

// Input:
// A = [5, 8, 3, 2, 1, 4], N = 6
// Output:
// 5
// Explanation:
// The resultant sequence can be 1, 2, 3, 4, 5.
// The length of the sequence is 5.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10^5
// 1 <= A[i] <= 10^9
// Time Limit: 1 sec

// brute force approach
#include <bits/stdc++.h>
using namespace std;

bool ls(vector<int> &a, int num)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            return true;
        }
    }
    return false;
}

int longestSuccessiveElements(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        while (ls(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
