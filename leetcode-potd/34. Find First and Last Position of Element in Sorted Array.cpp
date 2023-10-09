Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] < target)
                low = low + 1;
            else if (nums[high] > target)
                high = high - 1;
            else if (nums[low] == target && nums[high] == target) {
                v.push_back(low);
                v.push_back(high);
                return {low, high};
            }
        }
        return {-1, -1};
    }
};
