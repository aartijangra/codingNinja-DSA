// Problem statement
// Given an integer ‘n’, return first n Fibonacci numbers using a generator function.



// Example:
// Input: ‘n’ = 5

// Output: 0 1 1 2 3

// Explanation: First 5 Fibonacci numbers are: 0, 1, 1, 2, and 3.
// Note:
// You don't need to print anything. Just implement the given function.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1:
// 0 1 1 2 3
// Explanation Of Sample Input 1:
// The first 5 Fibonacci numbers are 0, 1, 1, 2, and 3.
// Sample Input 2:
// 3
// Sample Output 2:
// 0 1 1
// Explanation Of Sample Input 2:
// The first 5 Fibonacci numbers are 0, 1, 1.
// Expected time complexity
// The expected time complexity is O(n).
// Constraints:
// 1 <= n <= 45
// Time Limit: 1 s


#include <vector>

std::vector<int> generateFibonacciNumbers(int n) {
    std::vector<int> fibonacciSequence;
    if (n == 0) return fibonacciSequence; // Return empty vector if n is 0

    fibonacciSequence.push_back(0); // First Fibonacci number
    if (n == 1) return fibonacciSequence; // Return vector with only 0 if n is 1

    fibonacciSequence.push_back(1); // Second Fibonacci number
    if (n == 2) return fibonacciSequence; // Return vector with 0 and 1 if n is 2

    // Generate subsequent Fibonacci numbers
    for (int i = 2; i < n; ++i) {
        int nextFibonacci = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
        fibonacciSequence.push_back(nextFibonacci);
    }

    return fibonacciSequence;
}
