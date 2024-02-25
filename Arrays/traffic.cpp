// Problem statement
// The Road Department is planning to make some new traffic regulations. But to make the regulations they need to analyze the current situation of the traffic.
// The traffic can be analyzed from an array 'VEHICLE' of length 'N' , which consists of ‘0’ if there is no vehicle at that point and ‘1’ if there is a vehicle at the point.
// Unfortunately the array ‘VEHICLE’ got corrupted as at most 'M' '1' got flipped to ‘0’.
// Traffic jam is defined as the length of consecutive vehicles on the road.
// The Road Department wants to know the worst possible scenario for the traffic jam. Return the maximum possible length of the consecutive vehicles.
// Example:
// Input: ‘N’ = 3, ‘M’ = 1, VEHICLE’ = [0, 1, 1]
// Output: 3

// Explanation:
// As there is at most one 1 that got flipped to 0, so for the worst-case scenario we can reflip the first(1-based ) index to 1, resulting in a length of 3. 
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3 1
// 0 1 1
// Sample Output 1:
// 3
// Explanation Of Sample Input 1 :
// As there is at most one 1 that got flipped to 0, so for the worst-case scenario we can reflip the first index (1- based) to 1, resulting in a length of 3. 
// Sample Input 2 :
// 6 3
// 0 1 0 0 1 0
// Sample Output 2 :
// 5
// Constraints:
// 1  <= N <= 10^6
// 1 <= M <= N
// 0 <= VEHICLE[i] <= 1
// Time Limit: 1 sec

#include<bits/stdc++.h>
using namespace std;

int traffic(int n, int m, vector<int> arr) {
	int low = 0 , high =0  , count =0 , max_count =0;

	while(high < n){
		if(arr[high] == 0 && m == 0){
			if(arr[low] == 0){
				m++;
			}
			count--;
			low++;
		}
		else {
			if(arr[high] == 0){
				m--;
			}
			count++;
			high++;
		}

		max_count = max(max_count, count);
	}
	return max_count;
}