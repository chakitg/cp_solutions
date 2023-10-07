// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        set<vector<int> >rs;
        sort(num.begin(), num.end());
        int i, j, k;
        int n = num.size();
        for (i = 0; i < n - 2; i++) {
            j = i+1;
            k = n-1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[j];
                    tmp[2] = num[k];
                    rs.insert(tmp);
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
            }
        }
        vector<vector <int> >result (rs.begin(), rs.end());
        return result;
    }
};