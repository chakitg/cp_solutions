Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1






class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0; i<=sqrt(c); i++){
            double root = sqrt(c-pow(i,2));
            int intval = static_cast<int>(root);
            if(root == intval)return true;
        }
        return false;
    }
};
