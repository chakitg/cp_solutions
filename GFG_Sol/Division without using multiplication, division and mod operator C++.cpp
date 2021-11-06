// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

// Example 1:

// Input:
// a = 10, b= 3
// Output: 3
// Exaplanation:
// 10/3 gives quotient as 3 
// and remainder as 1.
// Example 2:

// Input:
// a = 43, b = -8
// Output: -5
// Explanation:
// 43/-8 gives quotient as -5 and 
// remainder as 3.
// Your task:
// You don't have to read input or print anything. Your task is to complete the function divide() which takes two integers a and b as input and returns the quotient after dividing a by b.
 
// Expected Time Complexity: O(log(a))
// Expected Auxiliary Space: O(1)
 
// Constraints :
// -10^9 <= a,b <= 10^9




//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        int quotient;
        quotient = dividend/divisor;
        return quotient;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends