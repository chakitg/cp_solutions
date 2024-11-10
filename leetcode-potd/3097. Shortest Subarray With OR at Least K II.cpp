You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // Array to track the count of bits set in each position (0 to 31)
        vector<int> hash(32, 0);  
        
        int l = 0, r = 0;    // Pointers for the sliding window
        int n = nums.size();  // Size of the input array
        int num = 0;          // Current OR of the window
        int ans = INT_MAX;    // Minimum length of subarray with OR >= k

        while (r < n) {
            // Update OR with the current element nums[r]
            num |= nums[r];
            
            // Update bit counts for nums[r]
            for (int i = 0; i < 32; i++) {
                if (nums[r] & (1 << i)) { // Check if the i-th bit is set
                    hash[i]++;
                }
            }
            
            // Once the OR of the window is >= k, try to minimize the window
            while (l <= r && num >= k) {
                // Update the minimum subarray length
                ans = min(ans, r - l + 1);
                
                // Remove nums[l] from the window
                for (int i = 0; i < 32; i++) {
                    if (nums[l] & (1 << i)) { // Check if the i-th bit is set
                        hash[i]--;
                        if (hash[i] == 0) {
                            // If the count of this bit becomes zero, remove it from OR
                            num -= (1 << i);
                        }
                    }
                }
                // Shrink the window from the left
                l++;
            }
            
            // Expand the window by moving the right pointer
            r++;
        }
        
        // If no valid subarray was found, return -1, otherwise return the minimum length
        return (ans == INT_MAX) ? -1 : ans;
    }
};
