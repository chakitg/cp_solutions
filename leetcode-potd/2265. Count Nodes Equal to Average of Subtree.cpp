Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 

Example 1:


Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
Example 2:


Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int count = 0;  // Initialize a variable to count valid subtrees.

  // A helper function to calculate the sum and count of valid subtrees.
  pair<int, int> solve(TreeNode* root) {
      // If the node is null, return 0 for both sum and count.
    if (root == nullptr) return {0, 0};  
    int subtreeSum = root->val;  // Initialize the sum with the current node's value.
    int subtreeNodeCount = 1;    // Initialize the node count with 1 for the current node.

    // Recursively calculate the sum and node count for the left and right subtrees.
    pair<int, int> leftSubtree = solve(root->left);
    pair<int, int> rightSubtree = solve(root->right);

    // Update the sum and node count with values from left and right subtrees.
    subtreeSum += leftSubtree.first + rightSubtree.first;
    subtreeNodeCount += leftSubtree.second + rightSubtree.second;

    // Check if the current node satisfies the condition (value is equal to the average).
    if (root->val == (subtreeSum / subtreeNodeCount)) {
      count++;  // Increment the count if the condition is met.
    }

    return {subtreeSum, subtreeNodeCount};
  }

  int averageOfSubtree(TreeNode* root) {
    pair<int, int> result = solve(root);  // Calculate the sum and count.
    return count;  // Return the count of valid subtrees.
  }
};
