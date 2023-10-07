// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        map <int,int> m1;
        for(int i = 0; i < nums.size(); i++)
        {
            m1[nums[i]]++;
        }
        vector<int> counts = {};
        for(auto it = m1.begin(); it != m1.end(); it++)
        {
            counts.push_back(it->second);
        }
        sort(counts.begin(),counts.end());
        reverse(counts.begin(),counts.end());
        vector<int> ans = {};
        int a = 0;
        while(ans.size() != k)
        {
            for(auto it = m1.begin(); it != m1.end(); it++){
                if(it->second == counts[a] && a < k){
                    ans.push_back(it->first);
                    a++;
                }
            }
        }
        return ans;
    }
};
