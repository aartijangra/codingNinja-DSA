// Fractional Knapsack
// Problem statement
// You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.

// Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

// Note:
// You are allowed to break the items.
// Example:
// If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
// Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00   
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 5000
// 1 <= W <= 10^5
// 1 <= weights[i] <= 10^5
// 1 <= values[i] <= 10^5

// Time limit: 1 sec
// Sample Input 1:
// 1
// 6 200
// 50 40 90 120 10 200 
// 40 50 25 100 30 45
// Sample output 1:
// 204.00
// Explanation of Sample output 1:
// The most optimal way to fill the knapsack is to choose full items with weight 10 and value 30, weight 40 and value 50, weight 120 and value 100. Then take weight 30 from the item with weight 50 and value 40.

// The total value =  30 + 50 + 100 + (30/50)*(40) = 204.00
// Sample Input 2:
// 1
// 5 100
// 20 24 36 40 42
// 12 35 41 25 32
// Sample output 2:
// 106.48

#include <bits/stdc++.h> 
using namespace std;

bool static comparator(pair<int, int> &a, pair<int, int> &b){
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);

    int currentWeight = 0;
    double finalvalue = 0.0;

    for(int i=0; i<n; i++){
        if(currentWeight + items[i].first <= w){
            currentWeight +=  items[i].first;
            finalvalue += items[i].second;
        }
        else{
            int remain = w - currentWeight;
            finalvalue += ( items[i].second / (double) items[i].first) * (double) remain;
            break;
        }
    }
    return finalvalue;
}