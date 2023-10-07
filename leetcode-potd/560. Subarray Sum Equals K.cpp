Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107



class Solution {
public:
    map<int,int>mp;
    int subarraySum(vector<int>& nums, int k) {
     long long sum = 0;
     map<long long , long long>mp;
     int ans = 0;
     int n = (int)nums.size();
     for(int i = 0 ; i < n ; i++) {
        sum += nums[i];
        if(mp.find(sum - k) != mp.end()) {
            long long x = mp[sum-k];
            ans += (x);
        }
        mp[sum]++;
     }
     ans += mp[k];
     return ans;
    }
};
