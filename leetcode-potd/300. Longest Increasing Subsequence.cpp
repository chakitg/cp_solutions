Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?




  class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++) {
            ans[i] = 1;
            for(int j = 0 ; j < i ; j++) {
                if(nums[j] < nums[i]) {
                    ans[i] = max(ans[i],ans[j]+1);
                }
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};


_______________________________________________________________

// TC = O(N * log N) - N binary searches of O(log N) each
// SC = O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1; // len = 1 as we pushed nums[0]
        // LOGIC : Create a temp array that adds elements if greater than the last element, and if not, overwrites smallest greater element. NOTE : temp does not store the longest increasing subsequence, we are just utilizing the length of temp to get our answer.
        for(int i=1;i<nums.size();i++){
            if(temp.back() < nums[i]){ // If nums[i] is greater, just add it at the back
                temp.push_back(nums[i]);
                l++;
            }
            else{ // If not, just replace the smallest element greater than nums[i] with nums[i]
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin(); // inbuilt c++ function to perform binary search O(log N) to search for the third parameter in the array or element just greater than it. Do - temp.begin() to get an integer index value
                temp[ind] = nums[i];
            }
        }
        return l;
    }
};
