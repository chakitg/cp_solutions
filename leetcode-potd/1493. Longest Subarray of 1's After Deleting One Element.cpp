// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.






class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int previousCount = 0, currentCount = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) 
              currentCount++;
            else {
                maxCount = max(maxCount, currentCount + previousCount);
                previousCount = currentCount;
                currentCount = 0;
            }
        }
        maxCount = max(maxCount, currentCount + previousCount);
        return maxCount == nums.size() ? maxCount - 1 : maxCount;
    }
};
