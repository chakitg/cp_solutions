Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.
Since the answer may be very large, compute it modulo 109+7.

Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 
2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 
8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
Your Task:  
You don't need to read input or print anything. Complete the function sumK() which takes root node and integer K as input parameters and returns the number of paths that have sum K. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)

Constraints:
1 ≤ N ≤ 2*104
-105 ≤ Node Value ≤ 105
-109 ≤ K ≤ 109




class Solution {
public:
    int traversal(Node *root, unordered_map<int, int>& mp, int& k, int sum) {
        if (!root) return 0;
        
        int res = 0;
        int currSum = sum + root->data;
        
        if (mp.find(currSum - k) != mp.end()) 
            res += mp[currSum - k];
            
        mp[currSum]++;
        
        res += traversal(root->left, mp, k, currSum);
        res += traversal(root->right, mp, k, currSum);
        
        mp[currSum]--;
        return res;
    }

    int sumK(Node *root, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        return traversal(root, mp, k, 0);
    }
};
