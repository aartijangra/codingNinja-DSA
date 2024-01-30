// Problem statement
// Determine if a given string ‘S’ is a palindrome using recursion. Return a Boolean value of true if it is a palindrome and false if it is not.

// Note: You are not required to print anything, just implement the function. Example:
// Input: s = "racecar"
// Output: true
// Explanation: "racecar" is a palindrome.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// abbba
// Sample Output 1:
// true
// Explanation Of Sample Input 1 :
// “abbba” is a palindrome
// Sample Input 2:
// abcd
// Sample Output 2:
// false
// Explanation Of Sample Input 2 :
// “abcd” is not a palindrome.
// Constraints:
// 0 <= |S| <= 10^6
// where |S| represents the length of string S.
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string& str, int start, int end) {
    // Write your code here.
    if (start >= end) {
        return true;
    }
    
    // Check if characters at start and end positions are equal
    if (str[start] != str[end]) {
        return false;
    }
    
    // Recursively check the substring by moving start index forward and end index backward
    return isPalindrome(str, start + 1, end - 1);
}
bool isPalindrome(string& str) {
    int start = 0;
    int end = str.length() - 1;
    return isPalindrome(str, start, end);
}
int main(){
     string s1 = "racecar";
    string s2 = "abbba";
    string s3 = "abcd";
    
    cout << boolalpha; // Output true/false instead of 1/0
    cout << isPalindrome(s1) << endl; // Output: true
    cout << isPalindrome(s2) << endl; // Output: true
    cout << isPalindrome(s3) << endl; // Output: false
    
    return 0;
}
