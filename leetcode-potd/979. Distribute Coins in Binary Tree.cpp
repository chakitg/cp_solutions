You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

 

Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
Example 2:


Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
 

Constraints:

The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node.val is n.





class Solution {
public:
    int needCoins(TreeNode* r, int& steps){
        if(r==nullptr) return 0;
        int c1=needCoins(r->left, steps);
        int c2=needCoins(r->right, steps);
        steps+=(abs(c1)+abs(c2));
        return c1+c2+(r->val-1);
    }

    int distributeCoins(TreeNode* root) {
        int steps=0;
        needCoins(root, steps);
        return steps;
    }
};
