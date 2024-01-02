Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output : 
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2, 2}
Example 2:
Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of the subarray containing at least k numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
-105 <= a[i] <= 105
1 <= k <= n




class Solution {
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int> pre(n, 0);
        pre[0] = a[0];

        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] + a[i];

        long long int sum = pre[k - 1];
        long long int ans = sum;

        for (int i = k; i < n; i++) 
        {
            long long int cur = pre[i] - pre[i - k];
            sum = max(cur, sum + a[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
};
