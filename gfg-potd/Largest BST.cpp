Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106




struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBSTHelper(Node* root) {
    if (root == nullptr) {
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info leftInfo = largestBSTHelper(root->left);
    Info rightInfo = largestBSTHelper(root->right);

    Info currentInfo;
    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal && root->data < rightInfo.minVal) {
        currentInfo.isBST = true;
        currentInfo.size = 1 + leftInfo.size + rightInfo.size;
        currentInfo.minVal = std::min(root->data, leftInfo.minVal);
        currentInfo.maxVal = std::max(root->data, rightInfo.maxVal);
    } else {
        currentInfo.isBST = false;
        currentInfo.size = std::max(leftInfo.size, rightInfo.size);
        currentInfo.minVal = INT_MAX;
        currentInfo.maxVal = INT_MIN;
    }

    return currentInfo;
}

class Solution {
public:
    int largestBst(Node* root) {
        return largestBSTHelper(root).size;
    }
};
