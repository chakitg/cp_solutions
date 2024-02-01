You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

 

Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.
Example 2:

Input: nums = [1,3,3,2,7,3], k = 3
Output: []
Explanation: It is not possible to divide the array satisfying all the conditions.
 

Constraints:

n == nums.length
1 <= n <= 105
n is a multiple of 3.
1 <= nums[i] <= 105
1 <= k <= 105






class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        int l = nums.size();
        if (l % 3 != 0) {
            return std::vector<std::vector<int>>();
        }

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result(l / 3, std::vector<int>(3, 0));
        int c = 0;

        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (c < l - 1 && (c + 3) % 3 == 0 && nums[c + 2] - nums[c] > k) {
                    return std::vector<std::vector<int>>();
                }
                result[i][j] = nums[c++];
            }
        }

        return result;
    }
};
