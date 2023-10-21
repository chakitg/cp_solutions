Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104



  class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>>pq; //max heap to maintain the elements of dp vector in descending order
        pq.push({nums[0], 0}); // as we can not have empty subsequence
        vector<int>dp(n, 0); // dp vector for storing maximum sum that can be achieved till ith element
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++)
        {
            while(!pq.empty()) // find maximum element from dp vector in the range [i-k, i-1]
            {
                auto p = pq.top();
                if(i-p.second>k)
                    pq.pop();
                else
                    break;
            }
            // check if the current element must be first element of subsequence or not
            dp[i] = max(nums[i], nums[i]+pq.top().first); 
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        return ans;
    }
};
