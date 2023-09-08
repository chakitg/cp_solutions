Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 Example 1:

Input:
      1
    /   \
   2     3
Output: 
1 2 3
Explanation:
The converted BST will be 
      2
    /   \
   1     3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 
1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105




class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void inorder(Node* root, vector<int>&v){
        if(root == NULL)return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
    }
    
    void replace(Node* root, vector<int>&v, int &i){
        if(root == NULL)return;
        
        replace(root->left,v,i);
        root->data  = v[i];
        i++;
        replace(root->right,v,i);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        inorder(root,v);
        sort(v.begin(), v.end());
        int i=0;
        replace(root,v,i);
        
        return root;
    }
};
