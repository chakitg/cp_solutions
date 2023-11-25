You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104




class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int total_sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++)total_sum+=nums[i];
        vector<int> ans;
        int curr_sum=0;
        for(int i=0; i<n; i++){
            curr_sum+=nums[i];
            int Rsum=total_sum-curr_sum;
            int Lsum=curr_sum-nums[i];
            Lsum=(i*nums[i])-Lsum;
            Rsum=Rsum-(n-(i+1))*nums[i];
            ans.push_back(Lsum+Rsum);
        }
        return ans;
    }
};
