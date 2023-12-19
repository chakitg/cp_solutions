Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

Example 1: 

Input: 
M = 11, N = 9
Output: 
2
Explanation: 
Binary representation of the given numbers are: 1011 and 1001, 2nd bit from right is different.
Example 2:

Input: 
M = 52, N = 4
Output: 
5
Explanation: 
Binary representation of the given numbers are: 110100 and 0100, 5th-bit from right is different.
User Task:
The task is to complete the function posOfRightMostDiffBit() which takes two arguments M and N and returns the position of first different bits in M and N from right. If both m and n are the same then return -1 in this case.

Expected Time Complexity: O(max(log M, log N)).
Expected Auxiliary Space: O(1).

Constraints:
0 <= M, N <= 109




class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        
        int count=0;
        if(m==n){
            return -1;
        }
        while(m!=0 || n!=0){
            int d1=m%2;
            int d2=n%2;
            count++;
            if(d1!=d2){
                break;
            }
            m/=2;
            n/=2;
        }
        return count;
    }
};
