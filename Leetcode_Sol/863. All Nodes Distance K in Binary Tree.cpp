Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void dfs(TreeNode* root, TreeNode* parent){
        if(!root) return;
        if(!parent) parent = root;
        else mp[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        set<TreeNode*> st;
        dfs(root,NULL);
        q.push(target);
        int cnt=0;
        vector<int> res;
        while(!q.empty()){
            int sz=q.size();
            if(cnt>k) break;
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node->left!=NULL and !st.count(node->left)){
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right!=NULL and !st.count(node->right)){
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mp.count(node) and !st.count(mp[node])){
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
                st.insert(node);
                if(cnt==k){
                    res.push_back(node->val);
                }
            }
            cnt++;
        }
        return res;
    }
};
