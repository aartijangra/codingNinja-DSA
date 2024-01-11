// Problem statement
// Sam is researching on Alpha-Triangles. So, he needs to create them for different integers ‘N’.
// An Alpha-Triangle is represented by the triangular pattern of alphabets in reverse order.
// For every value of ‘N’, help sam to print the corresponding Alpha-Triangle.
// Example:
// Input: ‘N’ = 3
// Output: 
// C
// C B 
// C B A
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1  <= N <= 25
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// C
// C B 
// C B A
// Sample Input 2 :
// 1
// Sample Output 2 :
// A


#include<iostream>
using namespace std;
void alphaTriangle(int n) {
    // Write your code here.
    for(int i=1; i<=n; i++){
        char ch= 'A'+n-1;
        for(int j=1; j<=i; j++){
            cout<<ch<<" ";
            ch--;

        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    alphaTriangle(n);

}
