Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Example 1:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10

Example 2:

Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3
Your Task:
You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

Constraints:
1 <= Number of Nodes <= 105
1 <= Node data <= 109



  class Solution {
public:
    vector<int> out;

    bool find(Node* node, int x) {
        if (!node)
            return false;

        if (node->data == x)
            return true;

        if (node->data > x)
            return find(node->left, x);

        return find(node->right, x);
    }

    void inorder(Node* root1, Node* root2) {
        if (!root1)
            return;

        inorder(root1->left, root2);
        if (find(root2, root1->data))
            out.push_back(root1->data);
        inorder(root1->right, root2);
    }

    vector<int> findCommon(Node* root1, Node* root2) {
        inorder(root1, root2);
        return out;
    }
};
