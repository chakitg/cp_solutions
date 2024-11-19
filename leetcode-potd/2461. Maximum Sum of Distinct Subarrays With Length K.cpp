You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105



class Solution {
public:
    int hash[100100] = {0};
    int duplicate = 0;
    long long sum = 0;

    void add(int x) {
        hash[x]++;
        sum += x;
        if (hash[x] == 2) {
            duplicate++;
        }
    }

    void remove(int x) {
        hash[x]--;
        sum -= x;
        if (hash[x] == 1) {
            duplicate--;
        }
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long mxsum = INT_MIN;

        for (int i = 0; i < k; ++i) {
            add(nums[i]);
        }

        if (!duplicate) {
            mxsum = max(sum, mxsum);
        }

        for (int right = k, left = 0; right < nums.size(); ++right, ++left) {
            add(nums[right]);
            remove(nums[left]);
            if (!duplicate) {
                mxsum = max(sum, mxsum);
            }
        }

        return mxsum == INT_MIN ? 0 : mxsum;
    }
};
