// Missing and repeating numbers

// Problem statement
// You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.

// Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.

// Your task is to find the missing number (M) and the repeating number (R).

// For example:
// Consider an array of size six. The elements of the array are { 6, 4, 3, 5, 5, 1 }. 
// The array should contain elements from one to six. Here, 2 is not present and 5 is occurring twice. Thus, 2 is the missing number (M) and 5 is the repeating number (R). 
// Follow Up
// Can you do this in linear time and constant additional space? 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 2 <= N <= 5 * 10^4
// 1 <= data <= N

// Where ‘N’ is the size of the array and ‘data’ denotes the value of the elements of the array. 


//brute force approach



#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}


//better approach --- hashing
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int hash[n+1] = {0};
	for(int i=0; i<n; i++){
		hash[arr[i]] ++;

	}
	int repeat=-1; int miss=-1;
	for(int i=1; i<=n; i++){
		if(hash[i] == 2) repeat = i;
		else if(hash[i] == 0) miss = i;

		if(repeat != -1 && miss!=-1) break;
	}
	return {miss,repeat};
	
}


//optimal approach--- basic maths
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, long long int n)
{
	// Write your code here 
	
	long long SN = (n * (n+1)) / 2;
	long long S2N = (n * (n+1) * (2*n+1)) / 6;
	long long s = 0 , s2 = 0;

	for(int i=0; i<n; i++){
		s+=arr[i];
		s2+= (long long)arr[i] * (long long)arr[i];
	}

	long long val1 = s - SN;
	long long val2 = s2 - S2N;
	val2 = val2 / val1;
	long long x = (val1+val2) / 2;
	long long y = x - val1;

	return {(int)y, (int)x};
	
}




