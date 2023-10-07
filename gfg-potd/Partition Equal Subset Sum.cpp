Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
N*sum of elements ≤ 5*106



class Solution{
public:
bool solveMem(int index,int arr[],int n,int target,vector<vector<int>> &dp){
    if(index>=n) return 0;
    if(target<0) return 0;
    if(target==0) return 1;
    if(dp[index][target]!=-1) return dp[index][target];
    bool incl = solveMem(index+1,arr,n,target-arr[index],dp);
    bool excl = solveMem(index+1,arr,n,target,dp);
    return dp[index][target] = incl or excl;
}
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total & 1) return 0; //total is odd
        int target = total/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solveMem(0,arr,N,target,dp);
    }
};
