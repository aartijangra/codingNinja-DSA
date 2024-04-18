// Merge Two Sorted Arrays Without Extra Space
// Problem statement
// Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.



// You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.



// Note:
// You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
// For example:
// When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}. 
// We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
// Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3 4
// 1 8 8
// 2 3 4 5
// Sample Output 1:
// 1 2 3 4 5 8 8
// Explanation Of Sample Input 1:
// We have ‘A’ = {1, 8, 8} and ‘B’ = {2, 3, 4, 5}. 
// Merging the two arrays results in {1, 2, 3, 4, 5, 8, 8}.
// Hence the answer is {1, 2, 3, 4, 5, 8, 8}, where ‘A’ contains {1, 2, 3} and ‘B’ contains {4, 5, 8, 8}.
// Sample Input 2:
// 4 5
// 1 1 1 1 
// 2 2 3 3 5
// Sample Output 2:
// 1 1 1 1 2 2 3 3 5
// Constraints:
// 1 <= N <= 10^5
// 1 <= M <= 10^5
// 0 <= A[i] <= 10^9
// 0 <= B[i] <= 10^9

// The sum of ‘N + M’ over all test cases does not exceed 2 * 10^5.
// Time Limit: 1-sec


//brute force approach in which we use extra space which should not be used 
//TC O(n+m) + O(n+m)
//SC O(n+m)
#include<bits/stdc++.h>
using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	long long c[n+m];
	int left = 0;
	int right = 0;
	int index = 0;

	while(left<n && right<m){
		if(a[left]<b[right]){
			c[index]=a[left];
			index++; left++;
		}
		else{
			c[index]=b[right];
			right++; index++;
		}
	}
	while(left<n){
		c[index]=a[left];
			index++; left++;
	}
	while(right<m){
		c[index]=b[right];
			right++; index++;
	}

	for(int i=0; i<n+m; i++)
	{
		if(i<n){
			a[i]=c[i];
		}
		else{
			b[i-n]=c[i];
		}
	}
	
}
int main()
{
    long long a[] = {1, 4, 8, 10};
    long long b[] = {2, 3, 9};
    int n = 4, m = 3;
    // mergeTwoSortedArraysWithoutExtraSpace(a,b);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}


//optimal approach 1
#include<bits/stdc++.h>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int left = n-1;
	int right = 0;
	while(left>=0 && right<m){
		if(a[left]>b[right]){
			swap(a[left],b[right]);
			left--; right++;
		}
		else{
			break;
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	
}

//optimal approach 2 ---- GAP method
#include<bits/stdc++.h>

void swapIfGreater(vector<long long> &a, vector<long long> &b, int ind1, int ind2){
	if(a[ind1] > b[ind2]){
			swap(a[ind1],b[ind2]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int len = n+m;
	int gap = (len/2)+(len%2);

	while(gap>0){
		int left = 0;
		int right = left+gap;
		while(right<len){
			//arr1 and arr2
			if(left<n && right>=n){
				swapIfGreater(a,b,left,right-n);
			}
			//arr2 and arr2
			else if(left>=n){
				swapIfGreater(b,b,left-n,right-n);
			}
			//arr1 and arr1
			else{
				swapIfGreater(a,a,left,right);
			}
			left++; right++;
		}
		if(gap == 1) break;
		gap = (gap/2) + (gap%2);
	}
		
}
