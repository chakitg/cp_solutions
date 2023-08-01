Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = (int)nums.size();
        for(int i = 0 ; i < (1 << n) ; i++) {
            vector<int>b;
            for(int j = 0 ; j < n ; j++) {
                int x = (1 << j);
                if(i & x) {
                    b.push_back(nums[j]);
                }
            }
            ans.push_back(b);
        }
        return ans;
    }
};
