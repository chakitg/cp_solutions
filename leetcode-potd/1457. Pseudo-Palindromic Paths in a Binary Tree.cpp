Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 9






class Solution {
public:
    // Function to count pseudo-palindromic paths in a binary tree.
    int pseudoPalindromicPaths(TreeNode* root) {

        vector<int> digits(10, 0);
        // Start DFS traversal from the root.
        return dfs(root, digits);
    }

private:
    // Recursive function for DFS traversal.
    int dfs(TreeNode* root, vector<int>& digits) {
        // Base case: If the current node is NULL, return 0.
        if (root == nullptr) return 0;

        // Increment the count of the current digit.
        digits[root->val]++;

        // If the current node is a leaf, check if the path is pseudo-palindromic.
        if (root->left == nullptr && root->right == nullptr) {
            int cnt = countOdd(digits);
            digits[root->val]--;  // Backtrack by decrementing the count.
           
            return (cnt <= 1) ? 1 : 0;
        }

        // Recursively traverse the left and right subtrees.
        int leftCount = dfs(root->left, digits);
        int rightCount = dfs(root->right, digits);

        // Backtrack by decrementing the count of the current digit.
        digits[root->val]--;

        return leftCount + rightCount;
    }

    // Helper function to count the number of digits with odd occurrences.
    int countOdd(const vector<int>& digits) {
        int cnt = 0;
        
        for (int i = 1; i < 10; ++i) {
            if ((digits[i]) & 1) cnt++;
        }
        return cnt;
    }
};
