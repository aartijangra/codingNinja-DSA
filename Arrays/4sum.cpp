// Problem statement
// You are given an array ‘NUMS’ of length ‘N’. You are also given an integer ‘TARGET’.



// Return an array of all the unique quadruplets [ ‘NUMS[ a ]’, ‘NUMS[ b ]’, ‘NUMS[ c ]’, ‘NUMS[ d ]’ ] with the following conditions:



// i. 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.

// ii. NUMS[ a ] + NUMS[ b ] + NUMS[ c ] +NUMS[ d ] = TARGET



// Return the array in any order.



// Note:


// (NUMS[ a ], NUMS[ b ], NUMS[ c ], NUMS[ d ]), (NUMS[ a ], NUMS[ d ], NUMS[ c ], NUMS[ b ]), (NUMS[ a ], NUMS[ c ], NUMS[ b ], NUMS[ d ])... all of them are treated or considered the same quadruplets.



// Two quadruplets are different if there is any integer in one quadruplet which is not in the other.



// The solution will be verified by the number of valid quadruplets returned. In the output, only the number of valid quadruplets will be printed.



// Example:
// Input: ‘N’ = 5,  ‘TARGET’ = 5, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]

// Output: 1.

// There is only one unique quadruplet with sum = 5 and that is [1, 2, 1, 1].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6 8
// 2 2 2 2 1 3
// Sample Output 1 :
// 2
// Explanation Of Sample Input 1:
// (2+2+2+2) = (2+2+1+3) = 4.
// Sample Input 2:
// 4 4
// 1 1 1 0
// Sample Output 2 :
// 0
// Constraints :
// 4 <= N <= 100
// -10^6 <= NUMS[ i ] <= 10^6
// -10^6 <= TARGET <= 10^6


// Time Limit: 1 sec
//better approach---hashing
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                // taking bigger data type
                // to avoid integer overflow:
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


//optimal approach
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n ;j++){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    
                    if((int)(sum) == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if((int)(sum)<target) k++;
                    else l--;
                }
                
            }
        }
         
        return ans;
    
}