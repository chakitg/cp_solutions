Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length





  class Solution {
public:

    int K;
    vector<int> store;
    int dp[501];

    int solve(int start)
    {

        if(start>=store.size())
        {
            return 0;
        }

        if(dp[start]!=-1)
        {
            return dp[start];
        }

        int ans = 0;
        int largest = 0;
        for(int i=1; i<=K; i++)
        {
            if(start+i > store.size())
            {
                break;
            }
            largest = max(largest, store[start+i-1]);
            int currAns = largest*i + solve(start+i);
            ans = max(ans, currAns);
        }

        return dp[start] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        K = k;
        store = arr;
        memset(dp, -1, sizeof(dp));

        return solve(0);
    }
};
