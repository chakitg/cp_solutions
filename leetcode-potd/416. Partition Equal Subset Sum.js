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


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let total = nums.reduce((a, b) => a + b, 0);
    
    if (total % 2 === 1) return false;

    let target = total / 2;

    function dfs(i, cur){
        if (cur === target) return true;

        if (i === nums.length || cur > target) return false;

        return dfs(i + 1, cur + nums[i]) || dfs(i + 1, cur);
    }

    return dfs(0, 0)
};
