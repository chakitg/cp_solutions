Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

Example1:

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30
Example2:

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ 
     2        1                    4

Your Task:
The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Here N denotes total number of nodes in given BST.

Constraints:
1 <= N <= 105
1 <= Node data <= 109



class Solution {
public:
    vector<int> arr;

    void inorder(Node* node) {
        if (!node)
            return;
        inorder(node->left);
        arr.push_back(node->data);
        inorder(node->right);
    }

    Node* createBST(int low, int high) {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;
        Node* root = new Node(arr[mid]);

        root->left = createBST(low, mid - 1);
        root->right = createBST(mid + 1, high);

        return root;
    }

    Node* buildBalancedTree(Node* root) {
        inorder(root);
        return createBST(0, arr.size() - 1);
    }
};
