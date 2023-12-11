Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105






class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
       int n = nums.size();
       if(n==1)return 1;
       int ans ;
       int quarter = n/4;
       for(int i = 0 ;i < n - quarter;i++)
       {
           if(nums[i] == nums[i+quarter])
           {
               ans = nums[i];
           }
       } 
       return ans;
    }
};
