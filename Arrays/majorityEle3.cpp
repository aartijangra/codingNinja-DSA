// Problem statement
// Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.

// A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.

// Note: The floor function returns the number rounded down to the nearest integer.

// Note: Return the array of majority elements in sorted order.

// Example:
// Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

// Output: 1

// Explanation: The frequency of ‘1’ is 5, which is greater than floor(N / 3), hence ‘1’ is the majority element.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 1e3
// -1e9 <= A[i] <= 1e9

// Time Limit: 1-sec
// Sample Input 1:
// 6
// 1 1 1 2 2 2
// Sample Output 1:
// 1 2
// Explanation Of Sample Input 1:
// Input: ‘N’ = 6, ‘A’ = [1, 1, 1, 2, 2, 2]

// Output: [1, 2]

// Explanation: The frequency of ‘1’ and ‘2’ is 3, which is greater than floor(N / 3), hence ‘1’ & ‘2’ are the majority elements.
// Sample Input 2:
// 1
// 4
// Sample Output 2:
// 4


//brute force approach
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}


//better approach---hashing
vector<int> majorityElement(vector<int> v) {
	// Write your code here
    int n = v.size();
    map <int,int> mpp;
    vector<int> ls;
    int mini = (int)(n/3) + 1;

    for(int i=0; i<n; i++){
        mpp[v[i]]++;
        if(mpp[v[i]] == mini){
            ls.push_back(v[i]);
        }
        if(ls.size() == 2) break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}

// optimal approach
