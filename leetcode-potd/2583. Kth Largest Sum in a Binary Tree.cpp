You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n



class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans; // to store the level sum
        queue<TreeNode*>q; // for level order traversal
        q.push(root);
        while(!q.empty()){
            long long size = q.size(),sum = 0;
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum += (long long)temp->val;
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end()); // sorting the ans vector
        int n = ans.size();
        return (n >= k)?ans[n-k] : -1; // returning the result
    }
};
