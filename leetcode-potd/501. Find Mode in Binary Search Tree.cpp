Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105




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
    void solve(TreeNode* root,unordered_map<int,int> &mapp)
    {
        if(!root)
           return  ;

        solve(root->left,mapp) ;
        mapp[root->val]++ ;
        solve(root->right,mapp) ;
    }
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> mapp ;
        vector<int> ans ;
        int freq = 0 ;

        solve(root,mapp) ;
        
        for(auto it = mapp.begin() ; it != mapp.end() ; it++)
        {
            // cout<<it->first<<" "<<it->second<<endl ;
            if(it->second > freq)
            {
                ans.clear() ;
                ans.push_back(it->first) ;
                freq = it->second ;
            }
            else if(it->second == freq)
                ans.push_back(it->first) ; 
        }
        return ans ;
    }
};
