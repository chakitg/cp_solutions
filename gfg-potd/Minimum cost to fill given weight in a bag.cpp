Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.
Note:
1. cost[i] = -1 means that i kg packet of orange is unavailable.
2. It may be assumed that there is an infinite supply of all available packet types.

Example 1:

Input: 
n = 5
cost[] = {20, 10, 4, 50, 100} 
w = 5
Output: 
14
Explanation: 
Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of oranges for 14 coins.
Example 2:

Input: 
n = 5
cost[] = {-1, -1, 4, 3, -1}
w = 5
Output: 
-1
Explanation: 
It is not possible to buy 5 kgs of oranges.
Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes integers n and w, and integer array cost[] as input parameters and returns the minimum cost to buy exactly w kg of oranges, If buying exactly w kg of oranges is impossible, then return -1.

Expected Time Complexity: O(n*w)
Expected Auxiliary Space: O(n*w)

Constraints:
1 ≤ n, w ≤ 2*102
1 ≤ cost[i] ≤ 105
cost[i] ≠ 0






class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<int> prev(w+1, 1e8);
        vector<int> curr(w+1, 1e8);
        prev[0]=curr[0]=0;
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
            for(int k=0;k<=w;k++)
            {
                int nontake=prev[k];
                int take=1e8;
                if(cost[i-1]!=-1 && i<=k)
                    take=cost[i-1]+curr[k-i];
                curr[k]=min(take, nontake);
            }
            prev=curr;
        }
        return prev[w]==1e8 ? -1 : prev[w];
    }
};
