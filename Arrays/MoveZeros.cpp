// Problem statement
// Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping the non-zero elements at the start of the array in their original order. Return the modified array.



// Example :
// Input: ‘n’ = 5, ‘arr’ = [1, 2, 0, 0, 2, 3]
// Output: [1, 2, 2, 3, 0, 0]

// Explanation: Moved all the 0’s to the end of an array, and the rest of the elements retain the order at the start.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample input 1:
// 4
// 0 0 0 1 
// Sample output 1:
// 1 0 0 0 
// Explanation of sample input 1:
// Output: [1, 0, 0, 0]

// We move all the 0’s to the end of an array, and the rest of the elements retained the order at the start.
// Sample input 2:
// 5
// 4 0 3 2 5 
// Sample output 2:
// 4 3 2 5 0 
// Explanation of sample input 2:
// Output: [4, 3, 2, 5, 0]

// we move all the 0’s to the end of an array, and the rest of the elements retained the order at the start.
// Expected time complexity:
//  The expected time complexity is O(n).
// Constraints:
// 1 ≤ n ≤ 10^6
// 0 ≤ arr[i] ≤ 10^9

// Time limit: 1 sec


// //brute force approach
#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(a[i] != 0){
            temp.push_back(a[i]);
        }
        
    }

    for(int i=0; i<temp.size(); i++){
        a[i]=temp[i];
    }

    for(int i=temp.size(); i<n; i++){
        a[i]=0;
    }
    return a;
}

//optimal approach
#include<bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int j=-1;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            j=i;
            break;
        }
    }
    if(j==-1) return a;
    for(int i=j+1; i<n; i++){
        if(a[i] != 0){
            swap(a[i] , a[j]);
            j++;
        }
    }
    return a;
}


//Moore's voting algorithm
//optimal approach
int majorityElement(vector<int> v) {
	int n= v.size();
	int cnt=0;
	int el;
	for(int i=0; i<n; i++){
		if(cnt==0){
			el = v[i];
			cnt =1;
		}
		else if(v[i] == el){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	int cnt1=0;
	for(int i=0; i<n; i++){
		if(v[i] == el) cnt1++;
	}

	if(cnt1 > n/2) return el;
	else return -1;
}