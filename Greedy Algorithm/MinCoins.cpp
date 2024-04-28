// Find Minimum Number Of Coins
// Problem statement
// Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.



// Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in decreasing order.



// For Example
// For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
// Note
// It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1
// 13
// Sample Output 1
// 10 2 1
// Explanation of Sample Input 1
// The minimum number of coins to change is 3 {1, 2, 10}.
// Sample Input 2
// 50
// Sample Output 2
// 50
// Constraints
// 1 <= 'N' <= 10^5

// Time Limit: 1 sec

#include<bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> res;
       int coins[] = {1,2,5,10,20,50,100,500,1000};
       int size = 9;
	   for(int i=size-1; i>=0; i--) {
	       while(coins[i] <= n) {
	           n-=coins[i];
	           res.push_back(coins[i]);
	           if(n==0) break;
	       }
	   }
	   
	   return res;
}