// Problem statement
// You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.

// Note:

// 1) The number of rows should be at least 1.

// 2) The number of columns should be at least 1.

// 3) For example, refer to the below matrix illustration: 

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 100
// 1 <= M <= 100
// -10^9 <= MATRIX[i][j] <= 10^9

// Where 'MATRIX[i][j]' denotes the matrix element.
// Follow Up:

// Can you solve it with the space complexity of O(1)?

// Time limit: 1 sec


// Sample Input 1:
// 2 3
// 2 4 3
// 1 0 0
// Sample Output 1:
// 2 0 0 
// 0 0 0 
// Sample Input 2:
// 1 1 
// 5
// Sample Output 2:
// 5 


// Hints:
// 1. Think about how to identify the rows and columns containing a '0' element and then modify the matrix accordingly to make all elements in those rows and columns equal to 0.
// 2. You can use the first row and first column of the matrix itself as indicators to mark whether a particular row or column needs to be zeroed


//better approach
#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int row[n] = {0};
	int col[m] = {0};

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i=0; i<n; i++){
            for (int j = 0; j < m; j++) {
				if(row[i] || col[j]){
					matrix[i][j] = 0;
				}
            }
    }

	return matrix;
}

//optimal approach
#include <bits/stdc++.h>
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
  // Write your code here.
  // int row[n] = {0};  -> matrix[..][0]
  // int col[m] = {0};   -> matrix[0][..]
  int col0 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        // row[i] = 1;
        matrix[i][0] = 0;
        // col[j] = 1;
        if (j != 0) {
          matrix[0][j] = 0;
        } else {
          col0 = 0;
        }
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
		if(matrix[i][j] != 0){
			if(matrix[i][0] == 0 || matrix[0][j] == 0){
				matrix[i][j] = 0;
			}
		}
    }
  }

  if(matrix[0][0] == 0){
	  for(int j = 0; j < m; j++) matrix[0][j] = 0;
  }

  if(col0 == 0){
	  for(int i = 0; i < n; i++) matrix[i][0] = 0;
  }

  return matrix;
}
