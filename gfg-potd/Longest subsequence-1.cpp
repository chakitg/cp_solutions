Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

Example 1:

Input:
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
Output: 
3
Explaination: 
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.
Example 2:

Input: 
n = 5
a[] = {1, 2, 3, 4, 5}
Output: 
5
Explaination: 
All the elements can be included in the valid subsequence.
Your Task:
You do not need to read input. Your task is to complete the function longestSubseq() which takes integer n and array a[] as input parameters and returns the length of the longest subsequence where the absolute difference of adjacent elements is 1.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 103
1 ≤ a[i] ≤ 103





class Solution {
  public:
 int longestSubseq(int n, vector<int> &a) {

        unordered_map<int,int>mp;
        int maxi=0,b,c;
        for(auto i:a)
        {
            b=i-1,c=i+1;
            mp[i]=max(mp[b],mp[c])+1;
            maxi=max(maxi,mp[i]);
        }
        return maxi;


    }


};
