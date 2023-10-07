You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

 

Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106



class Solution {
public:
    int n;
    int solve(int mask, vector<int>&a , vector<int>&dp) {
        if(mask == (1 << n)-1) return 0;
        if(dp[mask] != -1) return dp[mask];
        int ans = 0;
        int st = __builtin_popcount(mask)/2;
        st++;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if((((1 << i) & mask) == 0) && ((1 << j) & mask) == 0) {
                    int newMask = mask|(1<<j);
                    newMask |= (1<<i);
                    ans = max(ans,st*(__gcd(a[i],a[j])) + solve(newMask,a,dp));
                }
            }
        }
        return dp[mask] = ans;
    }

    int maxScore(vector<int>& a) {
     n = (int)a.size();
     vector<int>dp((1 << n),-1);
     return solve(0,a,dp);
    }
};
