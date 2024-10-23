Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // calculate sum of nodes at all depths
    void dfs(TreeNode* root, int depth, vector<int> &mp){
        if(!root) return;
        mp[depth]+=root->val;
        dfs(root->left, depth+1, mp);
        dfs(root->right, depth+1, mp);
    }
    // replace values in dfs
    void solve(TreeNode* root, int sib, vector<int> &mp, int depth){
        if(!root) return;
        /* save left and right node values since dfs will 
            change the values of the right and left node */
        int leftsibling = 0, rightsibling = 0;
        if(root->left) leftsibling = root->left->val;
        if(root->right) rightsibling = root->right->val;

        int ans = mp[depth] - root->val - sib;
        // cout<<"root = "<<root->val<<" sum at level = "<<mp[depth]<<" sib = "<<sib<<" ans = "<<ans<<endl;

        // replace value of cur node
        root->val = ans;
        // call for right and left nodes and pass respective siblings.
        solve(root->right, leftsibling, mp, depth+1);
        solve(root->left, rightsibling, mp, depth+1);
 
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> mp (1e5+1, 0);
        // call dfs to calculate sum at each depth
        dfs(root, 0, mp);
        // for(auto i: mp){
        //     cout<<"depth = "<<i.first<<"sum = "<<i.second<<endl;
        // }
        // call dfs to replace values
        solve(root, 0, mp, 0);
        return root;
    }
};
