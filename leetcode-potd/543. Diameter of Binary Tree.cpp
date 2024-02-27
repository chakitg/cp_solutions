Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100



class Solution {
public:
    pair<int,int> solve(TreeNode *root){
        if(root==NULL){
            pair<int,int>temp = make_pair(0,0);
            return temp;
        }

        pair<int,int>left= solve(root->left);
        pair<int,int>right =solve(root->right);

        int op1=left.first;
        int op2=right.first;
        int op3 = left.second +right.second;

        pair<int,int>ans;
        ans.first= max(op1 , max(op2, op3));
        ans.second = max(left.second ,right.second) +1;

        return ans;


    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
        
    }
};
