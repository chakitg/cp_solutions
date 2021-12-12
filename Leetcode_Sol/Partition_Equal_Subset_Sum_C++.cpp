// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

//--------------------------------------------------------------------------------------------------------

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); //number of objects
        int capacity = accumulate(nums.begin(), nums.end(), 0);
        if((capacity & 1) == 1) return false;
        capacity /= 2;
        
        /*
        the +1 is not padding, it's meaningful!
        i: number of objects in the backpack
        j: current weight of backpack
        dp[i][j]: whether the state: (i, j) exists or not
        our goal is to find out dp[n][capacity]
        */
        vector<vector<bool>> dp(n+1, vector<bool>(capacity+1, false));

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= capacity; j++){
                if(i == 0 && j == 0){
                    //choose nothing, make up weight = 0
                    dp[i][j] = true;
                    continue;
                }else if(j == 0){
                    //make up weight = 0
                    dp[i][j] = true;
                    continue;
                }else if(i == 0){
                    //no object to choose, but need to make up weight j > 0
                    dp[i][j] = false;
                    continue;
                }
                /*
                not choose this object,
                so the weight remains the same(= j)
                */
                dp[i][j] = dp[i-1][j];
                /*
                need to check whether the remaining capacity 
                still allows us to choose object i:
                j >= nums[i] means we still have enough capacity
                
                note that dp[i] corresponds to nums[i-1]!!
                (because the i in dp[i] means number of items!)
                */
                if(j - nums[i-1] >= 0){
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][capacity];
    }
};