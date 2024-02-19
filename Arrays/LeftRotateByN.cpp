
// roblem statement
// Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.



// Example:
// 'arr '= [1,2,3,4,5]
// 'k' = 1  rotated array = [2,3,4,5,1]
// 'k' = 2  rotated array = [3,4,5,1,2]
// 'k' = 3  rotated array = [4,5,1,2,3] and so on.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 8
// 7 5 2 11 2 43 1 1
// 2
// Sample Output 1:
// 2 11 2 43 1 1 7 5
// Explanation of Sample Input 1:
// Rotate 1 steps to the left: 5 2 11 2 43 1 1 7
// Rotate 2 steps to the left: 2 11 2 43 1 1 7 5
// Sample Input 2:
// 4
// 5 6 7 8
// 3
// Sample Output 2:
// 8 5 6 7
// Explanation of Sample Input 2:
// Rotate 1 steps to the left: 6 7 8 5
// Rotate 2 steps to the left: 7 8 5 6
// Rotate 2 steps to the left: 8 5 6 7
// Expected Time Complexity:
// O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
// Constraints:
// 1 <= 'n' <= 10^3
// 1 <= 'arr'[i] <= 10^9
// 1 <= 'k' < 'n'

/*
//brute force approach
#include <iostream>
using namespace std;
void Rotatetoleft(int arr[], int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = 0; i < k; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < n - k; i++)
  {
    arr[i] = arr[i + k];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = temp[i - n + k];
  }
}
int main()
{
  int n = 7;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int k = 2;
  Rotatetoleft(arr, n, k);
  cout << "After Rotating the elements to left " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}

*/
//optimal approach
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>arr, int start, int end){
    while(start<+end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end--;
    }

}
vector<int> rotateArray(vector<int>arr, int k) {
    
    int n=arr.size();
    k=k%n;

    reverse(arr.begin() , arr.begin()+k);
    reverse(arr.begin()+k , arr.begin()+n);
    reverse(arr.begin() , arr.begin()+n);

    return arr;
}

