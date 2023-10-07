Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false; // Cannot have a 132 pattern with less than 3 elements.
        }

        vector<int> minLeft(n); // Store the minimum element to the left of each element.
        minLeft[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            minLeft[i] = min(minLeft[i - 1], nums[i]);
        }

        stack<int> stk; // Use a stack to store potential '3' candidates (nums[j]).
        
        for (int j = n - 1; j >= 0; --j) {
            if (nums[j] > minLeft[j]) { // We found a potential '3'.
                while (!stk.empty() && stk.top() <= minLeft[j]) {
                    stk.pop(); // Remove elements that can't be '2'.
                }
                if (!stk.empty() && stk.top() < nums[j]) {
                    return true; // We found a '132' pattern.
                }
                stk.push(nums[j]); // Add nums[j] as a potential '2'.
            }
        }

        return false; // No '132' pattern found.
    }
};
