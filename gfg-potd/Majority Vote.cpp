You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1. 

Note: The answer should be returned in an increasing format.

Examples:

Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: nums = [1, 2, 3, 4, 5]
Output: [-1]
Explanation: no candidate occur more than n/3 times.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
1 <= nums.size() <= 106
0 <= nums[i] <= 109





class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        
        vector<int> ans;
        
        int count = 1;
        int n = nums.size();
        if(n < 3) return nums;
        
        sort(nums.begin(),nums.end());
        
        for(int i =1;i<n;i++)
        {
            if(nums[i] == nums[i-1])
            {
                count++;
                if(count > (n/3))
                {
                    ans.push_back(nums[i]);
                    count = 1;
                    
                    while(nums[i] == nums[i-1] && i<n)
                    {
                        i++;
                    }
                }
            }
            else{
                count = 1;
            }
            
        }
        
         if(ans.size() == 0) return {-1};
         
         return ans;
        
    }
};
