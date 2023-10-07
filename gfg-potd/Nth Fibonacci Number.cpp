Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:

Input: 
n = 2
Output: 
1 
Explanation: 
1 is the 2nd number of fibonacci series.
Example 2:

Input: 
n = 5
Output: 
5
Explanation: 
5 is the 5th number of fibonacci series.
Your Task:  
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1<= n <=105


// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
     long f1=0,f2=1,f3;
        if(n<=1) return n;
        for(int i=2; i<=n; i++){
            f3=(f1+f2)%1000000007;
            f1=f2;
            f2=f3;
        }
        return f3;
    }
};
