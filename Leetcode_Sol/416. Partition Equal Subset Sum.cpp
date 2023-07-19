Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100


class Solution {
public:
    int dp[205][20005];
    
    bool solve(int i , int s , vector<int>&nums) {
        if(i < 0) return 0;
        if(s == 0) return 1;
        if(dp[i][s] != -1) return dp[i][s];
        bool ok = solve(i-1,s,nums);
        if(s - nums[i] >= 0) {
            ok |= solve(i-1,s-nums[i],nums);
        }
        return dp[i][s] = ok;
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        sum /= 2;
        return solve(n-1,sum,nums);
    }
};
