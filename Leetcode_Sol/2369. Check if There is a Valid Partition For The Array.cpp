You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

 

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.
Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= 106



class Solution {
public:
int dp[100005];
int solve(int j,vector<int>&nums){
    if(j==nums.size()){
        return 1;
    }
    if(dp[j]!=-1)
    return dp[j];
    int c=0;
       if(j+1<nums.size()){
           if(nums[j]==nums[j+1])
             c=c|solve(j+2,nums);
       }
       if(j+2<nums.size()){
           if(nums[j]==nums[j+1]&&nums[j]==nums[j+2]){
               c=c|solve(j+3,nums);
           }
           if(nums[j]+1==nums[j+1]&&nums[j+1]+1==nums[j+2]){
                c=c|solve(j+3,nums);
           }
       }
       return dp[j]= c;
}
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
