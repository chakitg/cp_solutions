// Given a binary tree, find its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input:
//  root  -->     1
//              /   \
//             3     2
//            /
//           4           
// Output: 3
// Explanation:
// Maximum depth is between nodes 1 and 4, which is 3.
// Example 2:

// Input:
//  root -->    10
//            /    \
//           20    30
//            \      \  
//            40     60
//                   /
//                  2 
// Output: 4
// Explanation:
// Maximum depth is between nodes 10 and 2, which is 4
// Your Task:  
// You don't need to read input or print anything. Complete the function maxDepth() which takes the root node as an input parameter and returns the maximum depth.
 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of the tree)
 
// Constraints:
// 1 ≤ N ≤ 10^5




class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(root ==NULL)
        return 0;
        int p=maxDepth(root->left);
        int q=maxDepth(root->right);
        return 1+max(p,q);
    }
};
