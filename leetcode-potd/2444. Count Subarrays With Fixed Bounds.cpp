You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106




class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMin = -1, lastMax = -1, left = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            // If the current number is outside the [minK, maxK] range, reset the left pointer
            if (nums[right] < minK || nums[right] > maxK) {
                left = right + 1;
            }
            
            // Update the last seen positions for minK and maxK
            if (nums[right] == minK) {
                lastMin = right;
            }
            if (nums[right] == maxK) {
                lastMax = right;
            }
            
            // If both minK and maxK are seen in the current window, update the count
            if (lastMin >= left && lastMax >= left) {
                count += min(lastMin, lastMax) - left + 1;
            }
        }

        return count;
    }
};
