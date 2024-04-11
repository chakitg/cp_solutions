Given an integer number n, which is a decimal representation of Gray Code. Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.

 

Note: Please visit here to learn How Gray Code is generated.

Example 1:

Input: 
n = 4
Output: 
7
Explanation:
Given 4, its gray code =  110.
Binary equivalent of the gray code 110 is 100.
Return 7 representing gray code 100.
Example 2:

Input: 
n = 15
Output: 
10
Explanation:
Given 15 representing gray code 1000.
Binary equivalent of gray code 1000 is 1111.
Return 10 representing gray code 1111 
ie binary 1010.
Your Task: 
You don't need to read input or print anything. Your task is to complete the function grayToBinary() which accepts an integer n as an input parameter and returns decimal representation of the binary equivalent of the given gray code.

Expected Time Complexity: O(log (n)).
Expected Auxiliary Space: O(1).

Constraints:
0 <= n <= 109





class Solution {
public:
    int grayToBinary(int n)
    {
        int ans = 0;
        while(n > 0)
        {
            ans = ans ^ n;
            n = n >> 1;
        }
        return ans;
    }
};
