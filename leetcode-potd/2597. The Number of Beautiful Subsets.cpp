You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
 

Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000




#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totCount = 1;
        unordered_map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int num : nums) {
            int remainder = num % k;
            freqMap[remainder][num]++;
        }

        // Iterate through each remainder group
        for (auto& frPair : freqMap) {
            map<int, int>& fr = frPair.second;
            int n = fr.size();
            int currCount = 1;
            int next1 = 1;
            int next2 = 0;
            vector<pair<int, int>> subsets(fr.begin(), fr.end());

            // Calculate counts for each subset starting from the second last
            for (int i = n - 1; i >= 0; i--) {
                int skip = next1;
                int take = pow(2, subsets[i].second) - 1;

                if (i + 1 < n && subsets[i + 1].first - subsets[i].first == k) {
                    take *= next2;
                } else {
                    take *= next1;
                }

                currCount = skip + take;
                next2 = next1;
                next1 = currCount;
            }

            totCount *= currCount;
        }

        return totCount - 1;
    }
};
