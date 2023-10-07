// Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

// Example 1:

// Input:
// A = 2, B = 2
// Output: 2
// Explanation: There are only two unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Example 2:

// Input:
// A = 3, B = 4
// Output: 10
// Explanation: There are only 10 unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Your Task:
// Complete NumberOfPath() function which takes 2 arguments(A and B) and returns the number of unique paths from top-left to the bottom-right cell.

// Expected Time Complexity: O(A*B).
// Expected Auxiliary Space: O(A*B).

// Constraints:
// 1 ≤ A ≤ 15
// 1 ≤ B ≤ 15


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
         int64_t p = 1, q = 1;
    for (int i = a; i <= a + b - 2; i++)p *= i, q *= (i - a + 1);
    return p / q;
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}
