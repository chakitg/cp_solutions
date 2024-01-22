You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104




  class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>cnt(n+1,0);
        for(auto x : nums) {
            cnt[x]++;    
        }
        vector<int>ans;
        int f = -1;
        int s = -1;
        for(int i = 1 ; i <= n ; i++) {
            if(cnt[i] == 0) {
                s = i;
            }
            else if(cnt[i] == 2) {
                f = i;
            }
        }
        ans.push_back(f);ans.push_back(s);
        return ans;
    }
};



____________________________________________________

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1))/2;
        long long sqr_sum = 0;
        for(int i = 1; i <= n; i++) sqr_sum += i * i;

        int arr_sum = 0;
        long long arr_sqr_sum = 0;

        for(int i = 0; i < n; i++){
            arr_sum += nums[i];
            arr_sqr_sum += (nums[i] * nums[i]);
        }

        int sum_diff = arr_sum - sum;
        int sqr_sum_diff = arr_sqr_sum - sqr_sum;

        int missing = (sqr_sum_diff - (sum_diff * sum_diff)) / (2 * sum_diff);
        int duplicate = sum_diff + (missing);
        return {duplicate , missing};
    }
};
