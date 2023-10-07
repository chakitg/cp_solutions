Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10} are 
possible subsets.
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
{2, 3, 5} are possible subsets.
Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0<=arr[I]<=106




class Solution{

	public:
       int mod=1e9+7;
	
	int countSubsets(int arr[], int n, int sum,vector<vector<int>> &dp)
	{
	    if(dp[n][sum]!=-1) return dp[n][sum];
	    if(n==0 and sum>0) return 0;
	    
	    else if(n==1)
	    {
	        if(sum==0)
	        {
	            if(arr[0]==0) 
	                return 2;
	            else 
	                return 1;
	        }
	        else
	        {
	            if(arr[0]==sum) 
	                return 1;
	            else 
	                return 0;
	        }
	    }
	    else if(n==0 and sum==0)
	        return 1;
	        
	    int ans=countSubsets(arr,n-1,sum,dp)%mod;
	    if(arr[n-1]<=sum)
	    {
	        ans+=countSubsets(arr,n-1,sum-arr[n-1],dp);
	        ans%=mod;
	    }
	    return dp[n][sum]=ans;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return countSubsets(arr,n,sum,dp);
	}
	
	  
};
