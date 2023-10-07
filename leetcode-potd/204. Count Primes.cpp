Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106



class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int>prime(n+2,0);
        prime[0] = 1;
        prime[1] = 1;
        for(int i = 2 ; i < n ; i++) {
            if(!prime[i]) {
                ++ans;
                for(int j = 2*i ; j < n ; j += i) {
                    prime[j] = 1;
                }
            }
        }
        return ans;
    }
};
