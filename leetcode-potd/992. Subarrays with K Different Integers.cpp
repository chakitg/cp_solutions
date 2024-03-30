Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length





#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0, result = 0;
        
        while (right < n) {
            if (freq[nums[right]] == 0)
                count++;
            freq[nums[right]]++;
            
            while (count > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    count--;
                left++;
            }
            
            // At this point, the window [left, right] has at most k distinct integers.
            // So, all subarrays ending at index 'right' with at most k distinct integers are valid.
            result += right - left + 1;
            
            right++;
        }
        
        return result;
    }
};
